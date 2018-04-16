#include <stdio.h>
#include <stdlib.h>

#include "testes.h"

#include "tests/03test.c"
#include "tests/04test.c"
#include "tests/05test.c"
#include "tests/06test.c"
#include "tests/07test.c"
#include "tests/08test.c"
#include "tests/09test.c"
#include "tests/11test.c"


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
query3(com);

//QUERY 4
query4(com);

//QUERY 5
//query5(com);

//QUERY 6
query6(com);

//QUERY 7
query7(com);

//QUERY 8
//query8(com);

//QUERY 9
//query9(com);

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
query11(com);

}
