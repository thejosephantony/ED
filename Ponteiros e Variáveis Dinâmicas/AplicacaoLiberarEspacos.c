// Ajustar códigode forma a liberar os espaços de memória a medida que estes não forem mais úteis.

#include <stdio.h>
#include <stdlib.h>

struct TpReg {
    char Simbolo;
    void *Prox;
};

typedef struct TpReg TpLetra;

int main() {
    TpLetra *Anterior, *Atual;
    char Dado;

                                                    // pede ao usuario os caracteres
    Anterior = NULL;
    printf("Digite caracteres ('*' para parar): ");
    scanf(" %c", &Dado);

                                                    // se o caractere digitador for * '*' entrar no loop do While

    while (Dado != '*') {
        Atual = (TpLetra*)malloc(sizeof(TpLetra));
        Atual->Simbolo = Dado;
        Atual->Prox = Anterior;
        Anterior = Atual;
        scanf(" %c", &Dado);
    }

                                                    // Imprime e libera
    printf("Pilha (imprimindo e liberando): ");
    Atual = Anterior;                               // começar do topo da fila

    while (Atual != NULL) {
                                                    // Imprime o elemento atual
        printf(" %c", Atual->Simbolo);

                                                    // Salvar referência para o próximo elemento
        TpLetra *Proximo = (TpLetra*)Atual->Prox;

                                                    //  Liberar o elemento atual
        free(Atual);

                                                    // Avança para o próximo elemento
        Atual = Proximo;
    }
    printf("\n");

                                                    // Todos os caracteres já foram liberados
    Anterior = NULL;                                // anular ponteiro

    return 0;
}
