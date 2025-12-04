#include <stdio.h>

/*Escrever um programa em C para ler um
número inteiro qualquer e classificá-lo
como para o ímpar.
Linguagem C*/

char* calculaParidade(int n){
	if ((n % 2) == 0){
		return "Par";
	}
	else
		return "Impar";
}

int main(){
	
	int numero;
	printf("--- Calculadora de Paridade ---\n\n");
	printf("Digite um numero inteiro: ");
	scanf("%d",&numero);
	printf("Este numero eh: %s", calculaParidade(numero));
		
	return 0;
}

