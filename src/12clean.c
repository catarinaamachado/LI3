#include <malloc.h>
#include "struct.h"

TAD_community clean(TAD_community com) {

    cleanStruct(com);
    free(com);

    return NULL;
}
