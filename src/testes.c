#include <stdio.h>
#include "testes.h"



void testes(TAD_community com) {

//QUERY 1
long id1 = 4; //não existe
STR_pair a1 = info_from_post(com, id1);
printf("Titulo: %s  Username: %s\n", get_fst_str(a1), get_snd_str(a1));
(void)a1;
free_str_pair(a1);
long id2 = 3; //pergunta
STR_pair b1 = info_from_post(com, id2);
printf("Titulo: %s  Username: %s\n", get_fst_str(b1), get_snd_str(b1));
(void)b1;
free_str_pair(b1);
long id3 = 2; //resposta
STR_pair c1 = info_from_post(com, id3);
printf("Titulo: %s  Username: %s\n", get_fst_str(c1), get_snd_str(c1));
(void)c1;
free_str_pair(c1);

//QUERY 2
int N2 = 10; //numero de utilizadores com mais posts
LONG_list b = top_most_active(com, N2);
(void)b;
free_list(b);

//QUERY 3
Date begin3 = createDate(15, 9, 2008);
Date end3 = createDate(15, 9, 2008);
LONG_pair c = total_posts(com, begin3, end3);
(void)c;

//QUERY 4
char tag4[] = "updates";
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
int N6 = 40;
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
//printf("Last %d containing word %s:\n", N8, word8);
for (int l = 0; l < N8; l++)
    //printf("%d - %ld\n", l, get_list(h, l));
(void)h;

//QUERY 9
long id9u1, id9u2; id9u1 = id9u2 = 10;
int N9 = 10;
LONG_list i = both_participated(com, id9u1, id9u2, N9);
//printf("Last %d both %ld and %ld participated:\n", N9, id9u1, id9u2);
for (int l = 0; l < N9; l++)
    //printf("%d - %ld\n", l+1, get_list(h, l));
(void)i;

//QUERY 10
long id10 = 4; //não existe
long j = better_answer(com, id10);
(void)j;
long id11 = 5; //pergunta
long j2 = better_answer(com, id11);
(void)j2;
long id12 = 10; //resposta
long j3 = better_answer(com, id12);
(void)j3;


//QUERY 11
int N11 = 11;
Date begin11 = createDate(15, 9, 2008);
Date end11 = createDate(15, 9, 2008);
LONG_list k = most_used_best_rep(com, N11, begin11, end11);
(void)k;

}
