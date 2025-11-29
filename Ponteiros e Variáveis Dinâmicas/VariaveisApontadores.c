#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tipo{
        char Letra;
        int Ok;
    };

    typedef struct Tipo TipoVd;            // TipoVD é o tipo da variável dinâmica

int main(){
    TipoVd *P, *K;                         // P é do tipo apontador, contendo um endereço da variável dinâmica
    P = (TipoVd *)malloc(sizeof(TipoVd));
    printf("Letra: ");
    scanf(" %c", &P->Letra);
    P -> Ok = 10;
    K = P;
    K ->Ok = 30;
    K -> Letra = 'A';
    printf("Letra: %c\n", P->Letra);
    printf("Valor: %d\n", P->Ok);
    free(P);

    P = NULL;
    K = NULL;

    return 0;
}

