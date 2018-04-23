#include <gmodule.h>
#include <stdlib.h>
#include <string.h>

#include "tags.h"

/*
Estrutura com o identificador da tag, o nome da tag e um parametro diferenciador.
*/
typedef struct tags {
  int id;
  char * nameTag;
  int value;
} tags;


/*
Função que devolve o tamanho da estrutura tags.
@returns int - Tamanho da estrutura tags
*/
int getTagsSize() {
  return sizeof(struct tags);
}

/*
Função que devolve o id da tag.
@param tag Apontador para tags
@returns int - Identificador da tag
*/
int getTagId(Tags tag) {
  return tag->id;
}

/*
Função que estabelece o id da tag.
@param tag Apontador para tags
@param id Identificador da tag
*/
void setTagId(Tags tag, int id) {
  tag->id = id;
}

/*
Função que devolve o nome da tag.
@param tag Apontador para tags
@returns char * - Nome da tag
*/
char * getTagName(Tags tag) {
  char * name = malloc(sizeof(char) * (strlen(tag->nameTag)+2));
  strcpy(name, tag->nameTag);

  return name;
}

/*
Função que estabelece o nome da tag.
@param tag Apontador para tags
@param name Nome da tag
*/
void setTagName(Tags tag, const char * name){
  char * nameTag = malloc(sizeof(char) * (strlen(name)+2));
  strcpy(nameTag, name);

  tag->nameTag = nameTag;
}


/*
Função que devolve o valor do parametro value.
@param tag Apontador para tags
@returns int - Valor do parametro value
*/
int getTagValue(Tags tag) {
  return tag->value;
}

/*
Função que estabelece o valor do parametro value.
@param tag Apontador para tags
@param Valor do value
*/
void setTagValue(Tags tag, int value) {
  tag->value = value;
}

/*
Função que incrementa em uma unidade o parametro value.
@param tag Apontador para tags
*/
void incrementTagValue(Tags tag) {
  tag->value = tag->value + 1;
}

/*
Função que compara o número de ocorrências de duas tags recebidas como parametro.
(query 11)
@param t1 Apontador para um apontador para tags
@param t2 Apontador para um apontador para tags
@returns gint - 1 se valor da tag t1 for menor que o da t2, caso contrário devolve
-1.
*/
static gint sortOccurrencesTags(Tags * t1, Tags * t2) {
  int nOccur1, nOccur2;
  nOccur1 = getTagValue(*t1);
  nOccur2 = getTagValue(*t2);

    if(nOccur1 < nOccur2)
      return 1;
    else
      return -1;
}

/*
Função que ordena as tags de acordo com o número de vezes que elas aparecem,
(da tag mais usada para a tag menos usada).
(query 11)
@param total_tags Apontador para GPtrArray.
*/
void sortTags(GPtrArray * total_tags) {
  g_ptr_array_sort(total_tags, (GCompareFunc)sortOccurrencesTags);
}


/*
Função que elimina o espaço de memória criado para o nome da tag.
@param t Apontador para tags
*/
void cleanTags(Tags t) {
  free(t->nameTag);
  free(t);
}
