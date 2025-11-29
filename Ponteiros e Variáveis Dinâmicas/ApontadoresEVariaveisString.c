#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct TpReg {
    char Simbolo;
    struct TpReg *Prox;  // Correto: ponteiro para o mesmo tipo
};

typedef struct TpReg TpLetra;

int main() {
    TpLetra *Anterior, *Atual;
    char Dado;

    Anterior = NULL;

    printf("Digite caracteres ( '*' para parar): ");
    scanf(" %c", &Dado);

    while(Dado != '*') {
        Atual = (TpLetra*)malloc(sizeof(TpLetra));
        if (Atual == NULL) {
            printf("Erro de alocação de memória!\n");
            return 1;
        }

        Atual->Simbolo = Dado;
        Atual->Prox = Anterior;  // Aponta para o elemento anterior
        Anterior = Atual;        // Atual se torna o novo topo

        scanf(" %c", &Dado);
    }

    //  CORRETO: Percorrer a pilha a partir do topo (Anterior)
    printf("Pilha (do topo para a base): ");
    Atual = Anterior;  // Começar do topo da pilha

    while(Atual != NULL) {  //  Condição correta
        printf(" %c", Atual->Simbolo);
        Atual = Atual->Prox;  // Avança para o próximo
    }
    printf("\n");

    //  LIBERAR MEMÓRIAA (importante!)
    Atual = Anterior;
    while(Atual != NULL) {
        TpLetra *Temp = Atual;
        Atual = Atual->Prox;
        free(Temp);
    }

    return 0;
}
