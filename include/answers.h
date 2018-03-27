#include <gmodule.h>

typedef struct answers * Answers;

int sizeAnswers();

long getAnswerId(Answers a);

void setAnswerId(Answers a, long id);

long getAUserId(Answers a);

void setAUserId(Answers a, long id);

int getScore(Answers a);

long getParentId(Answers a);

void setParentId(Answers a, long id);

int getUpVotes(Answers a);

int getDownVotes(Answers a);

void setUpVotes(Answers a, int upvotes);

void setDownVotes(Answers a, int downvotes);

int getTotalVotes(Answers a);

int incrementUpVotes(Answers a);

int incremenDownVotes(Answers a);

int getFavoriteCount(Answers a);

int getCommentCount(Answers a);

void setCommentCount(Answers a, int c);

void setScore(Answers a, int s);

void sortAnswersVotes(GPtrArray * total_answers);
