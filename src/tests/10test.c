#include <stdio.h>
#include <stdlib.h>
#include "struct.h"


void query10(TAD_community com) {

  printf("\n\nQuery 10\n");
  long id10 = 30334; //não existe
  long j = better_answer(com, id10);
  printf("%ld\n", j);
  (void)j;
  long id11 = 5942; //pergunta
  long j2 = better_answer(com, id11);
  printf("%ld\n", j2);
  (void)j2;
  long id12 = 10; //resposta
  long j3 = better_answer(com, id12);
  printf("%ld\n", j3);
  (void)j3;
  printf("\n\n\n\n\n\n");


}
