#include <stdlib.h>
#include <stdio.h>
#include <gmodule.h>
#include <string.h>

#include "struct.h"


int main(int argc, char const *argv[]){

  TAD_community com = init();

  com = load(com, "../android/");
/*
  GDate * do1 = g_date_new_dmy(15, 9, 2008);
  GDate * do2 = g_date_new_dmy(1, 9, 2010);
  int oi = g_date_days_between(do1, do2);

  Day d = lookDay(com, oi);

  char * all_tags;
  all_tags = getTags(getDAYQuestionAtIndex(d, 0));

  printf("Tags de uma question: %s\n", all_tags);
  // <contacts><nexus-one><2.2-froyo><sms>


  //test query 11 FIXME SOMETHING IS WRONG
  Date date1 = createDate(8, 9, 2010);
  Date date2 = createDate(8, 12, 2011);

  LONG_list list = most_used_best_rep(com, 10, date1, date2);
  if (list != NULL){
    for(int i = 0; i < 10; i++)
      printf("%ld\n", get_list(list, i));
  }



  // int t = strlen(all_tags);

  // for(int i = 0; i < t; i++){
  //   printf("nao li isto. tamanho: %d\n", t);
  //   char * tentativa = separaTags2(all_tags + i);
  //   printf("%s\n", tentativa);
  //   i += strlen(tentativa) + 1;
  //   int t2 = strlen(tentativa);
  //   printf("li isto. tamanho: %d\n", t2);
  // }


  // Tags tagsS;
  // int tag_id = 0;
  // int tag_value;
  // char * tag_name = "sms";
  //
  // printf("\n\n");
  //
  // for(int i = 0; i < 2 ; i++){
  //   tagsS = lookTag(com, tag_name);
  //   if (tagsS != NULL){
  //     tag_id = getTagId(tagsS);
  //     tag_name = getTagName(tagsS);
  //     tag_value = getTagValue(tagsS);
  //     printf("Id: %d Nome: %s Value: %d\n", tag_id, tag_name, tag_value);
  //     tag_name = "contacts";
  //   }
  // }
  //


  //test query 3
  Date date3 = createDate(1, 9, 2010);
  Date date4 = createDate(1, 9, 2017);

  LONG_pair query3 = total_posts(com, date3, date4);

  printf("Query 3: %ld questions; %ld answers\n", get_fst_long(query3), get_snd_long(query3));


  //test query 6
  printf("\nQuery 6:\n");
  LONG_list query6 = most_voted_answers(com, 2, date3, date4);

  for(int i = 0; i < 2; i++){
    long a = get_list(query6, i);
    printf("ID Answer%d: %ld\n", i+1, a);
  }


  int post_id1 = 938;
  int post_id2 = 941;
  int post_id3 = 944;

  Questions question1 = lookQuestion(com, post_id1);
  Questions question2 = lookQuestion(com, post_id2);
  Questions question3 = lookQuestion(com, post_id3);

  long utilizador1 = getQUserId(question1);
  long utilizador2 = getQUserId(question2);
  long utilizador3 = getQUserId(question3);

  printf("U1: %ld; U2: %ld; U3: %ld\n", utilizador1, utilizador2, utilizador3);

  Users user1 = lookUsers(com, utilizador1);
  // Users user2 = lookUsers(com, utilizador2);
  // Users user3 = lookUsers(com, utilizador3);
  //
   int reputacao1 = getReputation(user1);
  // int reputacao2 = getReputation(user2);
  // int reputacao3 = getReputation(user3);

   printf("R1: %d\n", reputacao1);

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
  LONG_list lista = better_answer(com, 100);
  if (lista != NULL)
    printf("%ld\n", get_list(lista,0));


//teste query 1
STR_pair ola = info_from_post(com, 158);
char * fst = get_fst_str(ola);
char * snd = get_snd_str(ola);

printf("Title: %s\nUsername: %s\n", fst, snd);
*/

//teste query 2
  LONG_list list = top_most_active(com, 50);

  for(int i = 0; i < 50; i++)
    printf("%ld\n", get_list(list, i));




  //free(com);

  return 0;
}
