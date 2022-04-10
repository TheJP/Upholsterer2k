#pragma once

#include <stdlib.h>

typedef struct {
    char* data;
    size_t length;
} StringView;

StringView string_view_from_pointers(char* start_inclusive, char* end_exclusive);
StringView string_view_from_string(char* string);
int string_view_compare(StringView lhs, StringView rhs);
int string_view_compare_case_insensitive(StringView lhs, StringView rhs);
