#include <gmodule.h>
#include <stdlib.h>

#include "struct.h"

/**
@file 06mostVotedAnswers.c
Resposta à interrogação 6.
*/

/**
\brief Dado um intervalo de tempo arbitrário,
devolve os IDs das N respostas com mais votos,
em ordem decrescente do número de votos.
@param com Estrutura dos dados.
@param N Número de perguntas pretendidas.
@param begin Data inicial do intervalo de tempo.
@param end Data final do intervalo de tempo.
@returns LONG_list - IDs das N respostas com mais votos,
em ordem decrescente do número de votos.
*/
LONG_list most_voted_answers(TAD_community com, int N, Date begin, Date end) {
  int capacity = 10;
  int used = 0;
  int *list = (int *) malloc(sizeof(int) * capacity);

  int n_days, count_day, n_answers, i, sizeTA = 0;;
  long answer_id;

  GDate * begin_stackOverflow = g_date_new_dmy (15, 9, 2008);
  GDate * beginDate = g_date_new_dmy(get_day(begin), get_month(begin), get_year(begin));
  GDate * endDate = g_date_new_dmy(get_day(end), get_month(end), get_year(end));

  n_days = g_date_days_between(beginDate, endDate);
  count_day = g_date_days_between(begin_stackOverflow, beginDate);

  GPtrArray * total_answers = g_ptr_array_sized_new(N);
  Answers info_answer;

  while(n_days >= 0){
    Day d = lookDay(com, count_day);
    n_answers = getDAYNAnswers(d);
    sizeTA += n_answers;

    for (i = 0; i < n_answers; i++){
      info_answer = getDAYAnswerAtIndex(d, i);
      g_ptr_array_add(total_answers, info_answer);
    }

    count_day++; n_days--;
  }

  sortAnswersVotes(total_answers);

  if (N > sizeTA)
    N = sizeTA;

  for(i = 0; ((i < N) && (info_answer != NULL)); i++){
    info_answer = g_ptr_array_index(total_answers, i);
    if (info_answer != NULL){
      answer_id = getAnswerId(info_answer);
      if(used == capacity){
        capacity *= 2;
        list = (int *) realloc(list, sizeof(int) * capacity);
      }
      list[used] = answer_id;
      used++;
    }
  }

  g_date_free(begin_stackOverflow);
  g_date_free(beginDate);
  g_date_free(endDate);

  LONG_list ll = create_list(used);

  for(sizeTA = 0; sizeTA < used; sizeTA++){
    set_list(ll, sizeTA, list[sizeTA]);
  }

  free(list);
  g_ptr_array_free(total_answers, TRUE);

  return ll;
}
