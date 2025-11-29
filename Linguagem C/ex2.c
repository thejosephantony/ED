#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Escrever um programa em C para ler um número inteiro qualquer e retornar a que mês do ano corresponde. Caso não haja correspondência, exibir mensagem de erro.


int main(){
    int num;                                   // cria a variável num;
    printf("Digite um numero inteiro: \n");    // pede para o usuário inserir um valor inteiro;
    scanf("%d", &num);                         // lê o valor digitado pelo usuário e o armazena na variavel num

    switch(num){                               // avalia o valor da variavel de memória e vai comparando com cada case
    case 1:
        printf("Janeiro\n");
        break;                                 // sai do switch, impede a execução dos cases seguintes
    case 2:
        printf("Fevereiro\n");
        break;
    case 3:
        printf("Marco\n");
        break;
    case 4:
        printf("Abril\n");
        break;
    case 5:
        printf("Maio\n");
        break;
    case 6:
        printf("Junho\n");
        break;
    case 7:
        printf("Julho\n");
        break;
    case 8:
        printf("Agosto\n");
        break;
    case 9:
        printf("Setembro\n");
        break;
    case 10:
        printf("Outubro\n");
        break;
    case 11:
        printf("Novembro\n");
        break;
    case 12:
        printf("Dezembro\n");
        break;
    default:                                       // caso de erro, tratamento de exceção, quando o numero não corresponde a nenhum case
        printf("Mes invalido\n");
    }

    return 0;

}
