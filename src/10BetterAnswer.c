#include <gmodule.h>
//#include<stdio.h>

#include "struct.h"

/*
Dado o ID de uma pergunta, obter a melhor resposta.
Para isso, deverá usar a função de média ponderada abaixo:

(score da resposta × 0.45) + (reputação do utilizador × 0.25) +
(número de votos recebidos pela resposta × 0.2) +
(número de comentários recebidos pela resposta × 0.1)
*/

LONG_list better_answer(TAD_community com, int id) {
  int i, total_answers, answer_id, reputation;
  double total, max = 0.0;

  Questions question = lookQuestion(com, (long)id);


  if (question == NULL) {
     return NULL;
   }

  total_answers = getNAnswers(question);

  LONG_list better_answer = create_list(1);

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

   set_list(better_answer, 0, answer_id);


  return better_answer;
}
