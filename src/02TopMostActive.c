
#include <gmodule.h>


#include "struct.h"


/*
Estrutura de dados que armazena o id do utilizador e o número de posts que este publicou
*/
typedef struct totalPosts {
  long user_id;
  int n_posts;
} totalPosts;

/*
Função que compara o número de posts de duas posições da estutura totalPost
*/

gint compare_func(gconstpointer total_posts_a, gconstpointer total_posts_b) {
  totalPosts *a = (totalPosts *)total_posts_a;
  totalPosts *b = (totalPosts *)total_posts_b;

  return b->n_posts - a->n_posts; //se a < b return n.º negativo se a = b return 0 e se a > b return n.º positivo
}

/*
Pretende obter o top N utilizadores com maior número
de posts de sempre. Para isto, devem ser considerados tanto perguntas
quanto respostas dadas pelo respectivo utilizador;
*/


LONG_list top_most_active(TAD_community com, int N){
  int i;
  totalPosts total_posts;
  GArray * garray;
  GHashTableIter iter;
  gpointer key, value;

  LONG_list list = create_list(N);

  garray = g_array_new (FALSE, FALSE, sizeof (totalPosts));

  GHashTable * hash_table_users = getHashTableUsers(com);

  g_hash_table_iter_init (&iter, hash_table_users);

  while (g_hash_table_iter_next (&iter, &key, &value) == TRUE) //value é um users e key é user_id
    {
      total_posts.user_id = GPOINTER_TO_INT(key);
      total_posts.n_posts = getNPosts(value);
      //printf("TotalPosts %d User id%ld\n", total_posts.n_posts, total_posts.user_id);
      g_array_append_val (garray, total_posts);
    }

    g_array_sort (garray, (GCompareFunc)compare_func);

    for(i = 0; i < N; i++) {
      totalPosts total_posts = g_array_index(garray, totalPosts, i);

      set_list(list, i, total_posts.user_id);
    }


    g_array_free (garray, TRUE);

return list;

}
