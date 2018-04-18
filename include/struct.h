#ifndef __STRUCT__
#define __STRUCT__


#include <gmodule.h>

#include "interface.h"
#include "users.h"
#include "questions.h"
#include "postDate.h"
#include "day.h"
#include "tags.h"

TAD_community init();

Users lookUsers(TAD_community t, long id);

void insertUser(TAD_community t, long id, Users pointer);

Questions lookQuestion(TAD_community t, long id);

void insertQuestion(TAD_community t, long id, Questions pointer);

void insertAnswers(TAD_community t, long id, Answers pointer);

guint getNumberOfQuestions(TAD_community t);

GHashTable * getHashTableUsers(TAD_community t);

GList * getQuestions(TAD_community t);

Day lookDay(TAD_community t, long indexDay);

void insertDay(TAD_community t, long indexDay, Day pointer);

Tags lookTag(TAD_community t, char * tagName);

void insertTag(TAD_community t, char * tagName, Tags tag);

void insertAnswers(TAD_community t, long id, Answers pointer);

Answers lookAnswer(TAD_community t, long id);

void cleanStruct(TAD_community com);


#endif
