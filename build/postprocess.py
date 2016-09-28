"""
`#define` defined constant will be a constant of type int in go.
That is, for `#define X 0xFFFFFFFF` the go code will be 
```
const X int = 0xFFFFFFFF
```  
which will cause a compilation error. We need to change them into
a negative number. It is not elegant but works.

By dontpanic, 2015/5/27
"""

import sys, os, re

regex = re.compile("^const (.+?) int = (.+?)$", re.MULTILINE) 
regex_ctor = re.compile("^func New(.+?)\((.+?)\).+? {$", re.MULTILINE)

def calc_new_value(var_value):
    values = var_value.split('+')
    new_value = 0
    for value in values:
        new_value += int(value, 0)
    
    return new_value

def replace_hex(match_object):
    var_name = match_object.group(1).strip()
    var_value = match_object.group(2).strip()
    
    code = ""
    new_value = calc_new_value(var_value)
    if new_value > 0x7FFFFFFF:
        new_value = new_value - 0xFFFFFFFF - 1
        print "Found const", var_name, "change it from", var_value, "to", new_value
        return "const " + var_name + " int = " + str(new_value)
    else:
        return match_object.group(0)

def add_tracked_type(code):
    exceptions = ["DirectorGoCallbackDispatcher"]

    for match_object in regex_ctor.finditer(code):
        type_name = match_object.group(1)
        ctor_param = match_object.group(2)
        if "__SWIG_" in type_name or type_name in exceptions:
            continue
        
        ctor_args = ""
        if ctor_param == "a ...interface{}":
            ctor_args = "a..."
        elif ctor_param != "":
            ctor_param_list = ctor_param.split(',')
            ctor_args_num = len(ctor_param_list)
            ctor_args = ", ".join([x.strip().split(" ")[0] for x in ctor_param_list])
        

        code += "\ntype %sT struct {\n" % type_name
        code += "    Swigcptr%s\n}\n\n" % type_name
        code += "func _wxgo_%sTFinalizer(obj *%sT) {\n" % (type_name, type_name)
        code += "    Delete%s(obj)\n" % type_name
        code += "}\n\n"
        code += "func New%sT(%s) %s {\n" % (type_name, ctor_param, type_name)
        code += "    ret := &%sT{}\n" % type_name
        code += "    ret.Swigcptr%s = Swigcptr%s(New%s(%s).Swigcptr())\n" % (type_name, type_name, type_name, ctor_args)
        code += "    runtime.SetFinalizer(ret, _wxgo_%sTFinalizer)\n" % type_name
        code += "    return ret\n"
        code += "}\n"

    return code

def postprocess(filename):
    print "Postprocessing", filename
    code = file(filename).read()
    code = regex.sub(replace_hex, code)
    code = add_tracked_type(code)
    file(filename, "w").write(code)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print "Usage: python2 preprocess.py wx.go"
    else:
        postprocess(sys.argv[1])
