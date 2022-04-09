// auto-generated with opcodes2c.py

#include "opcodes.h"

OpcodeList opcode_specifications() {
    size_t const num_opcodes = 60;
    OpcodeSpecification* specifications = malloc(num_opcodes * sizeof(*specifications));
    specifications[0] = (OpcodeSpecification){
        .name = "RightShiftTargetLhsRhs",
        .mnemonic = opcode_to_mnemonic("RightShiftTargetLhsRhs"),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x11,
    };
    specifications[1] = (OpcodeSpecification){
        .name = "OrTargetLhsRhs",
        .mnemonic = opcode_to_mnemonic("OrTargetLhsRhs"),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0xd,
    };
    specifications[2] = (OpcodeSpecification){
        .name = "JumpRegisterIfLessThanOrEqual",
        .mnemonic = opcode_to_mnemonic("JumpRegisterIfLessThanOrEqual"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_POINTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x2a,
    };
    specifications[3] = (OpcodeSpecification){
        .name = "MoveRegisterAddress",
        .mnemonic = opcode_to_mnemonic("MoveRegisterAddress"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x1,
    };
    specifications[4] = (OpcodeSpecification){
        .name = "MoveTargetSource",
        .mnemonic = opcode_to_mnemonic("MoveTargetSource"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x2,
    };
    specifications[5] = (OpcodeSpecification){
        .name = "SubtractTargetLhsRhs",
        .mnemonic = opcode_to_mnemonic("SubtractTargetLhsRhs"),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x8,
    };
    specifications[6] = (OpcodeSpecification){
        .name = "XorTargetLhsRhs",
        .mnemonic = opcode_to_mnemonic("XorTargetLhsRhs"),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0xe,
    };
    specifications[7] = (OpcodeSpecification){
        .name = "DumpRegisters",
        .mnemonic = opcode_to_mnemonic("DumpRegisters"),
        .argument_count = 0,
        .required_arguments = { ARGUMENT_TYPE_NONE },
        .opcode = 0xffff,
    };
    specifications[8] = (OpcodeSpecification){
        .name = "DivmodTargetModLhsRhs",
        .mnemonic = opcode_to_mnemonic("DivmodTargetModLhsRhs"),
        .argument_count = 4,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0xb,
    };
    specifications[9] = (OpcodeSpecification){
        .name = "JumpRegisterIfGreaterThan",
        .mnemonic = opcode_to_mnemonic("JumpRegisterIfGreaterThan"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_POINTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x27,
    };
    specifications[10] = (OpcodeSpecification){
        .name = "JumpRegister",
        .mnemonic = opcode_to_mnemonic("JumpRegister"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_REGISTER },
        .opcode = 0x1a,
    };
    specifications[11] = (OpcodeSpecification){
        .name = "CallPointer",
        .mnemonic = opcode_to_mnemonic("CallPointer"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_POINTER },
        .opcode = 0x37,
    };
    specifications[12] = (OpcodeSpecification){
        .name = "JumpAddress",
        .mnemonic = opcode_to_mnemonic("JumpAddress"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x19,
    };
    specifications[13] = (OpcodeSpecification){
        .name = "JumpAddressIfNotCarry",
        .mnemonic = opcode_to_mnemonic("JumpAddressIfNotCarry"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x23,
    };
    specifications[14] = (OpcodeSpecification){
        .name = "AddTargetSourceImmediate",
        .mnemonic = opcode_to_mnemonic("AddTargetSourceImmediate"),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x12,
    };
    specifications[15] = (OpcodeSpecification){
        .name = "JumpRegisterIfGreaterThanOrEqual",
        .mnemonic = opcode_to_mnemonic("JumpRegisterIfGreaterThanOrEqual"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_POINTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x29,
    };
    specifications[16] = (OpcodeSpecification){
        .name = "AddTargetLhsRhs",
        .mnemonic = opcode_to_mnemonic("AddTargetLhsRhs"),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x7,
    };
    specifications[17] = (OpcodeSpecification){
        .name = "JumpAddressIfNotZero",
        .mnemonic = opcode_to_mnemonic("JumpAddressIfNotZero"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x21,
    };
    specifications[18] = (OpcodeSpecification){
        .name = "MoveAddressRegister",
        .mnemonic = opcode_to_mnemonic("MoveAddressRegister"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x3,
    };
    specifications[19] = (OpcodeSpecification){
        .name = "MultiplyHighLowLhsRhs",
        .mnemonic = opcode_to_mnemonic("MultiplyHighLowLhsRhs"),
        .argument_count = 4,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0xa,
    };
    specifications[20] = (OpcodeSpecification){
        .name = "MoveTargetPointer",
        .mnemonic = opcode_to_mnemonic("MoveTargetPointer"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_POINTER },
        .opcode = 0x4,
    };
    specifications[21] = (OpcodeSpecification){
        .name = "JumpAddressIfNotDivideByZero",
        .mnemonic = opcode_to_mnemonic("JumpAddressIfNotDivideByZero"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x25,
    };
    specifications[22] = (OpcodeSpecification){
        .name = "JumpAddressIfGreaterThan",
        .mnemonic = opcode_to_mnemonic("JumpAddressIfGreaterThan"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x1c,
    };
    specifications[23] = (OpcodeSpecification){
        .name = "JumpRegisterIfNotCarry",
        .mnemonic = opcode_to_mnemonic("JumpRegisterIfNotCarry"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_POINTER },
        .opcode = 0x2e,
    };
    specifications[24] = (OpcodeSpecification){
        .name = "MoveRegisterImmediate",
        .mnemonic = opcode_to_mnemonic("MoveRegisterImmediate"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x0,
    };
    specifications[25] = (OpcodeSpecification){
        .name = "PopRegister",
        .mnemonic = opcode_to_mnemonic("PopRegister"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_REGISTER },
        .opcode = 0x16,
    };
    specifications[26] = (OpcodeSpecification){
        .name = "DumpMemory",
        .mnemonic = opcode_to_mnemonic("DumpMemory"),
        .argument_count = 0,
        .required_arguments = { ARGUMENT_TYPE_NONE },
        .opcode = 0xfffe,
    };
    specifications[27] = (OpcodeSpecification){
        .name = "CallAddress",
        .mnemonic = opcode_to_mnemonic("CallAddress"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x17,
    };
    specifications[28] = (OpcodeSpecification){
        .name = "JumpAddressIfGreaterThanOrEqual",
        .mnemonic = opcode_to_mnemonic("JumpAddressIfGreaterThanOrEqual"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x1e,
    };
    specifications[29] = (OpcodeSpecification){
        .name = "JumpAddressIfLessThan",
        .mnemonic = opcode_to_mnemonic("JumpAddressIfLessThan"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x1d,
    };
    specifications[30] = (OpcodeSpecification){
        .name = "JumpAddressIfDivideByZero",
        .mnemonic = opcode_to_mnemonic("JumpAddressIfDivideByZero"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x24,
    };
    specifications[31] = (OpcodeSpecification){
        .name = "JumpRegisterIfZero",
        .mnemonic = opcode_to_mnemonic("JumpRegisterIfZero"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_POINTER },
        .opcode = 0x2b,
    };
    specifications[32] = (OpcodeSpecification){
        .name = "JumpRegisterIfDivideByZero",
        .mnemonic = opcode_to_mnemonic("JumpRegisterIfDivideByZero"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_POINTER },
        .opcode = 0x2f,
    };
    specifications[33] = (OpcodeSpecification){
        .name = "SwapFramebuffers",
        .mnemonic = opcode_to_mnemonic("SwapFramebuffers"),
        .argument_count = 0,
        .required_arguments = { ARGUMENT_TYPE_NONE },
        .opcode = 0x35,
    };
    specifications[34] = (OpcodeSpecification){
        .name = "InvisibleFramebufferAddress",
        .mnemonic = opcode_to_mnemonic("InvisibleFramebufferAddress"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_REGISTER },
        .opcode = 0x38,
    };
    specifications[35] = (OpcodeSpecification){
        .name = "PollCycleCountHighLow",
        .mnemonic = opcode_to_mnemonic("PollCycleCountHighLow"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x39,
    };
    specifications[36] = (OpcodeSpecification){
        .name = "SubtractWithCarryTargetLhsRhs",
        .mnemonic = opcode_to_mnemonic("SubtractWithCarryTargetLhsRhs"),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x9,
    };
    specifications[37] = (OpcodeSpecification){
        .name = "JumpRegisterIfLessThan",
        .mnemonic = opcode_to_mnemonic("JumpRegisterIfLessThan"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_POINTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x28,
    };
    specifications[38] = (OpcodeSpecification){
        .name = "PollTime",
        .mnemonic = opcode_to_mnemonic("PollTime"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x33,
    };
    specifications[39] = (OpcodeSpecification){
        .name = "CallRegister",
        .mnemonic = opcode_to_mnemonic("CallRegister"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_REGISTER },
        .opcode = 0x36,
    };
    specifications[40] = (OpcodeSpecification){
        .name = "AddWithCarryTargetLhsRhs",
        .mnemonic = opcode_to_mnemonic("AddWithCarryTargetLhsRhs"),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x34,
    };
    specifications[41] = (OpcodeSpecification){
        .name = "CompareTargetLhsRhs",
        .mnemonic = opcode_to_mnemonic("CompareTargetLhsRhs"),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x14,
    };
    specifications[42] = (OpcodeSpecification){
        .name = "AndTargetLhsRhs",
        .mnemonic = opcode_to_mnemonic("AndTargetLhsRhs"),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0xc,
    };
    specifications[43] = (OpcodeSpecification){
        .name = "JumpAddressIfLessThanOrEqual",
        .mnemonic = opcode_to_mnemonic("JumpAddressIfLessThanOrEqual"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x1f,
    };
    specifications[44] = (OpcodeSpecification){
        .name = "MovePointerSource",
        .mnemonic = opcode_to_mnemonic("MovePointerSource"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_POINTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x5,
    };
    specifications[45] = (OpcodeSpecification){
        .name = "JumpRegisterIfEqual",
        .mnemonic = opcode_to_mnemonic("JumpRegisterIfEqual"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_POINTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x26,
    };
    specifications[46] = (OpcodeSpecification){
        .name = "JumpRegisterIfNotDivideByZero",
        .mnemonic = opcode_to_mnemonic("JumpRegisterIfNotDivideByZero"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_POINTER },
        .opcode = 0x30,
    };
    specifications[47] = (OpcodeSpecification){
        .name = "LeftShiftTargetLhsRhs",
        .mnemonic = opcode_to_mnemonic("LeftShiftTargetLhsRhs"),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x10,
    };
    specifications[48] = (OpcodeSpecification){
        .name = "JumpRegisterIfCarry",
        .mnemonic = opcode_to_mnemonic("JumpRegisterIfCarry"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_POINTER },
        .opcode = 0x2d,
    };
    specifications[49] = (OpcodeSpecification){
        .name = "PushRegister",
        .mnemonic = opcode_to_mnemonic("PushRegister"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_REGISTER },
        .opcode = 0x15,
    };
    specifications[50] = (OpcodeSpecification){
        .name = "JumpAddressIfEqual",
        .mnemonic = opcode_to_mnemonic("JumpAddressIfEqual"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x1b,
    };
    specifications[51] = (OpcodeSpecification){
        .name = "GetKeyState",
        .mnemonic = opcode_to_mnemonic("GetKeyState"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x32,
    };
    specifications[52] = (OpcodeSpecification){
        .name = "SubtractTargetSourceImmediate",
        .mnemonic = opcode_to_mnemonic("SubtractTargetSourceImmediate"),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x13,
    };
    specifications[53] = (OpcodeSpecification){
        .name = "JumpAddressIfCarry",
        .mnemonic = opcode_to_mnemonic("JumpAddressIfCarry"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x22,
    };
    specifications[54] = (OpcodeSpecification){
        .name = "NoOp",
        .mnemonic = opcode_to_mnemonic("NoOp"),
        .argument_count = 0,
        .required_arguments = { ARGUMENT_TYPE_NONE },
        .opcode = 0x31,
    };
    specifications[55] = (OpcodeSpecification){
        .name = "JumpRegisterIfNotZero",
        .mnemonic = opcode_to_mnemonic("JumpRegisterIfNotZero"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_POINTER },
        .opcode = 0x2c,
    };
    specifications[56] = (OpcodeSpecification){
        .name = "Return",
        .mnemonic = opcode_to_mnemonic("Return"),
        .argument_count = 0,
        .required_arguments = { ARGUMENT_TYPE_NONE },
        .opcode = 0x18,
    };
    specifications[57] = (OpcodeSpecification){
        .name = "NotTargetSource",
        .mnemonic = opcode_to_mnemonic("NotTargetSource"),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0xf,
    };
    specifications[58] = (OpcodeSpecification){
        .name = "JumpAddressIfZero",
        .mnemonic = opcode_to_mnemonic("JumpAddressIfZero"),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x20,
    };
    specifications[59] = (OpcodeSpecification){
        .name = "HaltAndCatchFire",
        .mnemonic = opcode_to_mnemonic("HaltAndCatchFire"),
        .argument_count = 0,
        .required_arguments = { ARGUMENT_TYPE_NONE },
        .opcode = 0x6,
    };
    return (OpcodeList){
        .specifications = specifications,
        .num_specifications = num_opcodes,
    };
}