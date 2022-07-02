#pragma once

#include "types.h"
#include "string_view.h"
#include <stddef.h>
#include <stdbool.h>

#define ENTRY_POINT 1914696 // TODO: must be auto-generated from the JSON file in the future!

typedef enum {
    CONSTANT_TYPE_ADDRESS,
    CONSTANT_TYPE_REGISTER,
    CONSTANT_TYPE_UNSIGNED_INTEGER,
} ConstantType;

typedef struct {
    char const* name;
    ConstantType type;
    uint64_t value;
} Constant;

typedef struct {
    char const* name;
    char const* abbreviation;
} ConstantAbbreviation;

extern size_t num_constants;
extern Constant constants[];

extern size_t num_constant_abbreviations;
extern ConstantAbbreviation constant_abbreviations[];

char const* find_constant_name_by_abbreviation(StringView abbreviation);
void get_constant(StringView abbreviation, bool* out_found, Constant** out_constant);
void get_constant_value(StringView abbreviation, ConstantType type, bool* out_found, uint64_t* out_value);
