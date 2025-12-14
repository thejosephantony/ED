#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Escrever um programa em C para ler um numero inteiro qualquer e classificá-lo como para o ímpar.

int main(){
    int num;

    printf("Insira um numero: \n");      //pede para o usuario inserir um valor
    scanf("%d", &num);                   // lê o valor digitado pelo usuario e o armazena na variável de memória

    if (num % 2 != 0){                           // verifica se o resto da divisao é igual a 1, caso seja, diz que o numero é impar
        printf("O numero %d eh impar.\n", num);
    }
    else{
        printf("O numero %d eh par.\n", num);    // caso o primeiro if seja falso, o else declara que o numero eh par.
    }
    return 0;
}
