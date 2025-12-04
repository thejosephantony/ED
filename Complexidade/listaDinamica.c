#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

void inserir_final(No **head, No **tail, int x) {
    No *novo = (No *)malloc(sizeof(No));   // 1
    novo->valor = x;                       // 1
    novo->prox = NULL;                     // 1

    if (*head == NULL) {                   // 1
        *head = novo;                      // 1
        *tail = novo;                      // 1
    } else {
        (*tail)->prox = novo;              // 1
        *tail = novo;                      // 1
    }
}

int main() {
    No *head = NULL;
    No *tail = NULL;

    inserir_final(&head, &tail, 10);
    inserir_final(&head, &tail, 20);
    inserir_final(&head, &tail, 30);

    return 0;
}

// O(1)
