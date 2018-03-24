#include <gmodule.h>

#include "struct.h"

/*
Dado um intervalo de tempo arbitrário,
devolver as IDs das N perguntas com mais respostas,
em ordem decrescente do número de respostas
*/

LONG_list most_answered_questions(TAD_community com, int N, Date begin, Date end) {
  LONG_list ll = create_list(1);
  int n_days, count_day, n_questions, question_id, i, sizeTQ = 0;

  GDate * begin_stackOverflow = g_date_new_dmy (15, 9, 2008);
  GDate * beginDate = g_date_new_dmy(get_day(begin), get_month(begin), get_year(begin));
  GDate * endDate = g_date_new_dmy(get_day(end), get_month(end), get_year(end));

  n_days = g_date_days_between(beginDate, endDate);
  count_day = g_date_days_between(begin_stackOverflow, beginDate);

  GPtrArray * total_questions = g_ptr_array_new();
  Questions info_question;

  while(n_days >= 0){
    Day d = lookDay(com, count_day);
    n_questions = getDAYNQuestions(d);
    sizeTQ += n_questions;

    for (i = 0; i < n_questions; i++){
      info_question = getDAYQuestionAtIndex(d, i);
      g_ptr_array_add(total_questions, info_question);
    }

    count_day++; n_days--;
  }

  sortMoreAnswers(total_questions);

  if (N > sizeTQ) N = sizeTQ;

  for(i = 0; ((i < N) && (info_question != NULL)); i++){
    info_question = g_ptr_array_index(total_questions, i);
    if (info_question != NULL){
      question_id = getQuestionId(info_question);
      set_list(ll, i, question_id);
    }
  }

  return ll;
}
