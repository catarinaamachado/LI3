#include <gmodule.h>

#include "struct.h"

/*
Dado um intervalo de tempo arbitrário,
devolver os IDs das N respostas com mais votos,
em ordem decrescente do número de votos
*/

LONG_list most_voted_answers(TAD_community com, int N, Date begin, Date end) {
  LONG_list ll = create_list(1);
  int n_days, count_day, n_answers, answer_id, i, sizeTA = 0;;

  GDate * begin_stackOverflow = g_date_new_dmy (15, 9, 2008);
  GDate * beginDate = g_date_new_dmy(get_day(begin), get_month(begin), get_year(begin));
  GDate * endDate = g_date_new_dmy(get_day(end), get_month(end), get_year(end));

  n_days = g_date_days_between(beginDate, endDate);
  count_day = g_date_days_between(begin_stackOverflow, beginDate);

  GPtrArray * total_answers = g_ptr_array_new();
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

  if (N > sizeTA) N = sizeTA;

  for(i = 0; ((i < N) && (info_answer != NULL)); i++){
    info_answer = g_ptr_array_index(total_answers, i);
    if (info_answer != NULL){
      answer_id = getAnswerId(info_answer);
      set_list(ll, i, answer_id);
    }
  }

  return ll;
}
