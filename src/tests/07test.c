#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void query7(TAD_community com) {
  printf("\n\nQuery 7\n");

  //teste usual
  int N7 = 10;
  Date begin7 = createDate(15, 9, 2008);
  Date end7 = createDate(15, 9, 2010);
  LONG_list g = most_answered_questions(com, N7, begin7, end7);
  if(g != NULL){
    for(int i = 0; i < 10; i++)
      printf("Elemento %d: %ld\n", i, get_list(g, i));
  }
  free_list(g);
  free_date(begin7);
  free_date(end7);


  //data trocada
  int N7_1 = 10;
  Date begin7_1 = createDate(15, 9, 2010);
  Date end7_1 = createDate(15, 9, 2008);
  LONG_list gg = most_answered_questions(com, N7_1, begin7_1, end7_1);
  if(gg != NULL){
    for(int i = 0; i < 10; i++)
      printf("Elemento %d: %ld\n", i, get_list(gg, i));
  }
  free_list(gg);
  free_date(begin7_1);
  free_date(end7_1);

  printf("\n");

  //n maior do que o nr de posts que existem
  int N7_2 = 10;
  Date begin7_2 = createDate(12, 9, 2010);
  Date end7_2 = createDate(12, 9, 2010);
  LONG_list ggg = most_voted_answers(com, N7_2, begin7_2, end7_2);
  if(ggg != NULL){
    for(int i = 0; i < 1; i++) //só existe 1 neste caso
      printf("Elemento %d: %ld\n", i, get_list(ggg, i));
   }
  free_list(ggg);
  free_date(begin7_2);
  free_date(end7_2);

  printf("\n");

  //n menor do que o nr de posts que existem
  int N7_3 = 4;
  Date begin7_3 = createDate(1, 9, 2010);
  Date end7_3 = createDate(1, 9, 2010);
  LONG_list gggg = most_voted_answers(com, N7_3, begin7_3, end7_3);
  if(gggg != NULL){
    for(int i = 0; i < N7_3; i++)  //se tentar por um numero maior não imprime
      printf("Elemento %d: %ld\n", i, get_list(gggg, i));
   }
  free_list(gggg);
  free_date(begin7_3);
  free_date(end7_3);



  printf("\n\n");
}
