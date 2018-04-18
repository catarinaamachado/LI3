#include <stdio.h>
#include <stdlib.h>
#include "struct.h"


void query1(TAD_community com) {


  printf("\n\nQuery 1\n");
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
}
