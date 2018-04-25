#include <stdio.h>
#include <stdlib.h>
#include "struct.h"


void query2(TAD_community com) {

  printf("\n\nQuery 2\n");

/*
  int array[] = {10, 20, 30};
  LONG_list b = top_most_active(com, array[0]);
  LONG_list c = top_most_active(com, array[1]);
  LONG_list d = top_most_active(com, array[2]);
  for(int i = 0; i < 3; i++) {
    for(int j= 0; j < array[i]; j++) {
      printf("Rank: %d \tID Utilizador: %ld \tRank: %d \tID Utilizador: %ld \tRank: %d \tID Utilizador: %ld\n",
      (j > 9)? 0: j , (j > 9)? 0 : get_list(b, j), (j > 19)? 0 : j, (j > 19)? 0 : get_list(c, j),
       j, get_list(d, j));
    }
  }
  (void)b;
  free_list(b);
  (void)c;
  free_list(c);
  (void)d;
  free_list(d);
*/

  int N2 = 10;
  LONG_list b = top_most_active(com, N2);
  for(int i = 0; i < N2; i++) {
    printf("Rank: %d ID Utilizador: %ld\n", i ,get_list(b, i));
  }
  (void)b;
  free_list(b);

  int N3 = 100;
  LONG_list c = top_most_active(com, N3);
  for(int i = 0; i < N3; i++) {
    printf("%ld; ", get_list(c, i));
  }
  (void)c;
  free_list(c);


  printf("\n\n\n\n\n\n");

}
