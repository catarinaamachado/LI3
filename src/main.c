#include <stdlib.h>
#include <stdio.h>
#include <gmodule.h>

#include "00load.h"
#include "struct.h"

int main(int argc, char const *argv[]){

  TAD_community com = init();

  com = load(com, "../android/");

  USER us;
  long id = 123;//atol(argv[1]);
  us = get_user_info(com, id);

  if (us != NULL) {

    printf("User %ld\nBio:\n%s\n", id, get_bio(us));

    long * posts = get_10_latest_posts(us);

    for (int i = 0; i < 10 && posts[i] != -1; i++) {

      printf("Post: %ld\n", posts[i]);

    }
  }

  else
    printf("No user\n");

  free(com);

  return 0;
}
