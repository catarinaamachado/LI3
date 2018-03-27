#include "struct.h"


/*
Estrutura de dados que armazena o id do utilizador e a quantidade
de posts que este publicou
*/
typedef struct totalPosts {
  long user_id;
  int n_posts;
} totalPosts;

/*
Função que compara o número de posts de duas posições da estutura totalPost
*/

gint compare_func(gconstpointer n_posts_a, gconstpointer n_posts_b) {
  totalPosts *a = (totalPosts *)n_posts_a;
  totalPosts *b = (totalPosts *)n_posts_b;

  return b->n_posts - a->n_posts; //se a < b return n.º negativo se a = b return 0 e se a > b return n.º positivo
}

/*
Pretende obter o top N utilizadores com maior número
de posts de sempre. Para isto, devem ser considerados tanto perguntas
quanto respostas dadas pelo respectivo utilizador;
*/


LONG_list top_most_active(TAD_community com, int N){
  int i;
  totalPosts total;
  GArray * garray;
  GHashTableIter iter;
  gpointer key, value;

  LONG_list list = create_list(N);

  garray = g_array_new (FALSE, FALSE, sizeof (totalPosts));

  GHashTable * hash_table_users = getHashTableUsers(com);

  g_hash_table_iter_init (&iter, hash_table_users);

  while (g_hash_table_iter_next (&iter, &key, &value) == TRUE) //value é um users e key é user_id
    {
      total.user_id = GPOINTER_TO_INT(key);
      total.n_posts = getNPosts(value);
      //printf("TotalPosts %d User id%ld\n", total_posts.n_posts, total_posts.user_id);
      g_array_append_val (garray, total);
    }

    g_array_sort (garray, (GCompareFunc)compare_func);

    for(i = 0; i < N; i++) {
      totalPosts total = g_array_index(garray, totalPosts, i);

      set_list(list, i, total.user_id);
    }


    g_array_free (garray, TRUE);

return list;

}
