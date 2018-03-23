#include <gmodule.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "day.h"

typedef struct day {
  int day;
  int month;
  int year;
  int n_questions;
  int n_answers;
  int test_index;
  GPtrArray * questions;
  GPtrArray * answers;
} day;

void setCENAS(Day d, int NEW) {
    d->test_index = NEW;
}

int getCENAS(Day d) {
    return d->test_index;
}

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
    d->answers = g_ptr_array_sized_new(d->n_answers);
}

void addDAYAnswers(Day d, Answers a) {
    g_ptr_array_add(d->answers, a);
}

void initDAYQuestions(Day d) {
    d->questions = g_ptr_array_sized_new(d->n_questions);
}

void addDAYQuestions(Day d, Questions q) {
    g_ptr_array_add(d->questions, q);
}
