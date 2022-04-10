#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include "string_view.h"

typedef enum {
    ARGUMENT_TYPE_NONE,
    ARGUMENT_TYPE_IMMEDIATE,
    ARGUMENT_TYPE_REGISTER,
    ARGUMENT_TYPE_POINTER,
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
    X(MoveRegisterImmediate, COPY)
    // TODO: define all the opcodes!

StringView opcode_to_mnemonic(StringView opcode);
