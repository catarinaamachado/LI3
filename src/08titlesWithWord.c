#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

LONG_list contains_word(TAD_community com, char* word, int N) {
    LONG_list ll = create_list(N);

    GList * l, * k;

    int i = 0;

    for (l = k = getQuestions(com); N-i > 0 && l != NULL; l = l->next) {
        Questions q = l->data;

        char * title = getTitle(q);

        if(strstr(title, word)){
            set_list(ll, i, getQuestionId(q));
            i++;
        }

    }

     g_list_free(k);
    
    return ll;
}