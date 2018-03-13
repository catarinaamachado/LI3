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
  //     printf("Q: Id: %d, User id: %ld, Title: %s, N Respostas: %d, N Votos nas Respostas %d\n",
  //     q->post_id, q->user_id, q->title, q->n_answers, q->n_answer_votes);

  //     for(int l = 0; l < q->n_answers; l++) {

  //       a = g_ptr_array_index(q->answers, l);

  //       if(a != NULL)
  //         printf("  A: Id: %d, Score: %d\n", a->answer_id, a->score);
  //     }

  //   printf("\n\n");
  //   }
  // }

  // for (int i = 0; i <= 245699; i++) {
  //     u = g_hash_table_lookup (com->users, GINT_TO_POINTER(i));

  //     if(u != NULL) {
  //       //printf("Id: %d\nName: %sBio: %s\nReputation: %d", u->user_id, u->username, u->shortbio, u->reputation);
  //       printf("Id: %ld\n", u->user_id);
  //       printf("\n");

  //       printf("NP: %d\n", u->n_posts);


  //       for (int l = 0; l < u->n_posts && l < 10; l++) {
  //         postDate pd = g_array_index(u->last_10posts, postDate, l);
  //         printf("Post Id: %ld\n", pd->post_id);
  //         printf("%d-%d-%d\n%d:%d:%d.%d\n\n", 
  //                   pd->year, pd->month, pd->day, pd->hour, pd->min, pd->sec, pd->mili);
        
  //       }

  //       printf("\n\n");
  //     }
  //   }

  USER us;
  us = get_user_info(com, 152);

  printf("User 3\nBio:\n%s\n", get_bio(us));

  long * posts = get_10_latest_posts(us);

  for (int i = 0; i < 10 && posts[i] != -1; i++) {
  
    printf("Post: %ld\n", posts[i]);
  
  }

  //TODO criar função para libertar a memória de todas as estruturas
  free(com);

  return 0;
}