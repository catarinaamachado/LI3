#include <stdio.h>
#include <stdlib.h>

#include "postDate.h"

typedef struct postAndDate {
    long post_id;
    int year, month, day, hour, min, sec, mili;
} postAndDate;

int getPDSize() {
    return sizeof(struct postAndDate);
}

long getPostId(postDate pd) {
    return pd->post_id;
}

void setPostId(postDate pd, long i) {
    pd->post_id = i;
}

int getPDYear(postDate pd) {
    return pd->year;
}

int getPDMonth(postDate pd) {
    return pd->month;
}

int getPDDay(postDate pd) {
    return pd->day;
}

int getPDHour(postDate pd) {
    return pd->hour;
}

int getPDMin(postDate pd) {
    return pd->min;
}

int getPDSec(postDate pd) {
    return pd->sec;
}

int getPDMili(postDate pd) {
    return pd->mili;
}

void setDate(postDate pd, char * date) {
    sscanf(date, "%d-%d-%dT%d:%d:%d.%d\n", &pd->year, &pd->month, &pd->day, &pd->hour, &pd->min, &pd->sec, &pd->mili);
}