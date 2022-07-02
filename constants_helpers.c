#include "constants.h"
#include <string.h>
#include <assert.h>

char const* find_constant_name_by_abbreviation(StringView abbreviation) {
    for (size_t i = 0; i < num_constant_abbreviations; ++i) {
        StringView current_abbreviation_view = string_view_from_string(constant_abbreviations[i].abbreviation);
        if (string_view_compare_case_insensitive(abbreviation, current_abbreviation_view) == 0) {
            return constant_abbreviations[i].name;
        }
    }
    return NULL;
}

void get_constant(StringView abbreviation, bool* out_found, Constant** out_constant) {
    char const* constant_name = find_constant_name_by_abbreviation(abbreviation);
    if (constant_name == NULL) {
        *out_found = false;
        return;
    }
    Constant* constant = NULL;
    for (size_t i = 0; i < num_constants; ++i) {
        if (strcmp(constant_name, constants[i].name) == 0) {
            *out_found = true;
            *out_constant = &constants[i];
            return;
        }
    }
    assert(constant != NULL && "constant with given name does not exist");
}

void get_constant_value(
    StringView abbreviation,
    ConstantType type,
    bool* out_found,
    uint64_t* out_value
) {
    bool success;
    Constant* constant;
    get_constant(abbreviation, &success, &constant);
    if (!success || constant->type != type) {
        *out_found = false;
        return;
    }
    *out_found = true;
    if (out_value != NULL) {
        *out_value = constant->value;
    }
}
