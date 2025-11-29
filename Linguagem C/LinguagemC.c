#include <stdio.h>

int main(){
    int a;
    int b;
    int soma;
    int subtracao;
    int multiplicacao;
    int divisao;

// Entrada de dados
    printf("Digite o primeiro numero: ");
    scanf("%d", &a);
    printf("Digite o segundo numero: ");
    scanf("%d", &b);

// Operações básicas
    soma = a + b;
    subtracao = a - b;
    multiplicacao = a * b;

    printf("Os resultados das operacoes aritmeticas sao: \n");
    printf("Soma: %d\n", soma);
    printf("Subtracao: %d\n", subtracao);
    printf("Multiplicacao: %d\n", multiplicacao);

// Divisão com verificação
    if(b == 0){
        printf("Nao existe divisao por zero!\n");}
        else{
            divisao = a/b;
            printf("Divisao: %d\n", divisao);
        }

    // Verificação par/ímpar
    if(a % 2 == 0){
        printf("O numero %d eh par\n", a);
    }
    else{
        printf("O numero %d eh impar\n", a);
    }

    if(b % 2 == 0){
        printf("O numero %d eh par\n", b);
    }
    else{
        printf("O numero %d eh impar\n", b);
    }

        return 0;
    }

