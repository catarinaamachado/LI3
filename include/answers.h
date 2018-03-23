#include <gmodule.h>

typedef struct answers * Answers;

int sizeAnswers();

long getAnswerId(Answers a);

void setAnswerId(Answers a, long id);

long getAUserId(Answers a);

void setAUserId(Answers a, long id);

int getScore(Answers a);

void setScore(Answers a, int s);

int getTotalVoters(Answers a);

void setTotalVoters(Answers a, int t);

GArray * getVotersId(Answers a);

void setVotersId(Answers a, GArray * p);
