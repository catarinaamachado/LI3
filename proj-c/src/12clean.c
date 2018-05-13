#include <stdlib.h>
#include "struct.h"

/**
@file 12clean.c
Limpeza da estrutura de dados.
*/

/**
\brief Limpeza de toda a memória alocada na estrutura de dados.
@param com Apontador para a TCD_community.
@returns TAD_community - Apontador para null.
*/
TAD_community clean(TAD_community com) {

    cleanStruct(com);
    free(com);

    return NULL;
}
