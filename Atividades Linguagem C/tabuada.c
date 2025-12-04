#include <stdio.h>

/*Escrever um programa em C para ler um
número n e exibir a tabuada de multiplicar de
n (em forma tabular) de 0 a 10. Ao final da
exibição, perguntar ao usuário se ele deseja
obter a tabuada de outro número. deve ser
exibida a tabuada de tantos números quantos
o usuário desejar (uma por vez).*/

int exibirNumero(int numero){
	int i = 0;
	while (i <= 10){
		printf("%d x %d = %d\n",numero,i,numero*i);
		i++;
	}
	return 0;
}

int lerNumero(int numero, char confirmacao){ // Input depois executa a função principal "exibirNumero" 
	printf("Digite um numero inteiro: ");
	scanf("%d",&numero);
	exibirNumero(numero);
	
	printf("Digite 'S' se deseja obter a tabuada de outro numero."); 
	scanf(" %c",&confirmacao);
	
	if (confirmacao == 'S' || confirmacao == 's'){
		lerNumero(numero,confirmacao);
	}
	
	return 0;
}


int main(){	
	int n = 0;
	char confirmacao = 'N';	
	lerNumero(n,confirmacao);
	
	return 0;	
}
