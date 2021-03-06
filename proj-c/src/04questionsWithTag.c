#include <gmodule.h>
#include <string.h>
#include <stdlib.h>

#include "struct.h"

/**
@file 04questionsWithTag.c
Resposta à interrogação 4.
*/

/**
\brief Dado um intervalo de tempo arbitrário,
retorna todas as perguntas contendo uma determinada tag.
O retorno da função deverá ser uma lista com os IDs das perguntas
ordenadas em cronologia inversa.
@param com Apontador para a TCD_community.
@param tag Tag que procuramos nas perguntas.
@param begin Data inicial do intervalo de tempo.
@param end Data final do intervalo de tempo.
@returns LONG_list - IDs das perguntas
ordenadas em cronologia inversa.
*/
LONG_list questions_with_tag(TAD_community com, char* tag, Date begin, Date end) {
  int capacity = 10;
  int used = 0;
  int *list = (int *) malloc(sizeof(int) * capacity);

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
        if(used == capacity){
          capacity *= 2;
          list = (int *) realloc(list, sizeof(int) * capacity);
        }
        list[used] = question_id;
        used++;
      }
      free(dayTags);
    }
    count_day--; n_days--;
  }

  LONG_list ll = create_list(used);

  for(index_ll = 0; index_ll < used; index_ll++){
    set_list(ll, index_ll, list[index_ll]);
  }

  free(list);
  g_date_free(begin_stackOverflow);
  g_date_free(beginDate);
  g_date_free(endDate);

  return ll;
}
