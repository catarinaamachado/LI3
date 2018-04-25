#ifndef __QUESTIONS__
#define __QUESTIONS__


#include <gmodule.h>

#include "interface.h"
#include "users.h"
#include "answers.h"

typedef struct questions * Questions;

int sizeQuestions();

long getQuestionId(Questions q);

void setQuestionId(Questions q, long id);

char * getQDate(Questions q);

void setQDate(Questions q, char * date);

long getQUserId(Questions q);

void setQUserId(Questions q, long id);

char * getTitle(Questions q);

void setTitle(Questions q, char * t);

char * getTags(Questions q);

void setTags(Questions q, char * t);

int getNAnswers(Questions q);

void setNAnswers(Questions q, int n);

int getN_answers_date(Questions q);

void setN_answers_date(Questions q, int n);

int getNAnswerVotes(Questions q);

void setNAnswerVotes(Questions q, int n);

void initAnswers(Questions q);

void addAnswers(Questions q, Answers a);

long getAnswerUserIdAtIndex(Questions q, int index);

int getAnswerScoreAtIndex(Questions q, int index);

int getAnswerCommentAtIndex(Questions q, int index);

int getAnswersArraySize(Questions q);

Answers getAnswerAtIndex(Questions q, int index);

gint sortQDate(Questions aq, Questions bq);

void sortMoreAnswers(GPtrArray * total_questions);

void cleanQuestion(Questions q);

#endif
