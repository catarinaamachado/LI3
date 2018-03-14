#include <gmodule.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct questions {
  long post_id;
  long user_id;
  char * title;
  char * tags; //TODO: funcao que separa a string com as todas tags num array de strings
  int n_answers;
  int n_answer_votes;
  GPtrArray * answers;
} Questions;

long getQuestionId(Questions * q) {
    return q->post_id;
}

void setQuestionId(Questions * q, long id) {
    q->post_id = id;
}

long getQUserId(Questions * q) {
    return q->user_id;
}

void setQUserId(Questions * q, long id) {
    q->user_id = id;
}

char * getTitle(Questions * q) {
    char * title = malloc(sizeof(char) * strlen(q->title));
    strcpy(title, q->title);

    return title;
}

void setTitle(Questions * q, char * t) {
    char * title = malloc(sizeof(char) * strlen(t));
    strcpy(title, t);

    q->title = title;
}

char * getTags(Questions * q) {
    char * title = malloc(sizeof(char) * strlen(q->tags));
    strcpy(title, q->title);

    return title;
}

void setTags(Questions * q, char * t) {
    char * tags = malloc(sizeof(char) * strlen(t));
    strcpy(tags, t);

    q->tags = tags;
}

int getNAnswers(Questions * q) {
    return q->n_answers;
}

void setNAnswers(Questions * q, int n) {
    q->n_answers = n;
}

int getNAnswerVotes(Questions * q) {
    return q->n_answer_votes;
}

void setNAnswerVotes(Questions * q, int n) {
    q->n_answer_votes = n;
}

GPtrArray * getAnswers(Questions * q) { //FIXME:
    return q->answers;
}

void setAnswers(Questions * q, GPtrArray * p) { //FIXME:
    q->answers = p;
}