#include <stdlib.h>

#include "struct.h"
#include "interface.h"

typedef struct TCD_community {
  GHashTable * users;
  GHashTable * questions;
  GList * questionsList;
  GHashTable * answers;
  GPtrArray * day;
} TCD_community;

TAD_community init() {
  TAD_community com;

  com = malloc(sizeof(TCD_community));

  com->users =  g_hash_table_new(g_direct_hash, g_direct_equal);

  com->questions = g_hash_table_new (g_direct_hash, g_direct_equal);

  com->day = g_ptr_array_sized_new(3650);
  g_ptr_array_set_size (com->day, 3650);

  GDate * actualDate = g_date_new_dmy (15, 9, 2008);
  int day, month, year;

  for (int i = 0; i < 3650; i++) {
    Day pointerDay = malloc(sizeDay());

    initDAYQuestions(pointerDay);
    initDAYAnswers(pointerDay);

    day = g_date_get_day(actualDate);
    month = g_date_get_month(actualDate);
    year = g_date_get_year(actualDate);

    setDay(pointerDay, day);
    setMonth(pointerDay, month);
    setYear(pointerDay, year);

    g_ptr_array_insert(com->day, i, pointerDay);

    g_date_add_days(actualDate, 1);
  }

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

guint getNumberOfQuestions(TAD_community t) {
    guint size = g_hash_table_size(t->questions);

    return size;
}

//devolve o endereço da HashTable users.
GHashTable * getHashTableUsers(TAD_community t) {
  return t->users;
}

GList * getQuestions(TAD_community t) {
    if(t->questionsList != NULL)
        return t->questionsList;

    GList * q = g_hash_table_get_values(t->questions);

    q = g_list_sort(q, (GCompareFunc)sortQDate);

    t->questionsList = q;

    return q;
}

Day lookDay(TAD_community t, long indexDay){
  Day d = g_ptr_array_index(t->day, indexDay);
  return d;
}

void insertDay(TAD_community t, long indexDay, Day pointer) {
  g_ptr_array_insert(t->day, indexDay, pointer);
}
