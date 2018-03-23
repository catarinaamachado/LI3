#include <gmodule.h>

typedef struct answers * Answers;

int sizeAnswers();

long getAnswerId(Answers a);

void setAnswerId(Answers a, long id);

long getAUserId(Answers a);

void setAUserId(Answers a, long id);

int getScore(Answers a);

int getFavoriteCount(Answers a);

void setFavoriteCount(Answers a, int f);

int getCommentCount(Answers a);

void setCommentCount(Answers a, int c);

void setScore(Answers a, int s);
