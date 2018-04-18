#include <stdio.h>
#include <stdlib.h>

#include "testes.h"

#include "tests/01test.c"
#include "tests/02test.c"
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
query1(com);

//QUERY 2
query2(com);

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
