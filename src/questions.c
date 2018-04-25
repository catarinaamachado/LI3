#include <gmodule.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "questions.h"
#include "postDate.h"

/**
@file questions.c
Estrutura de dados relativa às perguntas, respetivos
getters e setters e funções auxiliares necessárias.
*/

/**
\brief Estrutura que guarda a informação considerada relevante das perguntas.
*/
typedef struct questions {
  long post_id;
  postDate pd;
  long user_id;
  char * title;
  char * tags;
  int n_answers;
  int n_answer_votes;
  GPtrArray * answers;
} questions;

/**
\brief Função que devolve o tamanho da estrutura questions.
@returns int - Tamanho da estrutura questions.
*/
int sizeQuestions() {
    return sizeof(struct questions);
}

/**
\brief Função que devolve o id da pergunta.
@param q Apontador para questions.
@returns long - Identificador da pergunta.
*/
long getQuestionId(Questions q) {
    return q->post_id;
}

/**
\brief Função que estabelece o o id da pergunta.
@param q Apontador para questions.
@param id Identificador da pergunta.
*/
void setQuestionId(Questions q, long id) {
    q->post_id = id;
}

/**
\brief Função que estabelece a data da pergunta.
@param q Apontador para questions.
@param date A data da pergunta em formato string.
*/
void setQDate(Questions q, char * date) {
    if(date == 0)
        q->pd = NULL;
    else {
        q->pd = malloc(getPDSize());
        setDate(q->pd, date);
    }
}

/**
\brief Função que devolve a data da pergunta.
@param q Apontador para questions.
@returns char * - A data da pergunta em formato string.
*/
char * getQDate(Questions q) {
    char * date = malloc(sizeof(char) * 12);

    sprintf(date, "%d:%d:%d", getPDYear(q->pd), getPDMonth(q->pd), getPDDay(q->pd));

    return date;
}

/**
\brief Função que devolve o id do utilizador.
@param q Apontador para questions.
@returns long - Identificador do user.
*/
long getQUserId(Questions q) {
    return q->user_id;
}

/**
\brief Função que estabelece o id do utilizador.
@param q Apontador para questions.
@param id Identificador do user.
*/
void setQUserId(Questions q, long id) {
    q->user_id = id;
}

/**
\brief Função que devolve o título de uma pergunta.
@param q Apontador para questions.
@returns char * -  Título da pergunta.
*/
char * getTitle(Questions q) {
    char * title = NULL;

    if(q->title != NULL) {
      title = malloc(sizeof(char) * (strlen(q->title)+2));
      strcpy(title, q->title);
    }

    return title;
}

/**
\brief Função que estabelece o título de uma pergunta.
@param q Apontador para questions.
@param t Título.
*/
void setTitle(Questions q, char * t) {
    if(t == NULL)
        q->title = NULL;
    else {
        char * title = malloc(sizeof(char) * (strlen(t)+4));
        strcpy(title, t);

        q->title = title;
    }
}

/**
\brief Função que devolve a(s) tag(s) de uma pergunta.
@param q Apontador para questions.
@returns char * -  Tags da pergunta.
*/
char * getTags(Questions q) {
    char * tags = malloc(sizeof(char) * (strlen(q->tags)+2));
    strcpy(tags, q->tags);

    return tags;
}

/**
\brief Função que estabelece a(s) tag(s) de uma pergunta.
@param q Apontador para questions.
@param t Tags da pergunta.
*/
void setTags(Questions q, char * t) {
    if(t == NULL)
        q->tags = NULL;
    else {
        char * tags = malloc(sizeof(char) * (strlen(t)+4));
        strcpy(tags, t);

        q->tags = tags;
    }
}

/**
\brief Função que devolve o número de respostas associadas a determinada pergunta.
@param q Apontador para questions.
@returns int -  Número de respostas.
*/
int getNAnswers(Questions q) {
    return q->n_answers;
}

/**
\brief Função que estabelece o número de respostas associadas a determinada pergunta.
@param q Apontador para questions.
@param n Número de respostas.
*/
void setNAnswers(Questions q, int n) {
    q->n_answers = n;
}

/**
\brief Função que devolve o número total de votos das respostas associadas a uma pergunta.
@param q Apontador para questions.
@returns int - Total de votos das respostas.
*/
int getNAnswerVotes(Questions q) {
    return q->n_answer_votes;
}

/**
\brief Função que estabelece o número total de votos das respostas associadas a uma pergunta.
@param q Apontador para questions.
@param n Votos das respostas.
*/
void setNAnswerVotes(Questions q, int n) {
    q->n_answer_votes = n;
}

/**
\brief Função que cria um novo GPtrArray com as respostas de determinada pergunta.
@param q Apontador para questions.
*/
void initAnswers(Questions q) {
    q->answers = g_ptr_array_sized_new(q->n_answers);
}

/**
\brief Função que adiciona uma resposta ao GPtrArray Answers.
@param q Apontador para questions.
@param a Apontador para answers.
*/
void addAnswers(Questions q, Answers a) {
    Answers new = malloc(sizeAnswers());
    memcpy(new, a, sizeAnswers());
    g_ptr_array_add(q->answers, new);
}

/**
\brief Função que devolve o id do utilizador que deu a resposta contida no GPtrArray,
mais precisamente no índice do array dado pela variável index.
@param q Apontador para questions.
@param index Índice da resposta no GPtrArray * answers.
@returns long - Identificador do user que publicou a resposta.
*/
long getAnswerUserIdAtIndex(Questions q, int index) {
    return getAUserId(g_ptr_array_index(q->answers, index));
}

/**
\brief Função que devolve o score obtido pela resposta contida no GPtrArray,
mais precisamente no índice do array dado pela variável index.
@param q Apontador para questions.
@param index Índice da resposta no GPtrArray * answers.
@returns int - Score da resposta.
*/
int getAnswerScoreAtIndex(Questions q, int index) {
   return getScore(g_ptr_array_index(q->answers, index));
}


/**
\brief Função que devolve o número de comentários obtido pela resposta contida no GPtrArray,
mais precisamente no índice do array dado pela variável index.
@param q Apontador para questions.
@param index Índice da resposta no GPtrArray * answers.
@returns int - Número de comentários da resposta.
*/
int getAnswerCommentAtIndex(Questions q, int index) {
   return getCommentCount(g_ptr_array_index(q->answers, index));
}

/**
\brief Função que devolve o id da resposta contida no GPtrArray,
mais precisamente no índice do array dado pela variável index.
@param q Apontador para questions.
@param index Índice da resposta no GPtrArray * answers.
@returns int - Identificador da resposta.
*/
int getAnswerIdAtIndex(Questions q, int index) {
   return getAnswerId(g_ptr_array_index(q->answers, index));
}

/**
\brief Função que devolve o tamanho do GPtrArray answers.
@param q Apontador para questions.
@returns int - Tamanho do GPtrArray * answers.
*/
int getAnswersArraySize(Questions q) {
  return q->answers->len;
}

/**
\brief Função que ordena as perguntas por data.
@param aq Apontador para questions.
@param bq Apontador para questions.
@returns gint - -1 se a primeira pergunta passada como parâmetro
for mais recente que a segunda ou 1 caso contrário.
*/
gint sortQDate (Questions aq, Questions bq) {
    postDate a = aq->pd;
    postDate b = bq->pd;

    if(a == NULL)
        return 1;
    if(b == NULL)
        return -1;

    if (getPDYear(a) < getPDYear(b))
        return 1;
    else if (getPDYear(a) > getPDYear(b))
        return -1;

    else if (getPDMonth(a) < getPDMonth(b))
        return 1;
    else if (getPDMonth(a) > getPDMonth(b))
        return -1;

    else if (getPDDay(a) < getPDDay(b))
        return 1;
    else if (getPDDay(a) > getPDDay(b))
        return -1;

    else if (getPDHour(a) < getPDHour(b))
        return 1;
    else if (getPDHour(a) > getPDHour(b))
        return -1;

    else if (getPDMin(a) < getPDMin(b))
        return 1;
    else if (getPDMin(a) > getPDMin(b))
        return -1;

    else if (getPDSec(a) < getPDSec(b))
        return 1;
    else if (getPDSec(a) > getPDSec(b))
        return -1;

    else if (getPDMili(a) < getPDMili(b))
        return 1;
    else if (getPDMili(a) > getPDMili(b))
        return -1;

    return 1;
}

/**
\brief Função que compara o número de respostas de duas perguntas recebidas
como parâmetro (query 7).
@param q1 Apontador para um apontador para questions.
@param q2 Apontador para um apontador para questions.
@returns gint - -1 se o número de respostas da primeira pergunta passada
como parâmetro for maior que o da segunda, ou 1 caso contrário.
*/
static gint sortPlusAnswers(Questions * q1, Questions * q2) {
  int nAnswers_q1 = 0, nAnswers_q2 = 0;
  nAnswers_q1 = getNAnswers(*q1);
  nAnswers_q2 = getNAnswers(*q2);

    if(nAnswers_q1 < nAnswers_q2)
      return 1;
    else
      return -1;
}

/**
\brief Função que ordena um array pela ordem decrescente do maior
número de respostas (query 7).
@param total_questions Apontador para GPtrArray.
*/
void sortMoreAnswers(GPtrArray * total_questions) {
  g_ptr_array_sort(total_questions, (GCompareFunc)sortPlusAnswers);
}

/**
\brief Função que liberta os espaços de memória criados para as datas, título, tags,
GPtrArray das respostas e o próprio apontador para questions.
@param q Apontador para questions.
*/
void cleanQuestion(Questions q) {
    if(q != NULL) {
        if(q->pd != NULL)
            free(q->pd);

        if(q->title != NULL)
            free(q->title);

        if(q->tags != NULL)
            free(q->tags);

        g_ptr_array_set_free_func(q->answers, (GDestroyNotify)cleanAnswer);
        g_ptr_array_free(q->answers, TRUE);

        free(q);
    }
}
