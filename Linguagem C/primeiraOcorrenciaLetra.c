#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    char string[16] = "";
    char caractere;
    int posicao = 0;

    printf("Digite a String: \n");
    scanf("%s", string);

    printf("Informe o caractere que quer procurar na string: \n");
    scanf(" %c", &caractere);                                     //O espaço antes do %c consome o \n anterior

    for(int i = 0; string[i] != '\0'; i++){
        if (string[i] == caractere){
            posicao = i + 1;
            break;
        }
    }
    if (posicao != 0){
    printf("A primeira ocorrencia eh %d\n", posicao);
    }
    else{
        printf("O caractere nao foi encontrado\n");
    }

    return 0;

}
