#include <gmodule.h>

typedef struct TCD_community {
  GHashTable * users;
  GHashTable * questions;
  GHashTable * answers; //hash table com as respostas
  GHashTable * day; //hash table com os dias
} TCD_community;