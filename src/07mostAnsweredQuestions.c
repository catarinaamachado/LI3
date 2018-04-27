#include <gmodule.h>
#include <stdlib.h>
#include <stdio.h>

#include "struct.h"

/**
@file 07mostAnsweredQuestions.c
Resposta à interrogação 7.
*/

/**
\brief Função que verifica se uma determinada pergunta existe no nosso array.
@param q1 Apontador para questions.
@param q2 Apontador para questions.
@returns gboolean - 1 se a pergunta existe, 0 caso contrário.
*/
static gboolean existQuestion(Questions q1, Questions q2) {
  long id1, id2;

  if ((q1) != NULL){
    id1 = getQuestionId(q1);
  }
  else
    id1 = -1;

  if ((q2) != NULL)
    id2 = getQuestionId(q2);
  else
    id2 = -2;

  if(id1 == id2)
    return 1;
  else
    return 0;
}

/**
\brief Dado um intervalo de tempo arbitrário,
devolve os IDs das N perguntas com mais respostas,
em ordem decrescente do número de respostas.
@param com Apontador para a TCD_community.
@param N Número de perguntas pretendidas.
@param begin Data inicial do intervalo de tempo.
@param end Data final do intervalo de tempo.
@returns LONG_list - IDs das N perguntas com mais respostas,
em ordem decrescente do número de respostas.
*/
LONG_list most_answered_questions(TAD_community com, int N, Date begin, Date end) {
  int capacity = 10;
  int used = 0;
  int *list = (int *) malloc(sizeof(int) * capacity);

  int n_days, count_day, n_questions, n_answers, parentID;
  int i, sizeTQ = 0;
  long question_id;
  guint index;

  GDate * begin_stackOverflow = g_date_new_dmy (15, 9, 2008);
  GDate * beginDate = g_date_new_dmy(get_day(begin), get_month(begin), get_year(begin));
  GDate * endDate = g_date_new_dmy(get_day(end), get_month(end), get_year(end));

  n_days = g_date_days_between(beginDate, endDate);
  count_day = g_date_days_between(begin_stackOverflow, beginDate);

  int n_days_aux = n_days;
  int count_day_aux = count_day;

  GPtrArray * total_questions = g_ptr_array_sized_new(N);
  Questions info_question;
  Answers info_answer;

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

  //vê se as answers da question aparecem naquele intervalo de tempo
  while(n_days_aux >= 0){
    Day d = lookDay(com, count_day_aux);
    n_answers = getDAYNAnswers(d);

    for (i = 0; i < n_answers; i++){
      info_answer = getDAYAnswerAtIndex(d, i);
      parentID = getParentId(info_answer);

      Questions data = malloc(sizeQuestions());
      setQuestionId(data, parentID);

      int flag = g_ptr_array_find_with_equal_func(total_questions, data, (GEqualFunc)existQuestion, &index);
      //se a resposta é resposta de alguma das perguntas que apareceram
      if(flag == 1){
        info_question = g_ptr_array_index(total_questions, index);
        setN_answers_date(info_question, getN_answers_date(info_question) + 1);
      }

      free(data);
    }

    count_day_aux++; n_days_aux--;
  }

  sortMoreAnswers(total_questions);

  if (N > sizeTQ)
    N = sizeTQ;

  for(i = 0; ((i < N) && (info_question != NULL)); i++){
    info_question = g_ptr_array_index(total_questions, i);
    if (info_question != NULL){
      question_id = getQuestionId(info_question);
      setN_answers_date(info_question, 0);
      if(used == capacity){
        capacity *= 2;
        list = (int *) realloc(list, sizeof(int) * capacity);
      }
      list[used] = question_id;
      used++;
    }
  }

  LONG_list ll = create_list(used);

  for(sizeTQ = 0; sizeTQ < used; sizeTQ++){
    set_list(ll, sizeTQ, list[sizeTQ]);
  }

  //serve para voltar a por o n_answers_date a 0 na estrutura original das questions
  for(i = N; i < sizeTQ; i++){
    info_question = g_ptr_array_index(total_questions, i);

    if (info_question != NULL){
      setN_answers_date(info_question, 0);
    }
  }


  g_date_free(begin_stackOverflow);
  g_date_free(beginDate);
  g_date_free(endDate);
  free(list);
  g_ptr_array_free(total_questions, TRUE);

  return ll;
}
