#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "string_view.h"

typedef enum {
    ARGUMENT_TYPE_NONE,
    ARGUMENT_TYPE_IMMEDIATE,
    ARGUMENT_TYPE_ADDRESS,
    ARGUMENT_TYPE_REGISTER,
    ARGUMENT_TYPE_POINTER,
    ARGUMENT_TYPE_LABEL,
    // TODO: Difference?
} ArgumentType;

typedef uint64_t Opcode;

typedef struct {
    StringView name; // e.g. "MoveRegisterImmediate"
    StringView mnemonic; // e.g. "COPY"
    size_t argument_count; // e.g. 2
    ArgumentType required_arguments[6]; // e.g. { Immediate, Register }
    Opcode opcode; // e.g. 0x0000
} OpcodeSpecification;

#define OPCODE_MAPPINGS \
    X(MoveRegisterImmediate, COPY) \
    X(MoveRegisterAddress, COPY) \
    X(MoveTargetSource, COPY) \
    X(MoveAddressRegister, COPY) \
    X(MoveTargetPointer, COPY) \
    X(MovePointerSource, COPY) \
    X(HaltAndCatchFire, HALT) \
    X(AddTargetLhsRhs, ADD) \
    X(AddWithCarryTargetLhsRhs, ADD_CARRY) \
    X(SubtractTargetLhsRhs, SUB) \
    X(SubtractWithCarryTargetLhsRhs, SUB_CARRY) \
    X(MultiplyHighLowLhsRhs, MULT) \
    X(DivmodTargetModLhsRhs, DIVMOD) \
    X(AndTargetLhsRhs, AND) \
    X(OrTargetLhsRhs, OR) \
    X(XorTargetLhsRhs, XOR) \
    X(NotTargetSource, NOT) \
    X(LeftShiftTargetLhsRhs, LSHIFT) \
    X(RightShiftTargetLhsRhs, RSHIFT) \
    X(AddTargetSourceImmediate, ADD) \
    X(SubtractTargetSourceImmediate, SUB) \
    X(CompareTargetLhsRhs, COMP) \
    X(PushRegister, PUSH) \
    X(PopRegister, POP) \
    X(CallAddress, CALL) \
    X(CallRegister, CALL) \
    X(CallPointer, CALL) \
    X(Return, RETURN) \
    X(JumpAddress, JUMP) \
    X(JumpRegister, JUMP) \
\
    X(JumpAddressIfEqual, JUMP_EQ) \
    X(JumpAddressIfGreaterThan, JUMP_GT) \
    X(JumpAddressIfLessThan, JUMP_LT) \
    X(JumpAddressIfGreaterThanOrEqual, JUMP_GTEQ) \
    X(JumpAddressIfLessThanOrEqual, JUMP_LTEQ) \
    X(JumpAddressIfZero, JUMP_ZERO) \
    X(JumpAddressIfNotZero, JUMP_NOT_ZERO) \
    X(JumpAddressIfCarry, JUMP_CARRY) \
    X(JumpAddressIfNotCarry, JUMP_NOT_CARRY) \
    X(JumpAddressIfDivideByZero, JUMP_DIVIDE_BY_ZERO) \
    X(JumpAddressIfNotDivideByZero, JUMP_NOT_DIVIDE_BY_ZERO) \
\
    X(JumpRegisterIfEqual, JUMP_EQ) \
    X(JumpRegisterIfGreaterThan, JUMP_GT) \
    X(JumpRegisterIfLessThan, JUMP_LT) \
    X(JumpRegisterIfGreaterThanOrEqual, JUMP_GTEQ) \
    X(JumpRegisterIfLessThanOrEqual, JUMP_LTEQ) \
    X(JumpRegisterIfZero, JUMP_ZERO) \
    X(JumpRegisterIfNotZero, JUMP_NOT_ZERO) \
    X(JumpRegisterIfCarry, JUMP_CARRY) \
    X(JumpRegisterIfNotCarry, JUMP_NOT_CARRY) \
    X(JumpRegisterIfDivideByZero, JUMP_DIVIDE_BY_ZERO) \
    X(JumpRegisterIfNotDivideByZero, JUMP_NOT_DIVIDE_BY_ZERO) \
\
    X(NoOp, NOOP) \
    X(GetKeyState, GET_KEY) \
    X(PollTime, POLL_TIME) \
    X(SwapFramebuffers, SWAP) \
    X(InvisibleFramebufferAddress, DRAW_BUFFER_ADDR) \
    X(PollCycleCountHighLow, POLL_CYCLES) \
\
    X(DumpRegisters, DUMP_REGISTERS) \
    X(DumpMemory, DUMP_REGISTERS)

StringView opcode_to_mnemonic(StringView opcode);
