#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

/**
@file 08titleWithWord.c
Resposta à interrogação 8.
*/

/**
\brief Dado uma palavra, devolve uma lista com os IDs de
N perguntas cujos títulos a contenham, ordenados por cronologia inversa.
@param com Apontador para a TCD_community.
@param word Palavra a verificar se está contida nos títulos.
@param N Número de perguntas pretendidas.
@returns LONG_list - IDs das N perguntas cujos títulos contenham o parâmetro
word, ordenados por cronologia inversa.
*/
LONG_list contains_word(TAD_community com, char* word, int N) {
    LONG_list ll = create_list(N);
    char * title;
    GList * l;
    Questions q;
    int i = 0;

    for (l = getQuestions(com); N-i > 0 && l != NULL; l = l->next) {
        q = l->data;

        title = getTitle(q);

        if(strstr(title, word)){
            set_list(ll, i, getQuestionId(q));
            i++;
        }

        free(title);
    }

    return ll;
}
