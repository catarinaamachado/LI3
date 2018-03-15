#ifndef __POSTDATE_H__
#define __POSTDATE_H__

typedef struct postAndDate * postDate;

int getPDSize();

long getPostId(postDate pd);
void setPostId(postDate pd, long i);

int getYear(postDate pd);

int getMonth(postDate pd);

int getDay(postDate pd);

int getHour(postDate pd);

int getMin(postDate pd);

int getSec(postDate pd);

int getMili(postDate pd);

void setDate(postDate pd, char * date);

#endif