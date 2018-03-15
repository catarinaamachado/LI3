// #include "struct.h"
// #include "interface.h"
// #include "pair.h"

// #include <stdlib.h>

// /*
// struct str_pair {
//   char* fst; apontador para o titulo
//   char* snd; apontador para o nome do usuário
// };
// */

// //typedef struct TCD_community * TAD_community;


// /* Dado o identificador de um post, a função devolve
// o título do post e o nome de utilizador do autor;
// */


// STR_pair info_from_post(TAD_community com, int id) {
//   STR_pair title_username;
//   int user_id;
//   title_username = create_str_pair(NULL, NULL);



//   Questions * question = g_hash_table_lookup(com->questions, GINT_TO_POINTER(id));

//   if (question == NULL) {
//      return title_username;
//    }

//   user_id = question->user_id;

//   Users * user = g_hash_table_lookup(com->users, GINT_TO_POINTER(user_id));

//   if ( user == NULL) {
//      return title_username;
//    }


//   title_username = create_str_pair(question->title, user->username);


//   return title_username;

// }
