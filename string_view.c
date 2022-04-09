#include <assert.h>
#include <stdlib.h>
#include "string_view.h"

StringView string_view_from_pointers(char* const start_inclusive, char* const end_exclusive) {
    assert(start_inclusive == NULL || end_exclusive >= start_inclusive);
    assert((start_inclusive == NULL && end_exclusive == NULL) || (start_inclusive != NULL && end_exclusive != NULL));
    return (StringView){
        .data = start_inclusive,
        .length = (size_t)(end_exclusive - start_inclusive),
    };
}
