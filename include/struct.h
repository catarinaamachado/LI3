#include <gmodule.h>

typedef struct users {
  char * shortbio;
  char * username;
  int reputation;
  int n_posts;
  int next_write;       //if(next_write == 9) next_write = 0 else next_write++;
  int last_10posts[10];
} Users;

typedef struct questions {
  int post_id;
  int user_id;
  char * title;
  char * tag;  //TODO: funcao que separa a string com as todas tags num array de strings
  int n_answers;
  int n_answer_votes;
  GArray * answers;
} Questions;

typedef struct answers{
  int answer_id;
  int score;
} Answers;

typedef struct day{
  int n_questions;
  int n_answers;
  GSList questions;
  GSList answers;
} Day;

typedef struct TCD_community{
  GPtrArray * users;
  GHashTable * questions;
  GPtrArray * day;  //BUG: algoritmo do tempo indices e datas
} TCD_community;
