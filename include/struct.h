#include <gmodule.h>

#include "interface.h"
#include "users.h"
#include "questions.h"
#include "postDate.h"

TAD_community init();

Users lookUsers(TAD_community t, long id);

void insertUser(TAD_community t, long id, Users pointer);

Questions lookQuestion(TAD_community t, long id);

void insertQuestion(TAD_community t, long id, Questions pointer);

void insertAnswers(TAD_community t, long id, Answers pointer);