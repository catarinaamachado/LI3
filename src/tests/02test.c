#include <stdio.h>
#include <stdlib.h>
#include "struct.h"


void query2(TAD_community com) {

  printf("\n\nQuery 2\n");
  int N2 = 10;
  LONG_list b = top_most_active(com, N2);
  for(int i = 0; i < N2; i++) {
    printf("Rank: %d ID Utilizador: %ld\n", i ,get_list(b, i));
  }
  (void)b;
  free_list(b);
  printf("\n\n\n\n\n\n");

}
