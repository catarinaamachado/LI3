#include <stdio.h>
#include <stdlib.h>
#include <gmodule.h>

#include "postDate.h"

/**
@file postDate.c
Estrutura de dados relativa às datas dos posts,
respetivos getters e setters e funções auxiliares necessárias.
*/


/**
\brief Estrutura de dados que guarda a informação referente à data de cada post.
*/
typedef struct postAndDate {
    long post_id;
    int year, month, day, hour, min, sec, mili;
} postAndDate;


/**
\brief Função que compara duas datas.
@param a Apontador para a data de um post.
@param b Apontador para a data de outro post.
@returns gint - Positivo se a primeira data for mais antiga que
a segunda e negativo caso contrário.
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

/**
\brief Função que devolve o tamanho da estrutura postAndDate.
@returns int - Tamanho da estrutura postAndDate.
*/
int getPDSize() {
    return sizeof(struct postAndDate);
}

/**
\brief Função que devolve o id do post.
@returns int - Id.
*/
long getPostId(postDate pd) {
    return pd->post_id;
}

/**
\brief Função que estabelece o id do post.
@param pd Apontador para o postDate em questão.
@param i Novo id.
*/
void setPostId(postDate pd, long i) {
    pd->post_id = i;
}

/**
\brief Função que devolve o ano de criação do post.
@param pd Apontador para o postDate em questão.
@returns int - Ano do post.
*/
int getPDYear(postDate pd) {
    return pd->year;
}

/**
\brief Função que devolve o mês de criação do post.
@param pd Apontador para o postDate em questão.
@returns int - Mês do post.
*/
int getPDMonth(postDate pd) {
    return pd->month;
}

/**
\brief Função que devolve o dia de criação do post.
@param pd Apontador para o postDate em questão.
@returns int - Dia do post.
*/
int getPDDay(postDate pd) {
    return pd->day;
}

/**
\brief Função que devolve a hora de criação do post.
@param pd Apontador para o postDate em questão.
@returns int - Hora do post.
*/
int getPDHour(postDate pd) {
    return pd->hour;
}

/**
\brief Função que devolve os minutos de criação do post.
@param pd Apontador para o postDate em questão.
@returns int - Número de minutos da hora em que o post foi criado.
*/
int getPDMin(postDate pd) {
    return pd->min;
}

/**
\brief Função que devolve os segundos de criação do post.
@param pd Apontador para o postDate em questão.
@returns int - Número de segundos da hora em que o post foi criado.
*/
int getPDSec(postDate pd) {
    return pd->sec;
}

/**
\brief Função que devolve os milissegundos de criação do post.
@param pd Apontador para o postDate em questão.
@returns int - Número de milissegundos da hora em que o post foi criado.
*/
int getPDMili(postDate pd) {
    return pd->mili;
}

/**
\brief Função que estabelece a data de criação do post.
@param pd Apontador para o postDate em questão.
@param date A data em que o post foi criado em formato string.
*/
void setDate(postDate pd, char * date) {
    sscanf(date, "%d-%d-%dT%d:%d:%d.%d\n", &pd->year, &pd->month, &pd->day, &pd->hour, &pd->min, &pd->sec, &pd->mili);
}

/**
\brief Função que liberta o apontador para a estrutura postDate.
@param pd Apontador para o postDate em questão.
*/
void cleanPD(postDate pd) {
    free(pd);
}

/**
\brief Função que liberta o apontador para o apontador para a estrutura postDate.
@param pd Apontador para o apontador do postDate em questão.
*/
void cleanPDp(postDate * pd) {
    free(*pd);
}
