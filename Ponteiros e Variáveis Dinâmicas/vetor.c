/*Crie um programa que:
 (a) Aloque dinamicamente um array de 5 n´umeros inteiros,
 (b) Pec¸a para o usu´ ario digitar os 5 n´umeros no espac¸o alocado,
 (c) Mostre na tela os 5 n´umeros,
 (d) Libere a mem´ oria alocada.*/

 #include <stdio.h>
 #include <stdlib.h>

 int main(){

     int *vetor;
     int i;

     vetor = (int *)malloc(5*sizeof(int));

     if (vetor == NULL){
        printf("Erro ao alocar memoria\n");
        return 1;
     }

     for(i = 0; i < 5; i++){
        printf("Digite o numero na posicao %d: \n", i);
        scanf("%d", &vetor[i]);
     }

     printf("o vetor eh: ");
     for(int i = 0; i < 5; i++){
        printf("%d ", vetor[i]);
     }
     free(vetor);
     return 0;


 }
