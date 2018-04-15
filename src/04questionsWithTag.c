#include <gmodule.h>
#include <string.h>

#include "struct.h"


/*
Dado um intervalo de tempo arbitrário,
retornar todas as perguntas contendo uma determinada tag.
O retorno da função deverá ser uma lista com os IDs das perguntas ordenadas em cronologia inversa
*/

LONG_list questions_with_tag(TAD_community com, char* tag, Date begin, Date end) {
  LONG_list ll = create_list(1);
  int n_days, count_day, n_questions, i, index_ll = 0;
  long question_id;
  char * dayTags;

  GDate * begin_stackOverflow = g_date_new_dmy (15, 9, 2008);
  GDate * beginDate = g_date_new_dmy(get_day(begin), get_month(begin), get_year(begin));
  GDate * endDate = g_date_new_dmy(get_day(end), get_month(end), get_year(end));

  n_days = g_date_days_between(beginDate, endDate);
  count_day = g_date_days_between(begin_stackOverflow, endDate);

  while(n_days >= 0){
    Day d = lookDay(com, count_day);
    n_questions = getDAYNQuestions(d);

    for (i = 0; i < n_questions; i++){
      Questions day_question = getDAYQuestionAtIndex(d, i);
      dayTags = getTags(day_question);

      if(strstr(dayTags, tag)){
        question_id = getQuestionId(day_question);
        set_list(ll, index_ll, question_id);
        index_ll++;
      }
    }

    count_day--; n_days--;
  }

  return ll;
}
