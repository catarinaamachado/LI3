#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

void query3(TAD_community com) {
  printf("\n\nQuery 3\n");

  //teste 1 prof
 Date begin3 = createDate(1, 7, 2016);
 Date end3 = createDate(31, 7, 2016);
 LONG_pair c = total_posts(com, begin3, end3);

 printf("Nr perguntas %ld; Nr respostas %ld\n", get_fst_long(c), get_snd_long(c));

 free_long_pair(c);
 free_date(begin3);
 free_date(end3);

 //teste 3 prof
 Date begin3_1 = createDate(01, 01, 2014);
 Date end3_1 = createDate(31, 12, 2014);
 LONG_pair cc = total_posts(com, begin3_1, end3_1);

 printf("Nr perguntas %ld; Nr respostas %ld\n", get_fst_long(cc), get_snd_long(cc));

 free_long_pair(cc);
 free_date(begin3_1);
 free_date(end3_1);

  //
  // //um só dia e sem posts
  // Date begin3 = createDate(15, 9, 2008);
  // Date end3 = createDate(15, 9, 2008);
  // LONG_pair c = total_posts(com, begin3, end3);
  //
  // printf("Nr perguntas %ld; Nr respostas %ld\n", get_fst_long(c), get_snd_long(c));
  //
  // free_long_pair(c);
  // free_date(begin3);
  // free_date(end3);
  //
  //
  // //caso vulgar
  // Date begin3_1 = createDate(15, 9, 2008);
  // Date end3_1 = createDate(15, 9, 2010);
  // LONG_pair cc = total_posts(com, begin3_1, end3_1);
  //
  // printf("Nr perguntas %ld; Nr respostas %ld\n", get_fst_long(cc), get_snd_long(cc));
  //
  // free_long_pair(cc);
  // free_date(begin3_1);
  // free_date(end3_1);
  //
  //
  // //intervalo de tempo muito grande
  // Date begin3_2 = createDate(15, 9, 2008);
  // Date end3_2 = createDate(15, 4, 2018);
  // LONG_pair ccc = total_posts(com, begin3_2, end3_2);
  //
  // printf("Nr perguntas %ld; Nr respostas %ld\n", get_fst_long(ccc), get_snd_long(ccc));
  //
  // free_long_pair(ccc);
  // free_date(begin3_2);
  // free_date(end3_2);
  //
  //
  // //datas por ordem contrária
  // Date begin3_3 = createDate(10, 9, 2017);
  // Date end3_3 = createDate(10, 9, 2009);
  // LONG_pair cccc = total_posts(com, begin3_3, end3_3);
  //
  // printf("Nr perguntas %ld; Nr respostas %ld\n", get_fst_long(cccc), get_snd_long(cccc));
  //
  // free_long_pair(cccc);
  // free_date(begin3_3);
  // free_date(end3_3);


  printf("\n\n");
}
