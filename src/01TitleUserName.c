#include "01TitleUserName.h"

#include <stdlib.h>

 /*
struct str_pair {
   char* fst; apontador para o titulo
   char* snd; apontador para o nome do usuário
};
*/

//typedef struct TCD_community * TAD_community;


 /* Dado o identificador de um post, a função devolve
  o título do post e o nome de utilizador do autor;
 */


STR_pair info_from_post(TAD_community com, int id) {
   STR_pair title_username;
   int user_id;
   title_username = create_str_pair(NULL, NULL);



   Questions question = lookQuestion(com, (long)id);

   if (question == NULL) {
      return title_username;
    }

   user_id = getQUserId(question);

   Users user = lookUsers(com, user_id);

   if ( user == NULL) {
      return title_username;
    }


   title_username = create_str_pair(getTitle(question), getUsername(user));


   return title_username;

 }
