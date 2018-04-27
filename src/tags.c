#include <gmodule.h>
#include <stdlib.h>
#include <string.h>

#include "tags.h"

/**
@file tags.c
Estrutura de dados relativa às tags, respetivos
getters e setters e funções auxiliares necessárias.
*/

/**
\brief Estrutura com o identificador da tag, o nome da tag
e um parâmetro diferenciador.
*/
typedef struct tags {
  int id;
  char * nameTag;
  int value;
} tags;


/**
\brief Função que devolve o tamanho da estrutura tags.
@returns int - Tamanho da estrutura tags.
*/
int getTagsSize() {
  return sizeof(struct tags);
}

/**
\brief Função que devolve o id da tag.
@param tag Apontador para tags.
@returns int - Identificador da tag.
*/
int getTagId(Tags tag) {
  return tag->id;
}

/**
\brief Função que estabelece o id da tag.
@param tag Apontador para tags.
@param id Identificador da tag.
*/
void setTagId(Tags tag, int id) {
  tag->id = id;
}

/**
\brief Função que devolve o nome da tag.
@param tag Apontador para tags.
@returns char * - Nome da tag.
*/
char * getTagName(Tags tag) {
  char * name = malloc(sizeof(char) * (strlen(tag->nameTag)+2));
  strcpy(name, tag->nameTag);

  return name;
}

/**
\brief Função que estabelece o nome da tag.
@param tag Apontador para tags.
@param name Nome da tag.
*/
void setTagName(Tags tag, const char * name){
  char * nameTag = malloc(sizeof(char) * (strlen(name)+2));
  strcpy(nameTag, name);

  tag->nameTag = nameTag;
}


/**
\brief Função que devolve o valor do parâmetro value.
@param tag Apontador para tags.
@returns int - Valor do parâmetro value.
*/
int getTagValue(Tags tag) {
  return tag->value;
}

/**
\brief Função que estabelece o valor do parâmetro value.
@param tag Apontador para tags.
@param Valor do value.
*/
void setTagValue(Tags tag, int value) {
  tag->value = value;
}

/**
\brief Função que incrementa em uma unidade o parâmetro value.
@param tag Apontador para tags.
*/
void incrementTagValue(Tags tag) {
  tag->value = tag->value + 1;
}

/**
\brief Função que compara o número de ocorrências de duas tags recebidas
como parâmetro (query 11).
@param t1 Apontador para um apontador para tags.
@param t2 Apontador para um apontador para tags.
@returns gint - positivo se o número de ocorrências da tag t1
for menor que o da t2, caso contrário devolve um número negativo.
*/
static gint sortOccurrencesTags(Tags * t1, Tags * t2) {
  int nOccur1, nOccur2;
  nOccur1 = getTagValue(*t1);
  nOccur2 = getTagValue(*t2);

  int result = nOccur2 - nOccur1;

  return (result != 0)? result : (getTagId(*t1) - getTagId(*t2));;
}

/**
\brief Função que ordena as tags de acordo com o número de vezes que elas aparecem,
(da tag mais usada para a tag menos usada) (query 11).
@param total_tags Apontador para GPtrArray.
*/
void sortTags(GPtrArray * total_tags) {
  g_ptr_array_sort(total_tags, (GCompareFunc)sortOccurrencesTags);
}


/**
\brief Função que elimina o espaço de memória criado para o nome da tag.
@param t Apontador para tags.
*/
void cleanTags(Tags t) {
  free(t->nameTag);
  free(t);
}
