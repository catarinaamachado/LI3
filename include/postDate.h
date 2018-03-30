typedef struct postAndDate * postDate;

int getPDSize();

long getPostId(postDate pd);
void setPostId(postDate pd, long i);

int getPDYear(postDate pd);

int getPDMonth(postDate pd);

int getPDDay(postDate pd);

int getPDHour(postDate pd);

int getPDMin(postDate pd);

int getPDSec(postDate pd);

int getPDMili(postDate pd);

void setDate(postDate pd, char * date);

void cleanPD(postDate pd);

void cleanPDp(postDate * pd);