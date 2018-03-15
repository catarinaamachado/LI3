#include <stdlib.h>
#include <stdio.h>
#include <gmodule.h>

#include "00load.h"
#include <struct.h>

int main(){

  TAD_community com = init();

  com = load(com, "../android/");

  Users u;

  // for (int i = 1; i <= 245699; i++) {
  //     u = lookUsers(com, i);

  //     if(u != NULL) {
  //       printf("Id: %ld\nName: %s\nBio: %s\nReputation: %d", getUserId(u), getUsername(u), getBio(u), getReputation(u));
  //       printf("\n");

  //       printf("NP: %d\n", getNPosts(u));


  //       // for (int l = 0; l < getNPosts(u) && l < 10; l++) {

  //       //   postDate pd = g_array_index(u->last_posts, postDate, l);

  //       //   printf("Post Id: %ld\n", gt);
  //       //   // printf("%d-%d-%d\n%d:%d:%d.%d\n\n",
  //       //   //           pd->year, pd->month, pd->day, pd->hour, pd->min, pd->sec, pd->mili);

  //       // }

  //       printf("\n\n");
  //     }
  //   }

  free(com);

  return 0;
}
