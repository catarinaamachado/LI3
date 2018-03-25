#include <stdlib.h>
#include <stdio.h>
#include <gmodule.h>

#include "struct.h"

int main(int argc, char const *argv[]){

  TAD_community com = init();

  com = load(com, "../android/");


/*
  //test query 3
  Date date1 = createDate(1, 9, 2010);
  Date date2 = createDate(1, 9, 2014);

  LONG_pair query3 = total_posts(com, date1, date2);

  printf("Query 3: %ld questions; %ld answers\n", get_fst_long(query3), get_snd_long(query3));


  //test query 6
  printf("\nQuery 6:\n");
  LONG_list query6 = most_voted_answers(com, 2, date1, date2);

  for(int i = 0; i < 2; i++){
    long a = get_list(query6, i);
    printf("ID Answer%d: %ld\n", i+1, a);
  }

  //test query 7
  printf("\nQuery 7:\n");
  LONG_list query7 = most_answered_questions(com, 2, date1, date2);

  for(int i = 0; i < 2; i++){
    long a = get_list(query7, i);
    printf("ID Question%d: %ld\n", i+1, a);
  }


  //test query 4
  printf("\nExperiencias\n");
  GDate * do1 = g_date_new_dmy(15, 9, 2008);
  GDate * do2 = g_date_new_dmy(1, 9, 2010);
  int oi = g_date_days_between(do1, do2);

  printf("Um indice: %d\n", oi);


  Day d = lookDay(com, oi);

  char * cenas;
  cenas = getTags(getDAYQuestionAtIndex(d, 0));

  printf("Tags de um dia: %s\n", cenas);

  printf("\nQuery 4:\n");
  LONG_list query4 = questions_with_tag(com, "contacts", date1, date2);
  for(int i = 0; i < 20; i++){
    long a = get_list(query4, i);
    printf("ID Question%d: %ld\n", i+1, a);
  }
*/
  //test day struct
/*
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



  USER us;
  long id = 123;//atol(argv[1]);
  us = get_user_info(com, id);

  if (us != NULL) {

  //   printf("%ld\n", getQuestionId(q));
  //   printf("%s\n\n", getQDate(q));i++;}
  // }


  STR_pair ola = info_from_post(com, 197);
  char * fst = get_fst_str(ola);
  char * snd = get_snd_str(ola);

  printf("Title: %s\nUsername: %s\n", fst, snd);


  // LONG_list ll = contains_word(com, "root", 10);
  // for(int i = 0; i < 10; i++) {
  //   long v = get_list(ll, i);
  //   printf("%ld\n\n", v);
  // }
  int n = 3;
  LONG_list ll = both_participated(com, 4, 4, n);
  for(int i = 0; i < n; i++) {
    long v = get_list(ll, i);
    printf("%ld\n\n", v);
  }


//teste query 10
  LONG_list list = better_answer(com, 4);
  if (list != NULL)
    printf("%ld\n", get_list(list,0));
*/


//teste query 2
  LONG_list list = top_most_active(com, 50);

  for(int i = 0; i < 50; i++)
    printf("%ld\n", get_list(list, i));


  free(com);

  return 0;
}
