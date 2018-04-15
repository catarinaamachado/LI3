#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

void query8(TAD_community com) {
    printf("\n\nQuery 8\n");

    //more than n posts
    char word8[] = "android";
    int N8 = 10;
    LONG_list h = contains_word(com, word8, N8);
    
    printf("Last %d containing word %s:\n", N8, word8);
    for (int l = 0; l < N8; l++)
        printf("%d - %ld\n", l, get_list(h, l));
    free_list(h);


    /*//less than n posts
    strcpy(word8, "afahtefdfaw");
    N8 = 10;
    h = contains_word(com, word8, N8);
    
    printf("Last %d containing word %s:\n", N8, word8);

    for (int l = 0; l < N8; l++)
        printf("%d - %ld\n", l, get_list(h, l));

    free_list(h);*/

}