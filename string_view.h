#pragma once

#include <stdlib.h>

typedef struct {
    char* data;
    size_t length;
} StringView;

StringView string_view_from_pointers(char* const start_inclusive, char* const end_exclusive);
