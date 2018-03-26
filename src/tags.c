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
Função que devolve o tamanho da estrtura tags
*/
int getTagsSize() {
  return sizeof(struct tags);
}

/*
Função que devolve o id da tag
*/
int getTagId(PtrTags tag) {
  return tag->id;
}

/*
Função que estabelece o id da tag
*/
void setTagId(PtrTags tag, int id) {
  tag->id = id;
}

/*
Função que devolve o nome da tag
*/
char * getTagName(PtrTags tag) {
  char * name = malloc(sizeof(char) * (strlen(tag->nameTag)+2));
  strcpy(name, tag->nameTag);

  return name;
}

/*
Função que estabelece o nome da tag
*/
void setTagName(PtrTags tag, const char * name){
  char * nameTag = malloc(sizeof(char) * (strlen(name)+2));
  strcpy(nameTag, name);

  tag->nameTag = nameTag;
}


/*
Função que devolve o valor do parametro value
*/
int getTagValue(PtrTags tag) {
  return tag->value;
}

/*
Função que estabelece o valor do parametro value
*/
void setTagValue(PtrTags tag, int value) {
  tag->value = value;
}

/*
Função que incrementa em uma unidade o parametro value
*/
int incrementTagValue(PtrTags tag) {
  return tag->value++;
}
