// REVISÃO: PONTEIROS

// Variável - é um espaço armazenado na memória para guardar o valor que pode ser modificado pelo programa.

// Ponteiro - é um espaço armazenado na memória para guardar o endereço de memória de uma outra variável; Ponteiro não armazena o valor, mas sim o endereço de memória




#include <stdio.h>
#include <stdlib.h>


int main(){
    int c = 10;
    int *p;
    p = &c;

    printf("O valor apontado no ponteiro antes da modificacao: %d\n", *p);
    *p = 20;

    printf("O valor apontado no ponteiro apos a modificacao: %d\n", *p);
    printf("O valor de C apos a modificacao: %d\n", c);
    return 0;

}
