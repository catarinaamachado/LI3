#include <stdio.h>
#include <stdlib.h>

#include "testes.h"

#include "tests/05test.c"
#include "tests/08test.c"
#include "tests/09test.c"


void testes(TAD_community com) {

//QUERY 1
printf("QUERY 1\n");
long id1 = 4;
STR_pair a1 = info_from_post(com, id1);
printf("Titulo: %s  Username: %s\n", get_fst_str(a1), get_snd_str(a1));
(void)a1;
free_str_pair(a1);
long id2 = 3;
STR_pair b1 = info_from_post(com, id2);
printf("Titulo: %s  Username: %s\n", get_fst_str(b1), get_snd_str(b1));
(void)b1;
free_str_pair(b1);
long id3 = 2;
STR_pair c1 = info_from_post(com, id3);
printf("Titulo: %s  Username: %s\n", get_fst_str(c1), get_snd_str(c1));
(void)c1;
free_str_pair(c1);
printf("\n\n\n\n\n\n");

//QUERY 2
printf("QUERY 2\n");
int N2 = 10;
LONG_list b = top_most_active(com, N2);
(void)b;
free_list(b);
printf("\n\n\n\n\n\n");

//QUERY 3
printf("QUERY 3\n");
Date begin3 = createDate(15, 9, 2008); //um só dia
Date end3 = createDate(15, 9, 2008);
LONG_pair c = total_posts(com, begin3, end3);
(void)c;
printf("Nr perguntas %ld; Nr respostas %ld\n", get_fst_long(c), get_snd_long(c));
free_long_pair(c);
Date begin3_1 = createDate(15, 9, 2008); //caso normal
Date end3_1 = createDate(15, 9, 2015);
LONG_pair cc = total_posts(com, begin3_1, end3_1);
(void)cc;
printf("Nr perguntas %ld; Nr respostas %ld\n", get_fst_long(cc), get_snd_long(cc));
free_long_pair(cc);
Date begin3_2 = createDate(15, 9, 2008); //intervalo de tempo muito grande
Date end3_2 = createDate(15, 4, 2018);
LONG_pair ccc = total_posts(com, begin3_2, end3_2);
(void)ccc;
printf("Nr perguntas %ld; Nr respostas %ld\n", get_fst_long(ccc), get_snd_long(ccc));
free_long_pair(ccc);
Date begin3_3 = createDate(10, 9, 2017); //datas por ordem contrária(TODO deve dar 0 ou não?)
Date end3_3 = createDate(10, 9, 2009);
LONG_pair cccc = total_posts(com, begin3_3, end3_3);
(void)cccc;
printf("Nr perguntas %ld; Nr respostas %ld\n", get_fst_long(cccc), get_snd_long(cccc));
free_long_pair(cccc);
printf("\n\n\n\n\n\n");


//QUERY 4
printf("QUERY 4\n");
char tag4[] = "updates"; //não existe durante este periodo
Date begin4 = createDate(15, 9, 2008);
Date end4 = createDate(15, 9, 2008);
LONG_list d = questions_with_tag(com, tag4, begin4, end4);
(void)d;
for(int i = 0; i < 1; i++)
  printf("Elemento %d: %ld\n", i, get_list(d, i)); //logo, está vazia a lista
free_list(d);
// char tag4_1[] = "contacts"; //tag que nao existe
// Date begin4_1 = createDate(15, 9, 2008);
// Date end4_1 = createDate(16, 9, 2010);
// LONG_list dd = questions_with_tag(com, tag4_1, begin4_1, end4_1);
// (void)dd;
// for(int i = 0; i < 1; i++)
//   printf("Elemento %d: %ld\n", i, get_list(dd, i)); //logo, está vazia a lista
// // //free_list(dd);
char tag4_2[] = "applications"; //teste normal     *****É ESTE TESTE ISTO QUE DÁ ERRO******
Date begin4_2 = createDate(13, 9, 2010);
Date end4_2 = createDate(14, 9, 2010);
LONG_list ddd = questions_with_tag(com, tag4_2, begin4_2, end4_2);
(void)ddd;
for(int i = 0; i < 10; i++)
  printf("Elemento %d: %ld\n", i, get_list(ddd, i));
free_list(ddd);
printf("\n\n\n\n\n\n");

//QUERY 5
printf("QUERY 5\n");
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
printf("\n\n\n\n\n\n");

//QUERY 6
printf("QUERY 6\n");
int N6 = 40;
Date begin6 = createDate(15, 9, 2008);
Date end6 = createDate(15, 9, 2008);
LONG_list f = most_voted_answers(com, N6, begin6, end6);
(void)f;
// for(int i = 0; i < 1; i++)
//    printf("Elemento %d: %ld\n", i, get_list(f, i));
free_list(f);
printf("\n\n\n\n\n\n");

//QUERY 7
printf("QUERY 7\n");
int N7 = 0;
Date begin7 = createDate(15, 9, 2008);
Date end7 = createDate(15, 9, 2008);
LONG_list g = most_answered_questions(com, N7, begin7, end7);
(void)g;
printf("\n\n\n\n\n\n");

//QUERY 8
printf("QUERY 8\n");
char word8[] = "android";
int N8 = 10;
LONG_list h = contains_word(com, word8, N8);
//printf("Last %d containing word %s:\n", N8, word8);
for (int l = 0; l < N8; l++)
    //printf("%d - %ld\n", l, get_list(h, l));
(void)h;
free_list(h);
printf("\n\n\n\n\n\n");

//QUERY 9
printf("QUERY 9\n");
long id9u1, id9u2; id9u1 = id9u2 = 10;
int N9 = 10;
LONG_list i = both_participated(com, id9u1, id9u2, N9);
//printf("Last %d both %ld and %ld participated:\n", N9, id9u1, id9u2);
for (int l = 0; l < N9; l++)
    //printf("%d - %ld\n", l+1, get_list(h, l));
(void)i;
free_list(i);
printf("\n\n\n\n\n\n");

//QUERY 10
printf("QUERY 10\n");
long id10 = 4; //não existe
long j = better_answer(com, id10);
(void)j;
long id11 = 5; //pergunta
long j2 = better_answer(com, id11);
(void)j2;
long id12 = 10; //resposta
long j3 = better_answer(com, id12);
(void)j3;
printf("\n\n\n\n\n\n");

//QUERY 11
printf("QUERY 11\n");
int N11 = 11;
Date begin11 = createDate(15, 9, 2008);
Date end11 = createDate(15, 9, 2008);
LONG_list k = most_used_best_rep(com, N11, begin11, end11);
(void)k;
free_list(k);
printf("\n\n\n\n\n\n");

}
