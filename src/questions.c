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
  char * tags; //TODO: funcao que separa a string com as todas tags num array de strings
  int n_answers;
  int n_answer_votes;
  GPtrArray * answers;
} questions;

int sizeQuestions() {
    return sizeof(struct questions);
}

long getQuestionId(Questions q) {
    return q->post_id;
}

void setQuestionId(Questions q, long id) {
    q->post_id = id;
}

void setQDate(Questions q, char * date) {
    q->pd = malloc(getPDSize());

    setDate(q->pd, date);
}

char * getQDate(Questions q) {
    char * date = malloc(sizeof(char) * 12);

    sprintf(date, "%d:%d:%d", getPDYear(q->pd), getPDMonth(q->pd), getPDDay(q->pd));

    return date;
}

long getQUserId(Questions q) {
    return q->user_id;
}

void setQUserId(Questions q, long id) {
    q->user_id = id;
}

char * getTitle(Questions q) {
    char * title = malloc(sizeof(char) * (strlen(q->title)+2));
    strcpy(title, q->title);

    return title;
}

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

char * getTags(Questions q) {
    char * tags = malloc(sizeof(char) * (strlen(q->tags)+2));
    strcpy(tags, q->tags);

    return tags;
}

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

int getNAnswers(Questions q) {
    return q->n_answers;
}

void setNAnswers(Questions q, int n) {
    q->n_answers = n;
}

int getNAnswerVotes(Questions q) {
    return q->n_answer_votes;
}

void setNAnswerVotes(Questions q, int n) {
    q->n_answer_votes = n;
}

void initAnswers(Questions q) {
    q->answers = g_ptr_array_sized_new(q->n_answers);
}

void addAnswers(Questions q, Answers a) {
    g_ptr_array_add(q->answers, a);
}

long getAnswerUserIdAtIndex(Questions q, int index) {
    return getAUserId(g_ptr_array_index(q->answers, index));
}

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