#include <gmodule.h>

#include "answers.h"


/*
Estrutura dos posts respostas
*/
typedef struct answers {
  long user_id;
  long answer_id;
  int score;
  int favorite_count; //número de favoritos recebidos pela resposta (query 10)
  int comment_count; //número de comentários recebidos pela resposta (query 10)
} answers;

/*
Função que devolve o tamanho da estrutura answers
*/
int sizeAnswers() {
    return sizeof(struct answers);
}

/*
Função que devolve o id do user que deu a resposta
*/
long getAUserId(Answers a) {
    return a->user_id;
}

/*
Função que estabelece o id do user que deu determinada resposta
*/
void setAUserId(Answers a, long id) {
    a->user_id = id;
}

/*
Função que devolve o id da resposta
*/
long getAnswerId(Answers a) {
    return a->answer_id;
}

/*
Função que estabelece o id da resposta
*/
void setAnswerId(Answers a, long id) {
    a->answer_id = id;
}

/*
Função que devolve o número de votos de uma resposta
*/
int getScore(Answers a) {
    return a->score;
}

/*
Função que estabelece os votos de determinada resposta
*/
void setScore(Answers a, int s) {
    a->score = s;
}

/*
Função que devolve o número de favoritos de uma resposta
*/
int getFavoriteCount(Answers a) {
    return a->favorite_count;
}

/*
Função que estabelece o número de favoritos de uma resposta
*/
void setFavoriteCount(Answers a, int f) {
     a->favorite_count = f;
}

/*
Função que devolve o número de comentários de uma resposta
*/
int getCommentCount(Answers a) {
    return a->comment_count;
}

/*
Função que estabelece o número de comentários de uma resposta
*/
void setCommentCount(Answers a, int c) {
    a->comment_count = c;
}

/*
Função que compara os votos de duas respostas
query 6
*/
static gint sortVotes(Answers * a1, Answers * a2) {
  int votes_a1 = 0, votes_a2 = 0;
  votes_a1 = getScore(*a1);
  votes_a2 = getScore(*a2);

    if(votes_a1 < votes_a2)
      return 1;
    else
      return -1;
}


/*
Função que ordena os votos das respostas por ordem decrescente do número de votos
query 6
*/
void sortAnswersVotes(GPtrArray * total_answers) {
  g_ptr_array_sort(total_answers, (GCompareFunc)sortVotes);
}
