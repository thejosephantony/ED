/*Fac¸a um programa que leia dois valores inteiros e chame uma func¸˜ ao que receba estes
 2 valores de entrada e retorne o maior valor na primeira vari´ avel e o menor valor na
 segunda vari´ avel. Escreva o conte´udo das 2 vari´ aveis na tela.*/

 #include <stdio.h>

 void maiorEmenor(int *x, int *y){
     int temp = *x;
     if(*y > *x){
        *x = *y;
        *y = temp;
     }

 }

 int main(){
     int a;
     int b;

     printf("Digite o primeiro valor: \n");
     scanf("%d", &a);

     printf("Digite o segundo valor: \n");
     scanf("%d", &b);

     maiorEmenor(&a, &b);

     printf("O conteudo do primeiro valor: %d\n", a);
     printf("O conteudo do segundo valor: %d\n", b);

     return 0;


 }

