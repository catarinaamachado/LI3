#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

/*
Dado uma palavra, devolver uma lista com os IDs de
N perguntas cujos títulos a contenham, ordenados por cronologia inversa;
*/

LONG_list contains_word(TAD_community com, char* word, int N) {
    LONG_list ll = create_list(N);

    GList * l;

    int i = 0;

    for (l = getQuestions(com); N-i > 0 && l != NULL; l = l->next) {
        Questions q = l->data;

        char * title = getTitle(q);

        if(strstr(title, word)){
            set_list(ll, i, getQuestionId(q));
            i++;
        }

    }

    return ll;
}
