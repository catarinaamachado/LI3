#include <gmodule.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "tags.h"

typedef struct tags {
  int id;
  char * nameTag;
  int value;
} tags;


int getTagsSize() {
  return sizeof(struct tags);
}

int getTagId(PtrTags tag) {
  return tag->id;
}

void setTagId(PtrTags tag, int id) {
  tag->id = id;
}

char * getTagName(PtrTags tag) {
  char * name = malloc(sizeof(char) * (strlen(tag->nameTag)+2));
  strcpy(name, tag->nameTag);

  return name;
}

void setTagName(PtrTags tag, const char * name){
  char * nameTag = malloc(sizeof(char) * (strlen(name)+2));
  strcpy(nameTag, name);

  tag->nameTag = nameTag;
}


int getTagValue(PtrTags tag) {
  return tag->value;
}


void setTagValue(PtrTags tag, int value) {
  tag->value = value;
}


int incrementTagValue(PtrTags tag) {
  return tag->value++;
}
