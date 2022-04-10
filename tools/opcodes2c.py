import sys
import json

def argument_as_c_enum(argument):
    if "Register" in argument:
        return "ARGUMENT_TYPE_REGISTER"
    argument_mappings = {
        "Immediate": "ARGUMENT_TYPE_IMMEDIATE",
        "Address": "ARGUMENT_TYPE_ADDRESS",
    }
    return argument_mappings[argument]

def main():
    if len(sys.argv) != 3:
        sys.stderr.write(f"Usage: {sys.argv[0]} <input file> <output file>\n")
        exit(1)

    input_filename = sys.argv[1]
    output_filename = sys.argv[2]

    try:
        with open(input_filename, 'r') as in_file:
            data = json.load(in_file)
            try:
                num_opcodes = len(data["opcodes"])
                with open(output_filename, 'w') as out_file:
                    out_file.write("""// auto-generated with opcodes2c.py

#include "opcodes.h"
#include "string_view.h"

OpcodeList opcode_specifications() {\n""")
                    out_file.write(f"    size_t const num_opcodes = {num_opcodes};\n")
                    out_file.write("    OpcodeSpecification* specifications = malloc(num_opcodes * sizeof(*specifications));\n")
                    for i, opcode in enumerate(data["opcodes"]):
                        argument_count = len(data["opcodes"][opcode]["arguments"])
                        out_file.write(f"    specifications[{i}] = (OpcodeSpecification){{\n")
                        out_file.write(f"        .name = string_view_from_string(\"{opcode}\"),\n")
                        out_file.write(f"        .mnemonic = opcode_to_mnemonic(string_view_from_string(\"{opcode}\")),\n")
                        out_file.write(f"        .argument_count = {argument_count},\n")
                        out_file.write(f"        .required_arguments = {{ ")
                        arguments = list(map(lambda argument : argument_as_c_enum(argument), data["opcodes"][opcode]["arguments"]))
                        out_file.write("ARGUMENT_TYPE_NONE" if len(arguments) == 0 else ', '.join(arguments))
                        out_file.write(f" }},\n")
                        opcode = data["opcodes"][opcode]["opcode"]
                        out_file.write(f"        .opcode = {hex(opcode)},\n")
                        out_file.write(f"    }};\n")
                    out_file.write("""    return (OpcodeList){
        .specifications = specifications,
        .num_specifications = num_opcodes,
    };
}""")
            except KeyError:
                sys.stderr.write("Error reading JSON file: An expected key could not be found.\n")
    except IOError:
        sys.stderr.write(f"IO error. Make sure the input file exists and can be opened.\n")


if __name__ == "__main__":
    main()
