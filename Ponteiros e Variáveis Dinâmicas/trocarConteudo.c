/* Fac¸a um programa que leia 2 valores inteiros e chame uma func¸˜ ao que receba estas
 2 vari´ aveis e troque o seu conte´udo, ou seja, esta func¸˜ ao ´ e chamada passando duas
 vari´ aveis A e B por exemplo e, ap´ os a execuc¸˜ ao da func¸˜ ao, A conter´ a o valor de B e B
 ter´ a o valor de A. */

 #include <stdio.h>

 void troca(int *x, int *y){

     int temp = *x;
     *x = *y;
     *y = temp;

 }

 int main(){

     int A;
     int B;

     printf("Digite o valor de A: \n");
     scanf("%d", &A);

     printf("Digite o valor de B: \n");
     scanf("%d", &B);

     troca(&A, &B);

     printf("O valor de A apos a troca: %d\n", A);
     printf("O valor de B apos a troca: %d\n", B);



     return 0;

 }
