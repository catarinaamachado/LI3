#include <stdio.h>
#include "interface.h"

#include "testes.h"

/**
@file main.c
*/


int main(int argc, char const *argv[]){

    TAD_community com = init();

    com = load(com, "../dump/ubuntu");

    testes(com);


    com = clean(com);
    (void)com;

    return 0;
}
