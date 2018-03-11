#include <gmodule.h>

typedef struct users {
  int user_id;
  char * shortbio;
  char * username;
  int reputation;
  int n_posts;
  GArray * last_10posts;
} Users;

typedef struct questions {
  int post_id;
  int user_id;
  char * title;
  char * tags;  //assuming a max size //TODO: funcao que separa a string com as todas tags num array de strings
  int n_answers;
  int n_answer_votes; //numero total de votos de todas as respostas de uma dada pergunta
  GPtrArray * answers;
} Questions;

typedef struct answers{
  int answer_id;
  int score;
  int total_voters; //numero total de users que votaram naquela resposta
  GArray * voters_id; // array com os users que votaram na resposta
} Answers;

typedef struct day{
  int n_questions;
  int n_answers;
  GSList questions;
  GSList answers;
} Day;

typedef struct TCD_community{
  GHashTable * users;
  GHashTable * questions;
  GHashTable * answers; //hash table com as respostas
  GPtrArray * day;  //BUG: algoritmo do tempo indices e datas
} TCD_community;
