#include <stdlib.h>

#include "interface.h"
#include "struct.h"

TAD_community init() {
    TAD_community com;

    com = malloc(sizeof(TCD_community));

    com->users = g_ptr_array_sized_new (100000);
    com->questions = g_hash_table_new (g_int_hash, g_int_equal);
    com->day = g_ptr_array_sized_new (100000);

    return com;
}