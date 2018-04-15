#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void query5(TAD_community com) {
    printf("\n\nQuery 5\n");

    //user with more than 10 posts
    long id5 = 10;
    USER e = get_user_info(com, id5);
    
    if(e != NULL) {
        printf("User: %ld\nBio: %s\n", id5, get_bio(e));
        long *l = get_10_latest_posts(e);
    
        for (int i = 0; i < 10 && l[i] != -1; i++) {
            printf("%ld\n", l[i]);
        }
        free(l);
    } else
        printf("User: %ld doesn't exist\n", id5);
    
    free_user(e);

    //non existing user
    printf("\n\n");
    id5 = 11;
    e = get_user_info(com, id5);
    
    if(e != NULL) {
        printf("User: %ld\nBio: %s\n", id5, get_bio(e));
        long *l = get_10_latest_posts(e);
    
        for (int i = 0; i < 10 && l[i] != -1; i++) {
            printf("%ld\n", l[i]);
        }
        free(l);
    } else
        printf("User: %ld doesn't exist\n", id5);
    
    free_user(e);

    //user with less than 10 posts
    printf("\n\n");
    id5 = 13;
    e = get_user_info(com, id5);
    
    if(e != NULL) {
        printf("User: %ld\nBio: %s\n", id5, get_bio(e));
        long *l = get_10_latest_posts(e);
    
        for (int i = 0; i < 10 && l[i] != -1; i++) {
            printf("%ld\n", l[i]);
        }
        free(l);
    } else
        printf("User: %ld doesn't exist\n", id5);
    
    free_user(e);

    printf("\n\n");
}