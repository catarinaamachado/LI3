#include <stdlib.h>

#include "struct.h"

/**
@file 01TitleUserName.c
Resposta à interrogação 1.
*/


/**
\brief Dado o identificador de um post, a função retorna
o título do post e o nome (não o ID) de utilizador do autor. Caso o post não
possua título ou nome de utilizador, o resultado correspondente deverá
ser NULL.
Se o post for uma resposta, a função retorna informações (título e utilizador)
da pergunta correspondente.
@param com Apontador para a TCD_community.
@param id Identificador do Post.
@returns STR_pair - Título e utilizador.
*/
STR_pair info_from_post(TAD_community com, long id) {
   STR_pair title_username;
   int user_id;
   long parent_id;
   char * title, * username;

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
        return create_str_pair(NULL, NULL);
      }

      title = getTitle(question);
      username = getUsername(user);

      if(title != NULL && username != NULL){
        title_username = create_str_pair(title, username);
        free(title);
        free(username);
      }
      else {
        free(title);
        free(username);
        return create_str_pair(NULL, NULL);
      }
   }
   else
    return create_str_pair(NULL, NULL);

   return title_username;
 }
