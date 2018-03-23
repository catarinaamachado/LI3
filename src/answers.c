#include <gmodule.h>

#include "answers.h"

typedef struct answers {
  long user_id;
  long answer_id;
  int score;
  int total_voters;//
  GArray * voters_id;//
} answers;

int sizeAnswers() {
    return sizeof(struct answers);
}

long getAUserId(Answers a) {
    return a->user_id;
}

void setAUserId(Answers a, long id) {
    a->user_id = id;
}


long getAnswerId(Answers a) {
    return a->answer_id;
}

void setAnswerId(Answers a, long id) {
    a->answer_id = id;
}

int getScore(Answers a) {
    return a->score;
}

void setScore(Answers a, int s) {
    a->score = s;
}

int getTotalVoters(Answers a) {
    return a->total_voters;
}

void setTotalVoters(Answers a, int t) {
    a->total_voters = t;
}

GArray * getVotersId(Answers a) { //FIXME:
    return a->voters_id;
}

void setVotersId(Answers a, GArray * p) { //FIXME:
    a->voters_id = p;
}
