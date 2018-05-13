#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void query4(TAD_community com) {
  printf("\n\nQuery 4\n");

  //teste 1
  char tag4[] = "package-management";
  Date begin4 = createDate(1, 3, 2013);
  Date end4 = createDate(31, 3, 2013);
  LONG_list d = questions_with_tag(com, tag4, begin4, end4);
  if(d != NULL){
    for(int i = 0; i < 53; i++)
      printf("Elemento %d: %ld\n", i, get_list(d, i));
  }
  free_list(d);
  free_date(begin4);
  free_date(end4);


  //teste 2
  char tag4_1[] = "nautilus";
  Date begin4_1 = createDate(1, 1, 2014);
  Date end4_1 = createDate(31, 1, 2014);
  LONG_list dd = questions_with_tag(com, tag4_1, begin4_1, end4_1);
  if(dd != NULL){
    for(int i = 0; i < 30; i++)
      printf("Elemento %d: %ld\n", i, get_list(dd, i));
    }
  free_list(dd);
  free_date(begin4_1);
  free_date(end4_1);

  printf("\n");

  // //a tag não existe durante este periodo
  // char tag4[] = "updates";
  // Date begin4 = createDate(15, 9, 2008);
  // Date end4 = createDate(15, 9, 2008);
  // LONG_list d = questions_with_tag(com, tag4, begin4, end4);
  // if(d != NULL){
  //   for(int i = 0; i < 10; i++)
  //     printf("Elemento %d: %ld\n", i, get_list(d, i));
  // }
  // free_list(d);
  // free_date(begin4);
  // free_date(end4);


  // //teste normal
  // char tag4_1[] = "battery-life";
  // Date begin4_1 = createDate(12, 8, 2010);
  // Date end4_1 = createDate(12, 8, 2010);
  // LONG_list dd = questions_with_tag(com, tag4_1, begin4_1, end4_1);
  // if(dd != NULL){
  //   for(int i = 0; i < 1; i++)
  //     printf("Elemento %d: %ld\n", i, get_list(dd, i));
  //   }
  // free_list(dd);
  // free_date(begin4_1);
  // free_date(end4_1);
  //
  // printf("\n");

  /*
  //grande intervalo de tempo
  char tag4_2[] = "applications";
  Date begin4_2 = createDate(10, 10, 2008);
  Date end4_2 = createDate(10, 10, 2017);
  LONG_list ddd = questions_with_tag(com, tag4_2, begin4_2, end4_2);
  if(ddd != NULL){
  for(int i = 0; i < 30; i++)
    printf("Elemento %d: %ld\n", i, get_list(ddd, i));
  }
  free_list(ddd);
  free_date(begin4_2);
  free_date(end4_2);


  //datas trocadas
  char tag4_3[] = "applications";
  Date begin4_3 = createDate(10, 10, 2012);
  Date end4_3 = createDate(10, 10, 2010);
  LONG_list dddd = questions_with_tag(com, tag4_3, begin4_3, end4_3);
  if(dddd != NULL){
    for(int i = 0; i < 10; i++)
      printf("Elemento %d: %ld\n", i, get_list(dddd, i));
  }
  free_list(dddd);
  free_date(begin4_3);
  free_date(end4_3);


  printf("\n\n");
  */
}
