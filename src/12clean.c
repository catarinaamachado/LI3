#include <stdlib.h>
#include "struct.h"

/**
@file 12clean.c
Limpeza da estrutura de dados.
*/

/**
\brief Limpeza de toda a memória alocada na estrutura de dados.
@param com Estrutura dos dados.
@returns TAD_community Estrutura dos dados.
*/
TAD_community clean(TAD_community com) {

    cleanStruct(com);
    free(com);

    return NULL;
}
