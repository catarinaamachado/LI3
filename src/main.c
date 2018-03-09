#include <stdlib.h>
#include <stdio.h>
#include <gmodule.h>


#include "00load.h"
#include "init.h"

int main(){

  TAD_community com = init();

  com = load(NULL, "../../android");
  
  free(com);
  
  return 0;
} 
