 #include <stdio.h>
//Qual a ordem de complexidade de tempo do algoritmo dado abaixo? //

 int main(){
 float Distancia, Tempo;                         // 0
 printf("Qual a distancia percorrida (em m)? ");  // 0
 scanf("%f",&Distancia);                          // 1
 printf("Qual o intervalo de tempo (em s)? ");    // 0
 scanf("%f",&Tempo);                              // 1
 printf("Resultado: %.2fm/s.\n",Distancia/Tempo); // 1
 return 0;

 }
 // O(1)- constante
