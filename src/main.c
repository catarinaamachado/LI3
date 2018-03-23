#include <stdlib.h>
#include <stdio.h>
#include <gmodule.h>

#include "struct.h"

int main(int argc, char const *argv[]){

  TAD_community com = init();

  com = load(com, "../android/");

  GDate * do1 = g_date_new_dmy(15, 9, 2008);
  GDate * do2 = g_date_new_dmy(24, 11, 2010);
  int oi = g_date_days_between(do1, do2);

  printf("%d\n", oi);


  for(int i = 800; i < 801; i++){
    Day diiiias = lookDay(com, i);

    if(diiiias != NULL) {
      int dia = getDay(diiiias);
      int mes = getMonth(diiiias);
      int ano = getYear(diiiias);

      printf("\n\nPara i = %d: %d-%d-%d\n", i, dia, mes, ano);

      printf("Q:%d A:%d\n", getDAYNQuestions(diiiias), getDAYNAnswers(diiiias));

      printf("Questions:\n");
      getDAYQuestion(diiiias);

      printf("Answers:\n");
      getDAYAnswer(diiiias);
    }

    diiiias = NULL;
  }


/*
  USER us;
  long id = 123;//atol(argv[1]);
  us = get_user_info(com, id);

  if (us != NULL) {

    printf("User %ld\nBio:\n%s\n", id, get_bio(us));

    long * posts = get_10_latest_posts(us);

    for (int i = 0; i < 10 && posts[i] != -1; i++) {

      printf("Post: %ld\n", posts[i]);

    }
  }

  else
    printf("No user\n");



  STR_pair ola = info_from_post(com, 197);
  char * fst = get_fst_str(ola);
  char * snd = get_snd_str(ola);

  printf("Title: %s\nUsername: %s\n", fst, snd);
*/

  free(com);

  return 0;
}
