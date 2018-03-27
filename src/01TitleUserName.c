#include "struct.h"


 /*
Dado o identificador de um post, a função deve retornar
o título do post e o nome (não o ID) de utilizador do autor. Se o post
for uma resposta, a função deverá retornar informações (título e utilizador)
da pergunta correspondente;
 */

STR_pair info_from_post(TAD_community com, int id) {
   STR_pair title_username;
   int user_id;
   long parent_id;
   title_username = create_str_pair(NULL, NULL);


   Questions question = lookQuestion(com, (long)id);

    if (question == NULL) {
      Answers answer = lookAnswer(com, (long)id);
      if (answer != NULL) {
        parent_id = getParentId(answer);
        question = lookQuestion(com, (long)parent_id);
      }
    }

   if (question != NULL) {
      user_id = getQUserId(question);
      Users user = lookUsers(com, user_id);
      if (user == NULL) {
        return title_username;
      }
      title_username = create_str_pair(getTitle(question), getUsername(user));
   }

   return title_username;

 }
