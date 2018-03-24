#include <gmodule.h>
#include <stdlib.h>
#include <string.h>

#include "day.h"

typedef struct day {
  int day;
  int month;
  int year;
  int n_questions;
  int n_answers;
  GPtrArray * questions;
  GPtrArray * answers;
} day;

int sizeDay() {
    return sizeof(struct day);
}

int getDay(Day d) {
    return d->day;
}

void setDay(Day d, int newDay) {
    d->day = newDay;
}

int getMonth(Day d) {
    return d->month;
}

void setMonth(Day d, int newMonth) {
    d->month = newMonth;
}

int getYear(Day d) {
    return d->year;
}

void setYear(Day d, int newYear) {
    d->year = newYear;
}

int getDAYNQuestions(Day d) {
    return d->n_questions;
}

void setDAYNQuestions(Day d, int n_questions) {
    d->n_questions = n_questions;
}

int getDAYNAnswers(Day d) {
    return d->n_answers;
}

void setDAYNAnswers(Day d, int n_answers) {
    d->n_answers = n_answers;
}

void initDAYAnswers(Day d) {
    d->n_answers = 0;
    d->answers = g_ptr_array_new();
}

void addDAYAnswers(Day d, Answers a) {
    d->n_answers++;
    g_ptr_array_add(d->answers, a);
}

void initDAYQuestions(Day d) {
    d->n_questions = 0;
    d->questions = g_ptr_array_new();
}

void addDAYQuestions(Day d, Questions q) {
    d->n_questions++;
    g_ptr_array_add(d->questions, q);
}
/*
static void printQuestion(Questions q) {
    printf("%ld\n", getQuestionId(q));
}
//
void getDAYQuestion(Day d) {
    g_ptr_array_foreach(d->questions, (GFunc)printQuestion, NULL);
}
//
static void printAnswer(Answers a) {
    printf("%ld\n", getAnswerId(a));
}
//
void getDAYAnswer(Day d) {
    g_ptr_array_foreach(d->answers, (GFunc)printAnswer, NULL);
}
*/

Answers getDAYAnswerAtIndex(Day d, int index) {
    return g_ptr_array_index(d->answers, index);
}
