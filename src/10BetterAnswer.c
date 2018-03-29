#include <gmodule.h>
//#include<stdio.h>
#include <assert.h>

#include "struct.h"

/*
Dado o ID de uma pergunta, obter a melhor resposta.
Para isso, deverá usar a função de média ponderada abaixo:

(score da resposta × 0.45) + (reputação do utilizador × 0.25) +
(número de votos recebidos pela resposta × 0.2) +
(número de comentários recebidos pela resposta × 0.1)
*/

long better_answer(TAD_community com, long id) {
  int i, total_answers, reputation;
  long answer_id;
  double total, max = 0.0;

  Questions question = lookQuestion(com, id);


  if (question == NULL) {
     return -1;
   }

  total_answers = getNAnswers(question);
  assert(total_answers == getAnswersArraySize(question)); // isto tem de dar 1 senão o programa estoura

  for(i = 0; i < total_answers; i++) {
       Users user = lookUsers(com, getAnswerUserIdAtIndex(question, i));

       if (user == NULL) {
         reputation = 0;
       }
       else {
         reputation = getReputation(user);
       }

       /*
       printf("Id answer: %d\n", getAnswerIdAtIndex(question, i));
       printf("Reputação : %d %d\n", i, getReputation(user));
       printf("Votos: %d %d\n", i, getAnswerVotesAtIndex(question, i));
       printf("Score %d %d\n",i,  getAnswerScoreAtIndex(question, i));
       printf("Comments %d %d\n", i, getAnswerCommentAtIndex(question, i));
       */

       total = (getAnswerScoreAtIndex(question, i) * 0.45) +
               (reputation * 0.25) +
               (getAnswerVotesAtIndex(question, i) * 0.2) +
               (getAnswerCommentAtIndex(question, i) * 0.1);


      //printf("Total: %f\n", total);

      if(total > max) {
          max = total;
          answer_id = getAnswerIdAtIndex(question, i);
          //printf("Max: %f Id_answer: %d\n", max, answer_id);
      }

   }



  return answer_id;
}
