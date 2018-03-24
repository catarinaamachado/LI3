#include <gmodule.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "questions.h"
#include "postDate.h"

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


int sizeQuestions() {
    return sizeof(struct questions);
}

// devolve o id da pergunta
long getQuestionId(Questions q) {
    return q->post_id;
}

//Estabelece o o id da pergunta
void setQuestionId(Questions q, long id) {
    q->post_id = id;
}

//Estabelece a data da pergunta
void setQDate(Questions q, char * date) {
    q->pd = malloc(getPDSize());

    setDate(q->pd, date);
}

//devolve a data da pergunta
char * getQDate(Questions q) {
    char * date = malloc(sizeof(char) * 12);

    sprintf(date, "%d:%d:%d", getPDYear(q->pd), getPDMonth(q->pd), getPDDay(q->pd));

    return date;
}

//devolve o id do utilizador
long getQUserId(Questions q) {
    return q->user_id;
}

//Estabelece o id do utilizador
void setQUserId(Questions q, long id) {
    q->user_id = id;
}

//Devovle o título de uma pergunta
char * getTitle(Questions q) {
    char * title = malloc(sizeof(char) * (strlen(q->title)+2));
    strcpy(title, q->title);

    return title;
}


//Estabelece o título de uma pergunta
void setTitle(Questions q, char * t) {
    if(t == NULL) {
        q->title = malloc(sizeof(char));
        strcpy(q->title, "\n");
    }
    else {
        char * title = malloc(sizeof(char) * (strlen(t)+2));
        strcpy(title, t);

        q->title = title;
    }
}

//Devolve a(s) tag(s) de uma pergunta
char * getTags(Questions q) {
    char * tags = malloc(sizeof(char) * (strlen(q->tags)+2));
    strcpy(tags, q->tags);

    return tags;
}

//Estabelece a(s) tag(s) de uma pergunta
void setTags(Questions q, char * t) {
    if(t == NULL) {
        q->tags = malloc(sizeof(char));
        strcpy(q->tags, "\n");
    }
    else {
        char * tags = malloc(sizeof(char) * (strlen(t)+2));
        strcpy(tags, t);

        q->tags = tags;
    }
}

//Devovle o número de respostas associadas a determinada pergunta
int getNAnswers(Questions q) {
    return q->n_answers;
}

//Estabelece o número de respostas associadas a determinada pergunta
void setNAnswers(Questions q, int n) {
    q->n_answers = n;
}

int getNAnswerVotes(Questions q) {
    return q->n_answer_votes;
}

void setNAnswerVotes(Questions q, int n) {
    q->n_answer_votes = n;
}

// cria um novo GPtrArray com as respostas de determinada pergunta
void initAnswers(Questions q) {
    q->answers = g_ptr_array_sized_new(q->n_answers);
}

//Adiciona uma resposta ao GPtrArray Answers
void addAnswers(Questions q, Answers a) {
    g_ptr_array_add(q->answers, a);
}

/* Devolve o id do utilizador que deu a resposta contida no GPtrArray,
mais precisamente no índice do array dado pela variável index
*/
long getAnswerUserIdAtIndex(Questions q, int index) {
    return getAUserId(g_ptr_array_index(q->answers, index));
}

//
int getAnswerScoreAtIndex(Questions q, int index) {
   return getScore(g_ptr_array_index(q->answers, index));
}

//
int getAnswerFavoriteAtIndex(Questions q, int index) {
   return getFavoriteCount(g_ptr_array_index(q->answers, index));
}

//
int getAnswerCommentAtIndex(Questions q, int index) {
   return getCommentCount(g_ptr_array_index(q->answers, index));
}

//
int getAnswerIdAtIndex(Questions q, int index) {
   return getAnswerId(g_ptr_array_index(q->answers, index));
}


// Ordena as perguntas por data
gint sortQDate (Questions aq, Questions bq) {
    postDate a = aq->pd;
    postDate b = bq->pd;

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

//query 7
static gint sortPlusAnswers(Questions * q1, Questions * q2) {
  int nAnswers_q1 = 0, nAnswers_q2 = 0;
  nAnswers_q1 = getNAnswers(*q1);
  nAnswers_q2 = getNAnswers(*q2);

    if(nAnswers_q1 < nAnswers_q2)
      return 1;
    else
      return -1;
}

//query 7
void sortMoreAnswers(GPtrArray * total_questions) {
  g_ptr_array_sort(total_questions, (GCompareFunc)sortPlusAnswers);
}
