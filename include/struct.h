#include <gmodule.h>

typedef struct postAndDate {
    long post_id;
    int year, month, day, hour, min, sec, mili;
} postAndDate;

typedef postAndDate * postDate;

typedef struct users {
  long user_id;
  char * shortbio;
  char * username;
  int reputation;
  int n_posts;
  GArray * last_10posts;
} Users;

typedef struct questions {
  int post_id;
  long user_id;
  char * title;
  char * tags;  //assuming a max size //TODO: funcao que separa a string com as todas tags num array de strings
  int n_answers;
  int n_answer_votes; //numero total de votos de todas as respostas de uma dada pergunta
  GPtrArray * answers;
} Questions;

typedef struct answers {
  int answer_id;
  int score;
  int total_voters; //numero total de users que votaram naquela resposta
  GArray * voters_id; // array com os users que votaram na resposta
} Answers;

typedef struct day {   //int da forma "DDMMAAAA"
  int day;
  int month;  //provavelmente apagar depois estas 3 variáveis
  int year;
  int n_questions;
  int n_answers;
  GPtrArray * questions;
  GPtrArray * answers;
} Day;

typedef struct TCD_community {
  GHashTable * users;
  GHashTable * questions;
  GHashTable * answers; //hash table com as respostas
  GHashTable * day; //hash table com os dias
} TCD_community;
