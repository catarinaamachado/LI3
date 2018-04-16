#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void query6(TAD_community com) {
  printf("\n\nQuery 6\n");


  //n maior do que o nr de posts que existem
  int N6 = 10;
  Date begin6 = createDate(12, 9, 2010);
  Date end6 = createDate(12, 9, 2010);
  LONG_list f = most_voted_answers(com, N6, begin6, end6);
  if(f != NULL){
    for(int i = 0; i < 1; i++) //só existe 1 neste caso
      printf("Elemento %d: %ld\n", i, get_list(f, i));
   }
  free_list(f);
  free_date(begin6);
  free_date(end6);

  printf("\n");

  //n menor do que o nr de posts que existem
  int N6_1 = 4;
  Date begin6_1 = createDate(1, 9, 2010);
  Date end6_1 = createDate(1, 9, 2010);
  LONG_list ff = most_voted_answers(com, N6_1, begin6_1, end6_1);
  if(ff != NULL){
    for(int i = 0; i < N6_1; i++)  //se tentar por um numero maior não imprime
      printf("Elemento %d: %ld\n", i, get_list(ff, i));
   }
  free_list(ff);
  free_date(begin6_1);
  free_date(end6_1);


  //n = 0
  int N6_2 = 0;
  Date begin6_2 = createDate(1, 9, 2010);
  Date end6_2 = createDate(1, 9, 2010);
  LONG_list fff = most_voted_answers(com, N6_2, begin6_2, end6_2);
  if(fff != NULL){
    for(int i = 0; i < 10; i++)
      printf("Elemento %d: %ld\n", i, get_list(fff, i));
  }
  free_list(fff);
  free_date(begin6_2);
  free_date(end6_2);

  printf("\n\n");
}
