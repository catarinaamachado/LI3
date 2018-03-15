#include <stdlib.h>

#include "struct.h"
#include "interface.h"

typedef struct TCD_community {
  GHashTable * users;
  GHashTable * questions;
  GHashTable * answers; //hash table com as respostas
  GHashTable * day; //hash table com os dias
} TCD_community;

TAD_community init() {
  TAD_community com;

  com = malloc(sizeof(TCD_community));

  com->users =  g_hash_table_new(g_direct_hash, g_direct_equal);

  com->questions = g_hash_table_new (g_direct_hash, g_direct_equal);

  com->day = g_hash_table_new(g_direct_hash, g_direct_equal);

  com->answers = g_hash_table_new(g_direct_hash, g_direct_equal);

  return com;
}

Users lookUsers(TAD_community t, long id) {
  Users u = g_hash_table_lookup(t->users, GINT_TO_POINTER(id));
  return u;
}

void insertUser(TAD_community t, long id, Users pointer) {
  g_hash_table_insert(t->users, GINT_TO_POINTER(id), pointer);
}

Questions lookQuestion(TAD_community t, long id) {
  Questions q = g_hash_table_lookup(t->questions, GINT_TO_POINTER(id));
  return q;
}

void insertQuestion(TAD_community t, long id, Questions pointer) {
  g_hash_table_insert(t->questions, GINT_TO_POINTER(id), pointer);
}

void insertAnswers(TAD_community t, long id, Answers pointer) {
  g_hash_table_insert(t->answers, GINT_TO_POINTER(id), pointer);
}