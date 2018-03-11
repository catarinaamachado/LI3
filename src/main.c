#include <stdlib.h>
#include <stdio.h>
#include <gmodule.h>


#include "00load.h"
#include "init.h"
#include <struct.h>

int main(){

  TAD_community com = init();

  com = load(com, "../android/");

  Questions * q;
  Answers * a;
  Users * u;

  // for (int i = 0; i <= 187278; i++) {
  //   q = g_hash_table_lookup (com->questions, GINT_TO_POINTER(i));

  //   if(q != NULL) {
  //     printf("Q: Id: %d, User id: %d, Title: %s", q->post_id, q->user_id, q->title);

  //     for(int l = 0; l < q->n_answers; l++) {

  //       a = g_ptr_array_index(q->answers, l);

  //       if(a != NULL)
  //         printf("  A: Id: %d, Score: %d\n", a->answer_id, a->score);
  //     }

  //   printf("\n\n");
  //   }
  // }

  for (int i = 0; i <= 245699; i++) {
      u = g_hash_table_lookup (com->users, GINT_TO_POINTER(i));

      if(u != NULL) {
        printf("Id: %d\nName: %sBio: %s\nReputation: %d", i, u->username, u->shortbio, u->reputation);
        printf("\n\n");
      }
    }

  //TODO criar função para libertar a memória de todas as estruturas
  free(com);

  return 0;
}
