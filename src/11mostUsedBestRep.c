#include <gmodule.h>
#include <string.h>
#include <stdlib.h>
#include <stdlib.h>

#include "struct.h"

/**
@file 11mostUsedBestRep.c
Resposta à interrogação 11.
*/

/**
\brief Função que devolve a primeira tag (individual)
do conjunto de tags passado como argumento.
@param all_tags Palavra com todas as tags de uma pergunta.
@returns char * - Primeira tag presente na palavra passada
como argumento.
*/
char * separaTags(char * all_tags) {
  char * token;
  token = strtok(all_tags, "><");

  return token;
}


/**
\brief Dado um intervalo arbitrário de tempo,
devolve as N tags mais usadas pelos N utilizadores com melhor reputação.
Em ordem decrescente do número de vezes em que a tag foi usada.
@param com Apontador para a TCD_community.
@param N Número de perguntas pretendidas.
@param begin Data inicial do intervalo de tempo.
@param end Data final do intervalo de tempo.
@returns LONG_list - IDs das N perguntas com mais respostas,
em ordem decrescente do número de respostas
*/
LONG_list most_used_best_rep(TAD_community com, int N, Date begin, Date end) {
  int capacity = 10;
  int used = 0;
  int *list = (int *) malloc(sizeof(int) * capacity);

  int n_days, count_day, n_questions, i, flag;
  long user_id, tag_id;
  int sizePTRarray_users = 0;
  int tag_length, sizePTRarray_tags = 0;
  char * all_tags = NULL;

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


  //descobrir os N utilizadores com maior reputação
  while(n_days >= 0){
    Day d = lookDay(com, count_day);
    n_questions = getDAYNQuestions(d);

    for (i = 0; i < n_questions; i++){
      info_question = getDAYQuestionAtIndex(d, i);

      user_id = getQUserId(info_question);
      info_user = lookUsers(com, user_id);

      //averigua se o utilizador que fez essa question já se encontra ou não no GPtrArray total_users
      flag = g_ptr_array_find(total_users, info_user, NULL);
      if (flag != 1){
        g_ptr_array_add(total_users, info_user);
        sizePTRarray_users++;
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

        free(all_tags);
      }
    }
    count_day++; n_days--;
  }


  sortTags(total_tags);

  if (N > sizePTRarray_tags)
    N = sizePTRarray_tags;

  //escrever na long list as referências das N tags
  if(info_tag != NULL){

    for(i = 0; i < N; i++){
      info_tag = g_ptr_array_index(total_tags, i);

      if (info_tag != NULL){
        tag_id = getTagId(info_tag);

        if(used == capacity){
          capacity *= 2;
          list = (int *) realloc(list, sizeof(int) * capacity);
        }
        list[used] = tag_id;
        used++;
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

  LONG_list ll = create_list(used);

  for(sizePTRarray_tags = 0; sizePTRarray_tags < used; sizePTRarray_tags++){
    set_list(ll, sizePTRarray_tags, list[sizePTRarray_tags]);
  }

  free(list);
  g_date_free(begin_stackOverflow);
  g_date_free(beginDate);
  g_date_free(endDate);
  g_ptr_array_free(total_tags, TRUE);
  g_ptr_array_free(total_users, TRUE);

  return ll;
}
