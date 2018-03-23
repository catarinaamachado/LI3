#include <gmodule.h>

#include "interface.h"
#include "answers.h"
#include "questions.h"

typedef struct day * Day;

void setCENAS(Day d, int NEW);

int getCENAS(Day d);

int sizeDay();

int getDay(Day d);

void setDay(Day d, int newDay);

int getMonth(Day d);

void setMonth(Day d, int newMonth);

int getYear(Day d);

void setYear(Day d, int newYear);

int getDAYNQuestions(Day d);

void setDAYNQuestions(Day d, int n_questions);

int getDAYNAnswers(Day d);

void setDAYNAnswers(Day d, int n_answers);

void initDAYAnswers(Day d);

void addDAYAnswers(Day d, Answers a);

void initDAYQuestions(Day d);

void addDAYQuestions(Day d, Questions q);
