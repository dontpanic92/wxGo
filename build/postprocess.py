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

def postprocess(filename):
    print "Postprocessing", filename
    code = file(filename).read()
    code = regex.sub(replace_hex, code)
    file(filename, "w").write(code)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print "Usage: python2 preprocess.py wx.go"
    else:
        postprocess(sys.argv[1])
