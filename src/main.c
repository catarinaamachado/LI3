#include <stdlib.h>
#include <stdio.h>
#include <gmodule.h>

#include "00load.h"
#include "struct.h"

int main(int argc, char const *argv[]){

  TAD_community com = init();

  com = load(com, "../android/");
  int i = 0;

  for (GList * l = getQuestions(com); l != NULL; l = l->next) {
    if(i != 0)
      return 0;
    Questions q = l->data;

    printf("%ld\n", getQuestionId(q));
    printf("%s\n\n", getQDate(q));

    i++;
  }

/*
  STR_pair ola = info_from_post(com, 197);
  char * fst = get_fst_str(ola);
  char * snd = get_snd_str(ola);

  printf("Title: %s\nUsername: %s\n", fst, snd);
*/

  // LONG_list ll = contains_word(com, "root", 10);
  // for(int i = 0; i < 10; i++) {
  //   long v = get_list(ll, i);
  //   printf("%ld\n\n", v);
  // }

  free(com);

  return 0;
}
