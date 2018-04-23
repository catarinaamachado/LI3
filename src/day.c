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


/**
\brief Função que devolve o tamanho da estrutura day.
@returns int - Tamanho da estrutura day.
*/
int sizeDay() {
    return sizeof(struct day);
}

/**
\brief Função que devolve um dia.
@returns int - Dia.
*/
int getDay(Day d) {
    return d->day;
}

/**
\brief Função que estabelece um dia.
@param d Dia em questão.
@param newDay Novo dia.
*/
void setDay(Day d, int newDay) {
    d->day = newDay;
}

/**
\brief Função que devolve o mês.
@returns int - Mês.
*/
int getMonth(Day d) {
    return d->month;
}

/**
\brief Função que estabelece o mês.
@param d Dia em questão.
@param newMonth Novo mês.
*/
void setMonth(Day d, int newMonth) {
    d->month = newMonth;
}

/**
\brief Função que devolve o ano.
@returns int - Ano.
*/
int getYear(Day d) {
    return d->year;
}

/**
\brief Função que estabelece o ano.
@param d Dia em questão.
@param newYear Novo ano.
*/
void setYear(Day d, int newYear) {
    d->year = newYear;
}

/**
\brief Função que devolve o número de perguntas num dia.
@param d Dia em questão.
@returns int - Número de perguntas.
*/
int getDAYNQuestions(Day d) {
    return d->n_questions;
}

/**
\brief Função que estabelece o número de perguntas feitas num dia.
@param d Dia em questão.
@param n_questions Número de perguntas.
*/
void setDAYNQuestions(Day d, int n_questions) {
    d->n_questions = n_questions;
}

/**
\brief Função que devolve o número de respostas num dia.
@param d Dia em questão.
@returns int - Número de respostas.
*/
int getDAYNAnswers(Day d) {
    return d->n_answers;
}

/**
\brief Função que estabelece o número de respostas feitas num dia.
@param d Dia em questão.
@param n_answers Número de respostas.
*/
void setDAYNAnswers(Day d, int n_answers) {
    d->n_answers = n_answers;
}

/**
\brief Função que inicializa o GPtrArray answers, bem como número de respostas a zero.
@param d Dia em questão.
*/
void initDAYAnswers(Day d) {
    d->n_answers = 0;
    d->answers = g_ptr_array_new();
}

/**
\brief Função que adiciona uma resposta ao GPtrArray answers
e incrementa o número de respostas.
@param d Dia em questão.
@param a Nova resposta.
*/
void addDAYAnswers(Day d, Answers a) {
    d->n_answers++;
    g_ptr_array_add(d->answers, a);
}

/**
\brief Função que inicializa o GPtrArray questions, bem como número de perguntas a zero.
@param d Dia em questão.
*/
void initDAYQuestions(Day d) {
    d->n_questions = 0;
    d->questions = g_ptr_array_new();
}

/**
\brief Função que adiciona uma pergunta ao GPtrArray questions
e incrementa o número de perguntas.
@param d Dia em questão.
@param q Nova pergunta.
*/
void addDAYQuestions(Day d, Questions q) {
    d->n_questions++;
    g_ptr_array_add(d->questions, q);
}

/**
\brief Função que devolve um apontador para uma resposta que se encontra
em determinado índice do GPtrArray answers.
@param d Dia em questão.
@param index Índice onde se encontra a resposta.
@param Answers - Resposta.
*/
Answers getDAYAnswerAtIndex(Day d, int index) {
    return g_ptr_array_index(d->answers, index);
}

/**
\brief Função que devolve um apontador para uma pergunta que se encontra
em determinado índice do GPtrArray questions.
@param d Dia em questão.
@param index Índice onde se encontra a pergutna.
@param Questions - Pergunta.
*/
Questions getDAYQuestionAtIndex(Day d, int index) {
    return g_ptr_array_index(d->questions, index);
}

/**
\brief Função que limpa a memória alocada para as perguntas e respostas.
@param d Dia em questão.
*/
void cleanDay(Day d) {
    if (d != NULL) {
        g_ptr_array_free(d->questions, TRUE);

        g_ptr_array_free(d->answers, TRUE);

        free(d);
    }
}
