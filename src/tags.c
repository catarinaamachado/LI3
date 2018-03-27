#include <gmodule.h>
#include <stdlib.h>
#include <string.h>

#include "tags.h"

/*
Estrutura com o identificador da tag, o nome da tag e um parametro diferenciador
*/
typedef struct tags {
  int id;
  char * nameTag;
  int value;
} tags;


/*
Função que devolve o tamanho da estrutura tags
*/
int getTagsSize() {
  return sizeof(struct tags);
}

/*
Função que devolve o id da tag
*/
int getTagId(Tags tag) {
  return tag->id;
}

/*
Função que estabelece o id da tag
*/
void setTagId(Tags tag, int id) {
  tag->id = id;
}

/*
Função que devolve o nome da tag
*/
char * getTagName(Tags tag) {
  char * name = malloc(sizeof(char) * (strlen(tag->nameTag)+2));
  strcpy(name, tag->nameTag);

  return name;
}

/*
Função que estabelece o nome da tag
*/
void setTagName(Tags tag, const char * name){
  char * nameTag = malloc(sizeof(char) * (strlen(name)+2));
  strcpy(nameTag, name);

  tag->nameTag = nameTag;
}


/*
Função que devolve o valor do parametro value
*/
int getTagValue(Tags tag) {
  return tag->value;
}

/*
Função que estabelece o valor do parametro value
*/
void setTagValue(Tags tag, int value) {
  tag->value = value;
}

/*
Função que incrementa em uma unidade o parametro value
*/
void incrementTagValue(Tags tag) {
  tag->value = tag->value + 1;
}

/*
Função que compara o número de ocorrências de duas tags recebidas como parametro.
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
*/
void sortTags(GPtrArray * total_tags) {
  g_ptr_array_sort(total_tags, (GCompareFunc)sortOccurrencesTags);
}
