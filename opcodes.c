// auto-generated with opcodes2c.py

#include "opcodes.h"
#include "string_view.h"

OpcodeList opcode_specifications(void) {
    size_t const num_opcodes = 60;
    OpcodeSpecification* specifications = malloc(num_opcodes * sizeof(*specifications));
    specifications[0] = (OpcodeSpecification){
        .name = string_view_from_string("PopRegister"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("PopRegister")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_REGISTER },
        .opcode = 0x16,
    };
    specifications[1] = (OpcodeSpecification){
        .name = string_view_from_string("JumpRegisterIfNotDivideByZero"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpRegisterIfNotDivideByZero")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_POINTER },
        .opcode = 0x30,
    };
    specifications[2] = (OpcodeSpecification){
        .name = string_view_from_string("CallPointer"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("CallPointer")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_POINTER },
        .opcode = 0x37,
    };
    specifications[3] = (OpcodeSpecification){
        .name = string_view_from_string("OrTargetLhsRhs"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("OrTargetLhsRhs")),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0xd,
    };
    specifications[4] = (OpcodeSpecification){
        .name = string_view_from_string("JumpRegisterIfEqual"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpRegisterIfEqual")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_POINTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x26,
    };
    specifications[5] = (OpcodeSpecification){
        .name = string_view_from_string("RightShiftTargetLhsRhs"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("RightShiftTargetLhsRhs")),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x11,
    };
    specifications[6] = (OpcodeSpecification){
        .name = string_view_from_string("PollCycleCountHighLow"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("PollCycleCountHighLow")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x39,
    };
    specifications[7] = (OpcodeSpecification){
        .name = string_view_from_string("Return"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("Return")),
        .argument_count = 0,
        .required_arguments = { ARGUMENT_TYPE_NONE },
        .opcode = 0x18,
    };
    specifications[8] = (OpcodeSpecification){
        .name = string_view_from_string("XorTargetLhsRhs"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("XorTargetLhsRhs")),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0xe,
    };
    specifications[9] = (OpcodeSpecification){
        .name = string_view_from_string("CallRegister"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("CallRegister")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_REGISTER },
        .opcode = 0x36,
    };
    specifications[10] = (OpcodeSpecification){
        .name = string_view_from_string("LeftShiftTargetLhsRhs"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("LeftShiftTargetLhsRhs")),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x10,
    };
    specifications[11] = (OpcodeSpecification){
        .name = string_view_from_string("MoveTargetPointer"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("MoveTargetPointer")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_POINTER },
        .opcode = 0x4,
    };
    specifications[12] = (OpcodeSpecification){
        .name = string_view_from_string("JumpRegisterIfZero"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpRegisterIfZero")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_POINTER },
        .opcode = 0x2b,
    };
    specifications[13] = (OpcodeSpecification){
        .name = string_view_from_string("JumpAddressIfNotDivideByZero"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpAddressIfNotDivideByZero")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_ADDRESS },
        .opcode = 0x25,
    };
    specifications[14] = (OpcodeSpecification){
        .name = string_view_from_string("JumpRegisterIfLessThanOrEqual"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpRegisterIfLessThanOrEqual")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_POINTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x2a,
    };
    specifications[15] = (OpcodeSpecification){
        .name = string_view_from_string("PushRegister"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("PushRegister")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_REGISTER },
        .opcode = 0x15,
    };
    specifications[16] = (OpcodeSpecification){
        .name = string_view_from_string("SubtractWithCarryTargetLhsRhs"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("SubtractWithCarryTargetLhsRhs")),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x9,
    };
    specifications[17] = (OpcodeSpecification){
        .name = string_view_from_string("MoveTargetSource"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("MoveTargetSource")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x2,
    };
    specifications[18] = (OpcodeSpecification){
        .name = string_view_from_string("DivmodTargetModLhsRhs"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("DivmodTargetModLhsRhs")),
        .argument_count = 4,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0xb,
    };
    specifications[19] = (OpcodeSpecification){
        .name = string_view_from_string("AndTargetLhsRhs"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("AndTargetLhsRhs")),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0xc,
    };
    specifications[20] = (OpcodeSpecification){
        .name = string_view_from_string("JumpRegisterIfNotCarry"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpRegisterIfNotCarry")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_POINTER },
        .opcode = 0x2e,
    };
    specifications[21] = (OpcodeSpecification){
        .name = string_view_from_string("JumpAddressIfDivideByZero"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpAddressIfDivideByZero")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_ADDRESS },
        .opcode = 0x24,
    };
    specifications[22] = (OpcodeSpecification){
        .name = string_view_from_string("JumpRegisterIfGreaterThan"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpRegisterIfGreaterThan")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_POINTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x27,
    };
    specifications[23] = (OpcodeSpecification){
        .name = string_view_from_string("JumpAddressIfEqual"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpAddressIfEqual")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_ADDRESS, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x1b,
    };
    specifications[24] = (OpcodeSpecification){
        .name = string_view_from_string("JumpRegisterIfCarry"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpRegisterIfCarry")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_POINTER },
        .opcode = 0x2d,
    };
    specifications[25] = (OpcodeSpecification){
        .name = string_view_from_string("JumpAddressIfZero"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpAddressIfZero")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_ADDRESS },
        .opcode = 0x20,
    };
    specifications[26] = (OpcodeSpecification){
        .name = string_view_from_string("CompareTargetLhsRhs"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("CompareTargetLhsRhs")),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x14,
    };
    specifications[27] = (OpcodeSpecification){
        .name = string_view_from_string("HaltAndCatchFire"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("HaltAndCatchFire")),
        .argument_count = 0,
        .required_arguments = { ARGUMENT_TYPE_NONE },
        .opcode = 0x6,
    };
    specifications[28] = (OpcodeSpecification){
        .name = string_view_from_string("MovePointerSource"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("MovePointerSource")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_POINTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x5,
    };
    specifications[29] = (OpcodeSpecification){
        .name = string_view_from_string("SubtractTargetSourceImmediate"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("SubtractTargetSourceImmediate")),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x13,
    };
    specifications[30] = (OpcodeSpecification){
        .name = string_view_from_string("SwapFramebuffers"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("SwapFramebuffers")),
        .argument_count = 0,
        .required_arguments = { ARGUMENT_TYPE_NONE },
        .opcode = 0x35,
    };
    specifications[31] = (OpcodeSpecification){
        .name = string_view_from_string("AddTargetLhsRhs"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("AddTargetLhsRhs")),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x7,
    };
    specifications[32] = (OpcodeSpecification){
        .name = string_view_from_string("NoOp"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("NoOp")),
        .argument_count = 0,
        .required_arguments = { ARGUMENT_TYPE_NONE },
        .opcode = 0x31,
    };
    specifications[33] = (OpcodeSpecification){
        .name = string_view_from_string("JumpAddressIfGreaterThan"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpAddressIfGreaterThan")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_ADDRESS, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x1c,
    };
    specifications[34] = (OpcodeSpecification){
        .name = string_view_from_string("JumpAddress"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpAddress")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_ADDRESS },
        .opcode = 0x19,
    };
    specifications[35] = (OpcodeSpecification){
        .name = string_view_from_string("JumpAddressIfLessThan"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpAddressIfLessThan")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_ADDRESS, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x1d,
    };
    specifications[36] = (OpcodeSpecification){
        .name = string_view_from_string("NotTargetSource"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("NotTargetSource")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0xf,
    };
    specifications[37] = (OpcodeSpecification){
        .name = string_view_from_string("DumpMemory"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("DumpMemory")),
        .argument_count = 0,
        .required_arguments = { ARGUMENT_TYPE_NONE },
        .opcode = 0xfffe,
    };
    specifications[38] = (OpcodeSpecification){
        .name = string_view_from_string("JumpRegister"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpRegister")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_REGISTER },
        .opcode = 0x1a,
    };
    specifications[39] = (OpcodeSpecification){
        .name = string_view_from_string("InvisibleFramebufferAddress"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("InvisibleFramebufferAddress")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_REGISTER },
        .opcode = 0x38,
    };
    specifications[40] = (OpcodeSpecification){
        .name = string_view_from_string("JumpAddressIfCarry"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpAddressIfCarry")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_ADDRESS },
        .opcode = 0x22,
    };
    specifications[41] = (OpcodeSpecification){
        .name = string_view_from_string("CallAddress"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("CallAddress")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_ADDRESS },
        .opcode = 0x17,
    };
    specifications[42] = (OpcodeSpecification){
        .name = string_view_from_string("JumpAddressIfNotZero"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpAddressIfNotZero")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_ADDRESS },
        .opcode = 0x21,
    };
    specifications[43] = (OpcodeSpecification){
        .name = string_view_from_string("AddWithCarryTargetLhsRhs"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("AddWithCarryTargetLhsRhs")),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x34,
    };
    specifications[44] = (OpcodeSpecification){
        .name = string_view_from_string("MoveRegisterAddress"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("MoveRegisterAddress")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_ADDRESS },
        .opcode = 0x1,
    };
    specifications[45] = (OpcodeSpecification){
        .name = string_view_from_string("JumpAddressIfNotCarry"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpAddressIfNotCarry")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_ADDRESS },
        .opcode = 0x23,
    };
    specifications[46] = (OpcodeSpecification){
        .name = string_view_from_string("JumpRegisterIfLessThan"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpRegisterIfLessThan")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_POINTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x28,
    };
    specifications[47] = (OpcodeSpecification){
        .name = string_view_from_string("JumpRegisterIfNotZero"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpRegisterIfNotZero")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_POINTER },
        .opcode = 0x2c,
    };
    specifications[48] = (OpcodeSpecification){
        .name = string_view_from_string("DumpRegisters"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("DumpRegisters")),
        .argument_count = 0,
        .required_arguments = { ARGUMENT_TYPE_NONE },
        .opcode = 0xffff,
    };
    specifications[49] = (OpcodeSpecification){
        .name = string_view_from_string("MoveAddressRegister"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("MoveAddressRegister")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_ADDRESS, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x3,
    };
    specifications[50] = (OpcodeSpecification){
        .name = string_view_from_string("AddTargetSourceImmediate"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("AddTargetSourceImmediate")),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x12,
    };
    specifications[51] = (OpcodeSpecification){
        .name = string_view_from_string("MultiplyHighLowLhsRhs"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("MultiplyHighLowLhsRhs")),
        .argument_count = 4,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0xa,
    };
    specifications[52] = (OpcodeSpecification){
        .name = string_view_from_string("GetKeyState"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("GetKeyState")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x32,
    };
    specifications[53] = (OpcodeSpecification){
        .name = string_view_from_string("SubtractTargetLhsRhs"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("SubtractTargetLhsRhs")),
        .argument_count = 3,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x8,
    };
    specifications[54] = (OpcodeSpecification){
        .name = string_view_from_string("JumpRegisterIfGreaterThanOrEqual"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpRegisterIfGreaterThanOrEqual")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_POINTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x29,
    };
    specifications[55] = (OpcodeSpecification){
        .name = string_view_from_string("JumpRegisterIfDivideByZero"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpRegisterIfDivideByZero")),
        .argument_count = 1,
        .required_arguments = { ARGUMENT_TYPE_POINTER },
        .opcode = 0x2f,
    };
    specifications[56] = (OpcodeSpecification){
        .name = string_view_from_string("PollTime"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("PollTime")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x33,
    };
    specifications[57] = (OpcodeSpecification){
        .name = string_view_from_string("JumpAddressIfLessThanOrEqual"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpAddressIfLessThanOrEqual")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_ADDRESS, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x1f,
    };
    specifications[58] = (OpcodeSpecification){
        .name = string_view_from_string("JumpAddressIfGreaterThanOrEqual"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("JumpAddressIfGreaterThanOrEqual")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_ADDRESS, ARGUMENT_TYPE_REGISTER },
        .opcode = 0x1e,
    };
    specifications[59] = (OpcodeSpecification){
        .name = string_view_from_string("MoveRegisterImmediate"),
        .mnemonic = opcode_to_mnemonic(string_view_from_string("MoveRegisterImmediate")),
        .argument_count = 2,
        .required_arguments = { ARGUMENT_TYPE_REGISTER, ARGUMENT_TYPE_IMMEDIATE },
        .opcode = 0x0,
    };
    return (OpcodeList){
        .specifications = specifications,
        .num_specifications = num_opcodes,
    };
}