#include "interface.h"

/**
@file main.c
Ficheiro principal que gera o programa
*/


int main(int argc, char const *argv[]){

    TAD_community com = init();

    com = load(com, "../dump/ubuntu");

    //testes(com);

    
    com = clean(com);
    (void)com;

    return 0;
}
