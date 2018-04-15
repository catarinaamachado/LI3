#include <stdio.h>
#include "interface.h"

int main(int argc, char const *argv[]){

    TAD_community com = init();

    com = load(com, "../dump/ubuntu");


    /*
    //QUERY 1
    long id1 = 0;
    STR_pair a = info_from_post(com, id1);
    (void)a;

    //QUERY 2
    int N2 = 0;
    LONG_list b = top_most_active(com, N2);
    (void)b;

    //QUERY 3
    Date begin3 = createDate(15, 9, 2008);
    Date end3 = createDate(15, 9, 2008);
    LONG_pair c = total_posts(com, begin3, end3);
    (void)c;

    //QUERY 4
    char tag4[] = "";
    Date begin4 = createDate(15, 9, 2008);
    Date end4 = createDate(15, 9, 2008);
    LONG_list d = questions_with_tag(com, tag4, begin4, end4);
    (void)d;

    //QUERY 5
    long id5 = 10;
    USER e = get_user_info(com, id5);
    if(e != NULL) {
        printf("User: %ld\nBio: %s\n", id5, get_bio(e));
        long *l = get_10_latest_posts(e);
        for (int i = 0; i < 10 && l[i] != -1; i++) {
            printf("%ld\n", l[i]);
        }
    } else
        printf("User: %ld doesn't exist\n", id5);
    (void)e;

    //QUERY 6
    int N6 = 0;
    Date begin6 = createDate(15, 9, 2008);
    Date end6 = createDate(15, 9, 2008);
    LONG_list f = most_voted_answers(com, N6, begin6, end6);
    (void)f;

    //QUERY 7
    int N7 = 0;
    Date begin7 = createDate(15, 9, 2008);
    Date end7 = createDate(15, 9, 2008);
    LONG_list g = most_answered_questions(com, N7, begin7, end7);
    (void)g;

    //QUERY 8
    char word8[] = "android";
    int N8 = 10;
    LONG_list h = contains_word(com, word8, N8);
    printf("Last %d containing word %s:\n", N8, word8);
    for (int l = 0; l < N8; l++)
        printf("%d - %ld\n", l, get_list(h, l));
    (void)h;

    //QUERY 9
    long id9u1, id9u2; id9u1 = id9u2 = 10;
    int N9 = 10;
    LONG_list i = both_participated(com, id9u1, id9u2, N9);
    printf("Last %d both %ld and %ld participated:\n", N9, id9u1, id9u2);
    for (int l = 0; l < N9; l++)
        printf("%d - %ld\n", l+1, get_list(h, l));
    (void)i;

    //QUERY 10
    long id10 = 0;
    long j = better_answer(com, id10);
    (void)j;

    //QUERY 11
    int N11 = 0;
    Date begin11 = createDate(15, 9, 2008);
    Date end11 = createDate(15, 9, 2008);
    LONG_list k = most_used_best_rep(com, N11, begin11, end11);
    (void)k;
    */

    com = clean(com);
    (void)com;

    return 0;
}
