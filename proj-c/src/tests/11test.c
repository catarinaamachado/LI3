#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void query11(TAD_community com) {
  printf("\n\nQuery 11\n");

  //teste 1
  int N11 = 5;
  Date begin11 = createDate(1, 11, 2013);
  Date end11 = createDate(30, 11, 2013);
  LONG_list k = most_used_best_rep(com, N11, begin11, end11);
  for(int i = 0; i < N11; i++)
     printf("Elemento %d: %ld\n", i, get_list(k, i));
  free_list(k);
  free_date(begin11);
  free_date(end11);

  printf("\n");

// teste 2
  int N11_1 = 10;
  Date begin11_1 = createDate(1, 1, 2014);
  Date end11_1 = createDate(31, 12, 2014);
  LONG_list kk = most_used_best_rep(com, N11_1, begin11_1, end11_1);
  for(int i = 0; i < N11_1; i++)
     printf("Elemento %d: %ld\n", i, get_list(kk, i));
  free_list(kk);
  free_date(begin11_1);
  free_date(end11_1);

  printf("\n");

  //
  // //teste usual
  // int N11 = 10;
  // Date begin11 = createDate(15, 9, 2009);
  // Date end11 = createDate(15, 9, 2010);
  // LONG_list k = most_used_best_rep(com, N11, begin11, end11);
  // for(int i = 0; i < N11; i++)
  //    printf("Elemento %d: %ld\n", i, get_list(k, i));
  // free_list(k);
  // free_date(begin11);
  // free_date(end11);
  //
  // printf("\n");
  //
  // //um só dia
  // int N11_1 = 5;
  // Date begin11_1 = createDate(13, 10, 2013);
  // Date end11_1 = createDate(13, 10, 2013);
  // LONG_list kk = most_used_best_rep(com, N11_1, begin11_1, end11_1);
  // for(int i = 0; i < N11_1; i++)
  //    printf("Elemento %d: %ld\n", i, get_list(kk, i));
  // free_list(kk);
  // free_date(begin11_1);
  // free_date(end11_1);
  //
  // printf("\n");

  // //grande intervalo de tempo
  // int N11_1 = 20;
  // Date begin11_1 = createDate(15, 9, 2008);
  // Date end11_1 = createDate(15, 9, 2017);
  // LONG_list kk = most_used_best_rep(com, N11_1, begin11_1, end11_1);
  //
  // for(int i = 0; i < N11_1; i++)
  //    printf("Elemento %d: %ld\n", i, get_list(kk, i));
  //
  // free_list(kk);
  // free_date(begin11_1);
  // free_date(end11_1);



  printf("\n\n");
}
