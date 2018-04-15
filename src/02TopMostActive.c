#include "struct.h"



/*
Função que devolve o top N utilizadores com maior número
de posts de sempre. Para isto, são considerados tanto perguntas
quanto respostas dadas pelo respectivo utilizador;
*/
LONG_list top_most_active(TAD_community com, int N) {
  int i;
  GArray * garray;
  GHashTableIter iter;
  gpointer key, value;

  LONG_list list = create_list(N);

  garray = initArrayTotalPosts();

  GHashTable * hash_table_users = getHashTableUsers(com);

  g_hash_table_iter_init(&iter, hash_table_users);

  while (g_hash_table_iter_next(&iter, &key, &value) == TRUE) //value é um users e key é user_id ver função insertUser(structure, user_id, pointer);
    {
      insertTotalPostsArray(garray, GPOINTER_TO_INT(key), getNPosts(value));
    }

  sortArrayTotalPosts(garray);

  for(i = 0; i < N; i++) {
      set_list(list, i, getTotalPostsUserIdAtIndex(garray, i));
      //printf("Utilizador: %ld N_Posts: %d\n", getTotalPostsUserIdAtIndex(garray, i), getTotalPostsAtIndex(garray, i));
  }


    freeArrayTotalPosts(garray);

    return list;
}
