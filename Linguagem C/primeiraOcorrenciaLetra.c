/*Escrever programa para ler uma string S com
até 15 caracteres e um caractere C, e exibir a
posição da primeira ocorrência de C em S.
Exemplo, se dado ROSANA e A, exibir 4.
IMPORTANTE: Para implementação desta não
pode ser usada função predefinida de
definição de primeira ocorrência de um
caractere numa string.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
    char string[16] = "";                                         // array de caracteres
    char caractere;
    int posicao = 0;

    printf("Digite a String: \n");                                // pede ao usuario digitar a string
    scanf("%s", string);                                          // le a string digitada

    printf("Informe o caractere que quer procurar na string: \n"); // pede para o usuario digitar o caractere que quer encontrar
    scanf(" %c", &caractere);                                     //le o caractere. o espaço antes do %c consome o \n anterior

    for(int i = 0; string[i] != '\0'; i++){                       // estrutura de repeticao para percorrer a string buscando o caractere
        if (string[i] == caractere){
            posicao = i + 1;                                     // incrementa para a prox posicao. começa na posicao 1, e não 0.
            break;                                               // o break funciona aq para interromper o laço quando o caractere for encontrado
        }
    }
    if (posicao != 0){                                           // estrutura condicional para informar a primeira posicao do caractere na palavra
    printf("A primeira ocorrencia eh %d\n", posicao);
    }
    else{
        printf("O caractere nao foi encontrado\n");              // aq informa quando o caractere não for achado
    }

    return 0;

}
