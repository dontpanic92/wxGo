"""
Change all top-level enums in wxWidgets header into #define.
This makes SWIG could handle the situation below:

```
enum {
  wxHorizontal  
};
 
#define wxRA_HORIZONTAL wxHorizontal
```

SWIG will not treat wxRA_HORIZONTAL as a constant then ignore it.
Fortunately wxWidgets interface is simple -- we only use regular
expressions to deal with these tricks. Perhaps someday we will 
need a real parser.

By dontpanic, 2015/5/16
"""

import sys, os, re

regex = re.compile("enum\s+(.+?){(.+?)}.*?;", re.S) 
regex2 = re.compile("class\s+(\w+?)\s*(:.+?)?{.*?}.*?;", re.S) 

def is_top_level(match_object):
    right = 0
    for i in reversed(range(match_object.start())):
        if match_object.string[i] == '{':
            right -= 1
            if right < 0:
                return False
        elif match_object.string[i] == '}':
            right += 1
    return True
    
def replace_enum(match_object):
    enum_name = match_object.group(1).strip()
    if (len(enum_name.split()) > 1):
        return match_object.group(0)
        
    if not is_top_level(match_object):
        return match_object.group(0)
    code = ""
    
    if enum_name != "":
        code += "%ignore " +  enum_name + ";\nenum " + enum_name + ";\n"
    
    enum_items = match_object.group(2).split(',')
    last_item = ""
    for item in enum_items:
        item = item.strip()
        key_value_pair = item.split('=')
        if key_value_pair[0].strip() == "":
            continue
        
        if len(key_value_pair) == 1:
            if last_item == "":
                key_value_pair.append("0")
            else:
                key_value_pair.append("%s + 1" % last_item)
        else:
            key_value_pair[1] = key_value_pair[1].strip().replace('\n', "")
            
        code += "#define %s %s\n" % tuple(key_value_pair)
        last_item = key_value_pair[0]
        
    return code

def gen_conv_decl(code):
    exception_list = ["wxGoApp", "wxScrolled", "wxString"]
    decl = ""
    for match_object in regex2.finditer(code):
        if not is_top_level:
            continue
        classname = match_object.group(1).strip()
        if classname in exception_list:
            continue
        conv_name = classname[2:] if classname.startswith("wx") else classname
        decl += "WXGO_DECL_TYPECONV(" + conv_name + ")\n"
    return decl

def preprocess(ori_file, new_file):
    print "Processing " + ori_file
    os.system('sed -nf remccoms3.sed ' + ori_file + ' > ' + new_file)
    code = file(new_file).read()
    
    if len(code) == 0:
        return
    code = regex.sub(replace_enum, code)
    conv_decl = gen_conv_decl(code)
    code = os.linesep.join([s for s in code.splitlines() if s.rstrip()])
    file(new_file, "w").write(conv_decl + code) 
     
def preprocess_all(ori_folder, new_folder):
    for f in os.listdir(ori_folder):
        ori_path = os.path.join(ori_folder, f)
        new_path = os.path.join(new_folder, f)
        if os.path.isfile(ori_path):
            preprocess(ori_path, new_path)
        else:
            os.mkdir(new_path)
            preprocess_all(ori_path, new_path)

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print "Usage: python2 preprocess.py OriginalFolderPath NewFolderPath"
    else:
        os.mkdir(sys.argv[2])
        preprocess_all(sys.argv[1], sys.argv[2])