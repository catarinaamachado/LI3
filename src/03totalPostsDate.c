#include "struct.h"

/**
@file 03totalPostsDate.c
Resposta à interrogação 3.
*/

/**
\brief Dado um intervalo de tempo arbitrário,
obtem o número total de posts
(identificando perguntas e respostas separadamente) neste período.
@param com Estrutura dos dados.
@param begin Data inicial do intervalo de tempo.
@param end Data final do intervalo de tempo.
@returns LONG_pair - Número total de perguntas e número total de respostas
encontradas.
*/
LONG_pair total_posts(TAD_community com, Date begin, Date end) {
  LONG_pair total_QA = create_long_pair(0, 0);
  long n_questions = 0, n_answers = 0;
  int n_days, count_day;

  GDate * begin_stackOverflow = g_date_new_dmy (15, 9, 2008);
  GDate * beginDate = g_date_new_dmy(get_day(begin), get_month(begin), get_year(begin));
  GDate * endDate = g_date_new_dmy(get_day(end), get_month(end), get_year(end));

  n_days = g_date_days_between(beginDate, endDate);
  count_day = g_date_days_between(begin_stackOverflow, beginDate);

  while(n_days >= 0){
    n_questions += getDAYNQuestions(lookDay(com, count_day));
    n_answers += getDAYNAnswers(lookDay(com, count_day));
    count_day++; n_days--;
  }

  set_fst_long(total_QA, n_questions);
  set_snd_long(total_QA, n_answers);

  g_date_free(begin_stackOverflow);
  g_date_free(beginDate);
  g_date_free(endDate);

  return total_QA;
}
