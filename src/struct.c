#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "interface.h"


/*
Estrutura de dados que armazena informação relativa a todas as estruturas
de elementos necessários para responder às 11 interrogações.
*/
typedef struct TCD_community {
  GHashTable * users;
  GHashTable * questions;
  GHashTable * answers;
  GList * questionsList;
  GPtrArray * day;
  GHashTable * tags;
} TCD_community;


/*
Função que inicializa a estrutura TCD_community.
*/
TAD_community init() {
  TAD_community com;

  com = malloc(sizeof(TCD_community));

  com->users =  g_hash_table_new_full
    (g_direct_hash, g_direct_equal, NULL, (GDestroyNotify)cleanUser);
  
  com->questions = g_hash_table_new_full
    (g_direct_hash, g_direct_equal, NULL, (GDestroyNotify)cleanQuestion);
  
  com->answers = g_hash_table_new_full
    (g_direct_hash, g_direct_equal, NULL, (GDestroyNotify)cleanAnswer);
  
  com->tags = g_hash_table_new_full
    (g_str_hash, g_str_equal, g_free, (GDestroyNotify)cleanTags);
  
  com->questionsList = NULL;

  com->day = g_ptr_array_sized_new(3650);
  g_ptr_array_set_size (com->day, 3650);

  GDate * actualDate = g_date_new_dmy(15, 9, 2008);
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

    g_date_free(actualDate);

    return com;
}

/*
Função que procura um user na tabela de hash designada users.
*/
Users lookUsers(TAD_community t, long id) {
  Users u = g_hash_table_lookup(t->users, GINT_TO_POINTER(id));
  return u;
}

/*
Função que insere um user na tabela de hash designada users.
*/
void insertUser(TAD_community t, long id, Users pointer) {
  g_hash_table_insert(t->users, GINT_TO_POINTER(id), pointer);
}

/*
Função que procura uma pergunta na tabela de hash designada questions.
*/
Questions lookQuestion(TAD_community t, long id) {
  Questions q = g_hash_table_lookup(t->questions, GINT_TO_POINTER(id));
  return q;
}

/*
Função que insere uma pergunta na tabela de hash questions.
*/
void insertQuestion(TAD_community t, long id, Questions pointer) {
  g_hash_table_insert(t->questions, GINT_TO_POINTER(id), pointer);
}

/*
Função que devolve o número de perguntas armazenadas na tabela de hash questions.
*/
guint getNumberOfQuestions(TAD_community t) {
    guint size = g_hash_table_size(t->questions);

    return size;
}

/*
Função que devolve o endereço da tabela de hash users.
*/
GHashTable * getHashTableUsers(TAD_community t) {
  return t->users;
}

/*
Função que devolve um apontador para uma lista de perguntas ordenada por data.
*/
GList * getQuestions(TAD_community t) {
    if(t->questionsList != NULL)
        return t->questionsList;

    GList * q = g_hash_table_get_values(t->questions);

    q = g_list_sort(q, (GCompareFunc)sortQDate);

    t->questionsList = q;

    return q;
}

/*
Função que devolve o apontador para o dia contido num determinado índice
do GPtrArray day.
*/
Day lookDay(TAD_community t, long indexDay){
  Day d = g_ptr_array_index(t->day, indexDay);
  return d;
}

/*
Função que insere o apontador do respetivo dia no GPtrArray day.
*/
void insertDay(TAD_community t, long indexDay, Day pointer) {
  g_ptr_array_insert(t->day, indexDay, pointer);
}

/*
Função que devolve o apontador para uma tag contida num determinado índice
da hash table tags.
*/
Tags lookTag(TAD_community t, char * tagName) {
  Tags tag = g_hash_table_lookup(t->tags, g_strdup(tagName));

  return tag;
}

/*
Função que adiciona uma tag à hash table tags.
*/
void insertTag(TAD_community t, char * tagName, Tags tag) {
  g_hash_table_insert(t->tags, g_strdup(tagName), tag);
}


/*
Função que insere uma resposta na tabela de hash designada answers
*/
void insertAnswers(TAD_community t, long id, Answers pointer) {
  g_hash_table_insert(t->answers, GINT_TO_POINTER(id), pointer);
}


/*
Função que procura uma resposta na tabela de hash designada answers.
*/
 Answers lookAnswer(TAD_community t, long id) {
   Answers answer = g_hash_table_lookup(t->answers, GINT_TO_POINTER(id));
  return answer;
}


void cleanStruct(TAD_community com) {
    g_hash_table_destroy(com->users);

    g_hash_table_destroy(com->questions);

    g_hash_table_destroy(com->answers);

    g_list_free(com->questionsList);

    g_ptr_array_set_free_func(com->day, (GDestroyNotify)cleanDay);
    g_ptr_array_free(com->day, TRUE);

    g_hash_table_destroy(com->tags);
}
