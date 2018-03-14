#include <stdio.h>
#include <stdlib.h>

typedef struct postAndDate {
    long post_id;
    int year, month, day, hour, min, sec, mili;
} postAndDate;

typedef postAndDate * postDate;

long getPostId(postDate pd) {
    return pd->post_id;
}

void setPostId(postDate pd, long i) {
    pd->post_id = i;
}

char * getDate(postDate pd) {
    char * date = malloc(sizeof(21));
    sprintf(date, "%d/%d/%d/%d/%d/%d/%d", pd->year, pd->month, pd->day, pd->hour, pd->min, pd->sec, pd->mili);

    return date;
}

void setDate(postDate pd, char * date) {
    sscanf(date, "%d/%d/%d/%d/%d/%d/%d", &pd->year, &pd->month, &pd->day, &pd->hour, &pd->min, &pd->sec, &pd->mili);
}