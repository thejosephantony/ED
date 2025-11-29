#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ponteiro é uma variável que armazena o endereço de memória de outra variável.

int main(){
    int x = 10;
    int *ptr;   // o endereço '&' retorna o endereço de uma variável. o operador * acessa o endereço apontado e tbm significa que a variável é um ponteiro.
    ptr = &x;

    printf("Valor: %d\n", x);
    printf("Endereco: %d\n", &x);
    printf("Ponteiro: %d\n", ptr);
    printf("Valor via ponteiro: %d\n", *ptr);

    return 0;
}
