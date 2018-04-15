#include <gmodule.h>

#include "interface.h"
#include "users.h"
#include "answers.h"

typedef struct questions * Questions;

int sizeQuestions();

long getQuestionId(Questions q);

void setQuestionId(Questions q, long id);

void setQDate(Questions q, char * date);

char * getQDate(Questions q);

long getQUserId(Questions q);

void setQUserId(Questions q, long id);

char * getTitle(Questions q);

void setTitle(Questions q, char * t);

char * getTags(Questions q);

void setTags(Questions q, char * t);

int getNAnswers(Questions q);

void setNAnswers(Questions q, int n);

int getNAnswerVotes(Questions q);

void setNAnswerVotes(Questions q, int n);

GPtrArray * getAnswers(Questions q);

void setAnswers(Questions q, GPtrArray * p);

void initAnswers(Questions q);

void addAnswers(Questions q, Answers a);

long getAnswerUserIdAtIndex(Questions q, int index);

int getAnswerScoreAtIndex(Questions q, int index);

int getAnswerCommentAtIndex(Questions q, int index);

int getAnswerIdAtIndex(Questions q, int index);

int getAnswersArraySize(Questions q);

GPtrArray getQAnswers(Questions q);

gint sortQDate (Questions aq, Questions bq);

void sortMoreAnswers(GPtrArray * total_questions);

void cleanQuestion(Questions q);
