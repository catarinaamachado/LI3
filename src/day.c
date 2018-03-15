#include <gmodule.h>

typedef struct day {
  int day;
  int month;
  int year;
  int n_questions;
  int n_answers;
  GPtrArray * questions;
  GPtrArray * answers;
} Day;

int getDay(Day * day) {
    return day->day;
}

void setDay(Day * day, int newDay) {
    day->day = newDay;
}

int getMonth(Day * day) {
    return day->month;
}

void setMonth(Day * day, int newMonth) {
    day->month = newMonth;
}

int getYear(Day * day) {
    return day->year;
}

void setYear(Day * day, int newYear) {
    day->year = newYear;
}

int getN_questions(Day * day) {
    return day->n_questions;
}

void setN_questions(Day * day, int n_questions) {
    day->n_questions = n_questions;
}

int getN_answers(Day * day) {
    return day->n_answers;
}

void setN_answers(Day * day, int n_answers) {
    day->n_answers = n_answers;
}

GPtrArray * getQuestionsDay(Day * day) {
    return day->questions;
}

void setQuestionsDay(Day * day, GPtrArray * newQuestions) {
    day->questions = newQuestions;
}

GPtrArray * getAnswersDay(Day * day) { //FIXME
    return day->answers;
}

void setAnswersDay(Day * day, GPtrArray * newAnswers) { //FIXME
    day->answers = newAnswers;
}
