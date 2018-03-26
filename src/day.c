#include <gmodule.h>
#include <stdlib.h>
#include <string.h>

#include "day.h"



/*
Estrutura que armazena informação relativa a uma data, a quantidade de
perguntas e respostas e os arrays com as mesmas, publicadas nessa data.
*/
typedef struct day {
  int day;
  int month;
  int year;
  int n_questions;
  int n_answers;
  GPtrArray * questions;
  GPtrArray * answers;
} day;

/*
Função que devolve o tamanho da estrutura day.
*/
int sizeDay() {
    return sizeof(struct day);
}

/*
Função que devolve um dia
*/
int getDay(Day d) {
    return d->day;
}

/*
Função que estabelece um dia.
*/
void setDay(Day d, int newDay) {
    d->day = newDay;
}

/*
Função que devolve o mês.
*/
int getMonth(Day d) {
    return d->month;
}

/*
Função que estabelece o mês.
*/
void setMonth(Day d, int newMonth) {
    d->month = newMonth;
}

/*
Função que devolve o ano.
*/
int getYear(Day d) {
    return d->year;
}

/*
Função que estabelece o ano.
*/
void setYear(Day d, int newYear) {
    d->year = newYear;
}

/*
Função que devolve o número de perguntas num dia.
*/
int getDAYNQuestions(Day d) {
    return d->n_questions;
}

/*
Função que estabelece o número de perguntas feitas num dia.
*/
void setDAYNQuestions(Day d, int n_questions) {
    d->n_questions = n_questions;
}

/*
Função que devolve o número de resposta num dia.
*/
int getDAYNAnswers(Day d) {
    return d->n_answers;
}

/*
Função que estabelece o número de respostas feitas num dia.
*/
void setDAYNAnswers(Day d, int n_answers) {
    d->n_answers = n_answers;
}

/*
Função que inicializa o GPtrArray answers, bem como número de respotas a zero.
*/
void initDAYAnswers(Day d) {
    d->n_answers = 0;
    d->answers = g_ptr_array_new();
}

/*
Função que adiciona uma resposta ao GPtrArray answers
e incrementa o número de respostas.
*/
void addDAYAnswers(Day d, Answers a) {
    d->n_answers++;
    g_ptr_array_add(d->answers, a);
}

/*
Função que inicializa o GPtrArray questions, bem como número de perguntas a zero.
*/
void initDAYQuestions(Day d) {
    d->n_questions = 0;
    d->questions = g_ptr_array_new();
}

/*
Função que adiciona uma pergunta ao GPtrArray questions
e incrementa o número de perguntas.
*/
void addDAYQuestions(Day d, Questions q) {
    d->n_questions++;
    g_ptr_array_add(d->questions, q);
}
/*
static void printQuestion(Questions q) {
    printf("%ld\n", getQuestionId(q));
}
//
void getDAYQuestion(Day d) {
    g_ptr_array_foreach(d->questions, (GFunc)printQuestion, NULL);
}
//
static void printAnswer(Answers a) {
    printf("%ld\n", getAnswerId(a));
}
//
void getDAYAnswer(Day d) {
    g_ptr_array_foreach(d->answers, (GFunc)printAnswer, NULL);
}
*/


/*
Função que devolve um apontador para uma resposta que se encontra
em determinado índice do GPtrArray answers.
*/
Answers getDAYAnswerAtIndex(Day d, int index) {
    return g_ptr_array_index(d->answers, index);
}

/*
Função que devolve um apontador para uma pergunta que se encontra
em determinado índice do GPtrArray questions.
*/
Questions getDAYQuestionAtIndex(Day d, int index) {
    return g_ptr_array_index(d->questions, index);
}
