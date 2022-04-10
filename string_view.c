#include <assert.h>
#include <stdlib.h>
#include <string.h>
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
    } else if (lhs.length < rhs.length) {
        return -1;
    }
    return 0;
}
