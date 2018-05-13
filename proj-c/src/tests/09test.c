#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

void query9(TAD_community com) {
    printf("\n\nQuery 9\n");

    //more than n posts same user
    long id9u1, id9u2; id9u1 = id9u2 = 10;
    int N9 = 10;
    LONG_list i = both_participated(com, id9u1, id9u2, N9);
    
    printf("Last %d both %ld and %ld participated:\n", N9, id9u1, id9u2);
    
    for (int l = 0; l < N9; l++)
        printf("%d - %ld\n", l+1, get_list(i, l));
    
    free_list(i);


/*     //less than n posts
    id9u1 = 14; id9u2 = 14;
    N9 = 3;
    i = both_participated(com, id9u1, id9u2, N9);
    
    printf("Last %d both %ld and %ld participated:\n", N9, id9u1, id9u2);
    
    for (int l = 0; l < N9; l++)
        printf("%d - %ld\n", l+1, get_list(i, l));
    
    free_list(i); */

}