#include <stdio.h>
#include <stdlib.h>
#include "struct.h"


void query1(TAD_community com) {


  printf("\n\nQuery 1\n");


  long id1 = 801049;
  STR_pair a1 = info_from_post(com, id1);

  char * fst = get_fst_str(a1);
  char * snd = get_snd_str(a1);

  printf("Titulo: %s  Username: %s\n", fst, snd);

  free_str_pair(a1);
  free(fst);
  free(snd);

  long id2 = 796430;
  STR_pair b1 = info_from_post(com, id2);

  char * fst1 = get_fst_str(b1);
  char * snd1 = get_snd_str(b1);
  printf("Titulo: %s  Username: %s\n", fst1, snd1);

  free_str_pair(b1);
  free(fst1);
  free(snd1);

  /*
  long id3 = 2;
  STR_pair c1 = info_from_post(com, id3);

  char * fst2 = get_fst_str(c1);
  char * snd2 = get_snd_str(c1);
  printf("Titulo: %s  Username: %s\n", fst2, snd2);

  free_str_pair(c1);
  free(fst2);
  free(snd2);
  */

  printf("\n\n\n\n\n\n");
}
