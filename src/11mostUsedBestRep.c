#include <gmodule.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>

#include "struct.h"

/*
Dado um intervalo arbitrário de tempo,
devolver as N tags mais usadas pelos N utilizadores com melhor reputação.
Em ordem decrescente do número de vezes em que a tag foi usada.
*/

char * separaTags(char * all_tags){
  char * token;
  token = strtok(all_tags, "><");

  return token;
}


LONG_list most_used_best_rep(TAD_community com, int N, Date begin, Date end){
  LONG_list ll = create_list(1);
  int n_days, count_day, n_questions, user_id, i, flag, sizePTRarray_users = 0, tag_id, tag_length, sizePTRarray_tags = 0;
  char * all_tags;

  GDate * begin_stackOverflow = g_date_new_dmy (15, 9, 2008);
  GDate * beginDate = g_date_new_dmy(get_day(begin), get_month(begin), get_year(begin));
  GDate * endDate = g_date_new_dmy(get_day(end), get_month(end), get_year(end));

  n_days = g_date_days_between(beginDate, endDate);
  count_day = g_date_days_between(begin_stackOverflow, beginDate);

  GPtrArray * total_tags = g_ptr_array_new();
  GPtrArray * total_users = g_ptr_array_new();
  Tags info_tag;
  Questions info_question;
  Users info_user;


  //descobrir N utilizadores com maior reputação
  while(n_days >= 0){
    Day d = lookDay(com, count_day);
    n_questions = getDAYNQuestions(d);

    for (i = 0; i < n_questions; i++){
      info_question = getDAYQuestionAtIndex(d, i);

      if(getQUserId(info_question) != -1){ //significa que a pergunta tem owner_id
        user_id = getQUserId(info_question);
        info_user = lookUsers(com, user_id);

        //averigua se o utilizador que fez essa question já se encontra ou não no GPtrArray total_users
        flag = g_ptr_array_find(total_users, info_user, NULL);
        if (flag != 1){
          g_ptr_array_add(total_users, info_user);
          sizePTRarray_users++;
        }
      }
    }

    count_day++; n_days--;
  }

  sortUsersReputation(total_users);

  //elimina utilizadores de forma a só termos um array com os N com melhor reputação
  if(sizePTRarray_users > N)
    g_ptr_array_remove_range(total_users, N, sizePTRarray_users - N);


  //descobrir as tags usadas pelos N utilizadores
  n_days = g_date_days_between(beginDate, endDate);
  count_day = g_date_days_between(begin_stackOverflow, beginDate);

  while(n_days >= 0){
    Day d = lookDay(com, count_day);
    n_questions = getDAYNQuestions(d);

    for (i = 0; i < n_questions; i++){
      info_question = getDAYQuestionAtIndex(d, i);

      if(getQUserId(info_question) != -1){ //significa que a pergunta tem owner_id
        user_id = getQUserId(info_question);
        info_user = lookUsers(com, user_id);

        //averigua se o utilizador em questao faz parte dos utilizadores com mais reputacao
        flag = g_ptr_array_find(total_users, info_user, NULL);

        if (flag == 1){ //significa que se trata de uma question feita por um dos N users com mais rep
          all_tags = getTags(info_question);

          //separar as tags e atualiza na hashtable o numero de ocorrencias
          tag_length = strlen(all_tags);

          for(int letra = 0; letra < tag_length; letra++){
            char * tag = separaTags(all_tags + letra);

            info_tag = lookTag(com, tag);
            incrementTagValue(info_tag);

            if(getTagValue(info_tag) == 1){
              g_ptr_array_add(total_tags, info_tag);
              sizePTRarray_tags++;
            }

            letra += strlen(tag) + 1;
          }
        }
      }
    }
    count_day++; n_days--;
  }

  sortTags(total_tags);

  if (N > sizePTRarray_tags) N = sizePTRarray_tags;

  if(info_tag != NULL){

    for(i = 0; i < N; i++){
      info_tag = g_ptr_array_index(total_tags, i);

      if (info_tag != NULL){
        tag_id = getTagId(info_tag);
        set_list(ll, i, tag_id);
      }
    }
  }


  //serve para voltar a por o value a 0 na estrutura original das tags
  for(i = 0; i < sizePTRarray_tags; i++){
    info_tag = g_ptr_array_index(total_tags, i);

    if (info_tag != NULL){
      setTagValue(info_tag, 0);
    }
  }

  return ll;
}
