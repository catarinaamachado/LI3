#include <gmodule.h>

#include "answers.h"


/*
Estrutura dos posts respostas
*/
typedef struct answers {
  long user_id;
  long answer_id;
  long parent_id; // a que pergunta pertence
  int score;
  int up_votes;
  int down_votes;
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
Função que devolve o id da pergunta a que a resposta se refere
*/
long getParentId(Answers a) {
    return a->parent_id;
}

/*
Função que estabelece o id da pergunta a que a resposta se refere
*/
void setParentId(Answers a, long id) {
    a->parent_id = id;
}

/*
Função que devolve o score de uma resposta
*/
int getScore(Answers a) {
    return a->score;
}

/*
Função que estabelece o score de determinada resposta
*/
void setScore(Answers a, int s) {
    a->score = s;
}

/*
Função que devolve o número de up votes de uma resposta
*/
int getUpVotes(Answers a) {
    return a->up_votes;
}

/*
Função que estabelece o número de up votes de uma resposta
*/
void setUpVotes(Answers a, int upvotes) {
     a->up_votes = upvotes;
}

/*
Função que devolve o número de down votes de uma resposta
*/
int getDownVotes(Answers a) {
    return a->down_votes;
}

/*
Função que estabelece o número de down votes de uma resposta
*/
void setDownVotes(Answers a, int downvotes) {
     a->down_votes = downvotes;
}

/*
Função que devolve o número total de votos de uma resposta
*/
int getTotalVotes(Answers a) {
    return getUpVotes(a) - getDownVotes(a);
}


/*
Função que incrementa os up votes de uma resposta
*/
void incrementUpVotes(Answers a) {
    a->up_votes++;
}

/*
Função que incrementa os down votes de uma resposta
*/
void incremenDownVotes(Answers a) {
     a->down_votes++;
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
