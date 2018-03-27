#include <stdio.h>
#include <stdlib.h>
#include <gmodule.h>

#include "postDate.h"


/*
Estrutura de dados que guarda a informação referente à data de cada post.
*/
typedef struct postAndDate {
    long post_id;
    int year, month, day, hour, min, sec, mili;
} postAndDate;


/*
Função que compara duas datas.
*/
gint sortDate (postDate a, postDate b) {
    if (getPDYear(a) < getPDYear(b))
        return -1;
    else if (getPDMonth(a) < getPDMonth(b))
        return -1;
    else if (getPDDay(a) < getPDDay(b))
        return -1;
    else if (getPDHour(a) < getPDHour(b))
        return -1;
    else if (getPDMin(a) < getPDMin(b))
        return -1;
    else if (getPDSec(a) < getPDSec(b))
        return -1;
    else if (getPDMili(a) < getPDMili(b))
        return -1;

    return 1;
}

/*
Função que devolve o tamanho da estrutura postAndDate.
*/
int getPDSize() {
    return sizeof(struct postAndDate);
}

/*
Função que devolve o id do post.
*/
long getPostId(postDate pd) {
    return pd->post_id;
}

/*
Função que estabelece o id do post.
*/
void setPostId(postDate pd, long i) {
    pd->post_id = i;
}

/*
Função que devolve o ano de criação do post.
*/
int getPDYear(postDate pd) {
    return pd->year;
}

/*
Função que devolve o mês de criação do post.
*/
int getPDMonth(postDate pd) {
    return pd->month;
}

/*
Função que devolve o dia de criação do post.
*/
int getPDDay(postDate pd) {
    return pd->day;
}

/*
Função que devolve a hora de criação do post.
*/
int getPDHour(postDate pd) {
    return pd->hour;
}

/*
Função que devolve os minutos de criação do post.
*/
int getPDMin(postDate pd) {
    return pd->min;
}

/*
Função que devolve os segundos de criação do post.
*/
int getPDSec(postDate pd) {
    return pd->sec;
}

/*
Função que devolve os milissegundos de criação do post.
*/
int getPDMili(postDate pd) {
    return pd->mili;
}

/*
Função que estabelece a data de criação do post.
*/
void setDate(postDate pd, char * date) {
    sscanf(date, "%d-%d-%dT%d:%d:%d.%d\n", &pd->year, &pd->month, &pd->day, &pd->hour, &pd->min, &pd->sec, &pd->mili);
}
