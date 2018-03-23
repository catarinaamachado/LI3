#include <gmodule.h>

#include "answers.h"

typedef struct answers {
  long user_id;
  long answer_id;
  int score;
  int favorite_count; //número de favoritos recebidos pela resposta (query 10)
  int comment_count; //número de comentários recebidos pela resposta (query 10);
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

//query 10
int getFavoriteCount(Answers a) {
    return a->favorite_count;
}

//query 10
void setFavoriteCount(Answers a, int f) {
     a->favorite_count = f;
}

//query 10
int getCommentCount(Answers a) {
    return a->comment_count;
}

//query 10
void setCommentCount(Answers a, int c) {
    a->comment_count = c;
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
