#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    int venda;                 // armazena de forma temporaria o valor das vendas
    int totalVendedor1 = 0;    //totalVendedor1-12 inicia as vendas de cada vendedor com 0
    int totalVendedor2 = 0;
    int totalVendedor3 = 0;
    int totalVendedor4 = 0;
    int totalVendedor5 = 0;
    int totalVendedor6 = 0;
    int totalVendedor7 = 0;
    int totalVendedor8 = 0;
    int totalVendedor9 = 0;
    int totalVendedor10 = 0;
    int totalVendedor11 = 0;
    int totalVendedor12 = 0;
    int totalLoja;            // armazena o total de vendas na loja


    for(int i = 1; i <= 5; i++){                                    // inicialização; condição; incremento;
        printf("O vendedor 1 vendeu quantos na secao %d?\n", i);
        scanf("%d", &venda);
        totalVendedor1 = totalVendedor1 + venda;
    }
    for(int i = 1; i <= 5; i++){
        printf("O vendedor 2 vendeu quantos na secao %d?\n", i);
        scanf("%d", &venda);
        totalVendedor2 = totalVendedor2 + venda;
    }
    for(int i = 1; i <= 5; i++){
        printf("O vendedor 3 vendeu quantos na secao %d?\n", i);
        scanf("%d", &venda);
        totalVendedor3 = totalVendedor3 + venda;
    }
    for(int i = 1; i <= 5; i++){
        printf("O vendedor 4 vendeu quantos na secao %d?\n", i);
        scanf("%d", &venda);
        totalVendedor4 = totalVendedor4 + venda;
    }
    for(int i = 1; i <= 5; i++){
        printf("O vendedor 5 vendeu quantos na secao %d?\n", i);
        scanf("%d", &venda);
        totalVendedor5 = totalVendedor5 + venda;
    }
    for(int i = 1; i <= 5; i++){
        printf("O vendedor 6 vendeu quantos na secao %d?\n", i);
        scanf("%d", &venda);
        totalVendedor6 = totalVendedor6 + venda;
    }
    for(int i = 1; i <= 5; i++){
        printf("O vendedor 7 vendeu quantos na secao %d?\n", i);
        scanf("%d", &venda);
        totalVendedor7 = totalVendedor7 + venda;
    }
    for(int i = 1; i <= 5; i++){
        printf("O vendedor 8 vendeu quantos na secao %d?\n", i);
        scanf("%d", &venda);
        totalVendedor8= totalVendedor8 + venda;
    }
    for(int i = 1; i <= 5; i++){
        printf("O vendedor 9 vendeu quantos na secao %d?\n", i);
        scanf("%d", &venda);
        totalVendedor9 = totalVendedor9 + venda;
    }
    for(int i = 1; i <= 5; i++){
        printf("O vendedor 10 vendeu quantos na secao %d?\n", i);
        scanf("%d", &venda);
        totalVendedor10 = totalVendedor10 + venda;
    }
    for(int i = 1; i <= 5; i++){
        printf("O vendedor 11 vendeu quantos na secao %d?\n", i);
        scanf("%d", &venda);
        totalVendedor11 = totalVendedor11 + venda;
    }
    for(int i = 1; i <= 5; i++){
        printf("O vendedor 12 vendeu quantos na secao %d?\n", i);
        scanf("%d", &venda);
        totalVendedor12 = totalVendedor12 + venda;
    }

    totalLoja = (totalVendedor1 + totalVendedor2 + totalVendedor3 + totalVendedor4 + totalVendedor5 + totalVendedor6 + totalVendedor7 + totalVendedor8 + totalVendedor9 + totalVendedor10 + totalVendedor11 + totalVendedor12);
    printf("O total do vendedor 1 foi de: %d\n", totalVendedor1);
    printf("O total do vendedor 2 foi de: %d\n", totalVendedor2);
    printf("O total do vendedor 3 foi de: %d\n", totalVendedor3);
    printf("O total do vendedor 4 foi de: %d\n", totalVendedor4);
    printf("O total do vendedor 5 foi de: %d\n", totalVendedor5);
    printf("O total do vendedor 6 foi de: %d\n", totalVendedor6);
    printf("O total do vendedor 7 foi de: %d\n", totalVendedor7);
    printf("O total do vendedor 8 foi de: %d\n", totalVendedor8);
    printf("O total do vendedor 9 foi de: %d\n", totalVendedor9);
    printf("O total do vendedor 10 foi de: %d\n", totalVendedor10);
    printf("O total do vendedor 11 foi de: %d\n", totalVendedor11);
    printf("O total do vendedor 12 foi de: %d\n", totalVendedor12);

    printf("O total da loja foi de %d\n", totalLoja);

    return 0;

}
