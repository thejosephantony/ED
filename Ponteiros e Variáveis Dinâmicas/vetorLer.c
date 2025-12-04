/*Fac¸a umprogramaqueleia dousu´ ario o tamanho de umvetoraserlido e fac¸a a alocac¸˜ ao
 dinˆ amica de mem´ oria. Em seguida, leia do usu´ ario seus valores e imprima o vetor lido.*/

 #include <stdio.h>
 #include <stdlib.h>


 int main(){
     int *vetor;
     int i;
     int N;

     printf("Qual o tamanho do vetor? \n");
     scanf("%d", &N);

     vetor = (int *)malloc(N*sizeof(int));

     if(vetor == NULL){
        printf("Erro ao alocar memoria");
        return 1;
     }

     printf("Digite os valores do vetor \n");

     for(int i = 0; i < N; i++){
        scanf("%d", &vetor[i]);
    }

     printf("O vetor eh: ");
     for(int i = 0; i < N; i++){
        printf("%d ", vetor[i]);
     }
     free(vetor);
     return 0;

 }
