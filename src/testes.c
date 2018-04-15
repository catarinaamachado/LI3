#include <stdio.h>
#include "testes.h"

#include "tests/05test.c"
#include "tests/08test.c"
#include "tests/09test.c"


void testes(TAD_community com) {

    //QUERY 1
    long id1 = 4; //não existe
    STR_pair a1 = info_from_post(com, id1);
    char * fst = get_fst_str(a1); char * snd = get_snd_str(a1); 
    printf("Titulo: %s  Username: %s\n", fst, snd);
    free(fst);
    free(snd);
    free_str_pair(a1);

    long id2 = 3; //pergunta
    STR_pair b1 = info_from_post(com, id2);
    fst = get_fst_str(b1); snd = get_snd_str(b1); 
    printf("Titulo: %s  Username: %s\n", fst, snd);
    free(fst);
    free(snd);
    free_str_pair(b1);

    long id3 = 2; //resposta
    STR_pair c1 = info_from_post(com, id3);
    fst = get_fst_str(c1); snd = get_snd_str(c1); 
    printf("Titulo: %s  Username: %s\n", fst, snd);
    free(fst);
    free(snd);
    free_str_pair(c1);

    //QUERY 2
    int N2 = 10; //numero de utilizadores com mais posts
    LONG_list b = top_most_active(com, N2);
    free_list(b);


    query5(com);

    query8(com);

    query9(com);

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

}
