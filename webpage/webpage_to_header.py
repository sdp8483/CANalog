#!/usr/bin/python

import os

# set directories
working_dir = os.getcwd()
web_dir = working_dir.replace("webpage", "firmware/esp_CANalog_interface/lib/webpage")

# Get all html, js, css files in CANalog/webpage directory
files_to_convert = []
for file in os.listdir():
    if (file.endswith(".html") | (file.endswith(".js")) | (file.endswith(".css"))):
        print(file)
        files_to_convert.append(file)

for f in files_to_convert:
    print(f)
    
    header_fname = "{}.h".format(f)
    header_path = os.path.join(web_dir, header_fname)

    hdefine = "INC_{}_".format(header_fname.replace(".", "_").upper())
    pdefine = "PAGE_{}_{}".format(f.split(".")[0].lower(), f.split(".")[-1].upper())

    with open(header_path, 'w') as header, open(f, 'r') as html:
        header.write("#ifndef {}\n".format(hdefine))
        header.write("#define {}\n\n".format(hdefine))
        header.write("#include <Arduino.h>\n\n")
        header.write('const char {}[] PROGMEM = R"=====(\n'.format(pdefine))
        header.write(html.read())
        header.write(')=====";\n')
        header.write("#endif")