#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "string_view.h"

StringView string_view_from_pointers(char* const start_inclusive, char* const end_exclusive) {
    assert(start_inclusive == NULL || end_exclusive >= start_inclusive);
    assert((start_inclusive == NULL && end_exclusive == NULL) || (start_inclusive != NULL && end_exclusive != NULL));
    return (StringView){
        .data = start_inclusive,
        .length = (size_t)(end_exclusive - start_inclusive),
    };
}

StringView string_view_from_string(char* const string) {
    return (StringView){
        .data = string,
        .length = strlen(string),
    };
}

int string_view_compare(StringView const lhs, StringView const rhs) {
    size_t const min_length = lhs.length < rhs.length ? lhs.length : rhs.length;
    int const comparison_result = strncmp(lhs.data, rhs.data, min_length);
    if (comparison_result != 0) {
        return comparison_result;
    }
    if (lhs.length > rhs.length) {
        return 1;
    }
    if (lhs.length < rhs.length) {
        return -1;
    }
    return 0;
}

int case_insensitive_strncmp(char const * const lhs, char const * const rhs, size_t const n) {
    for (size_t i = 0; i < n; ++i) {
        char const left = toupper(lhs[i]);
        char const right = toupper(rhs[i]);
        int const comparison_result = strncmp(&left, &right, 1);
        if (comparison_result != 0) {
            return comparison_result;
        }
    }
    return 0;
}

int string_view_compare_case_insensitive(StringView const lhs, StringView const rhs) {
    size_t const min_length = lhs.length < rhs.length ? lhs.length : rhs.length;
    int const comparison_result = case_insensitive_strncmp(lhs.data, rhs.data, min_length);
    if (comparison_result != 0) {
        return comparison_result;
    }
    if (lhs.length > rhs.length) {
        return 1;
    }
    if (lhs.length < rhs.length) {
        return -1;
    }
    return 0;
}
