#include <stdio.h>

/*Escrever um programa em C para ler um
número inteiro qualquer e retornar a que
mês do ano corresponde. Caso não haja
correspondência, exibir mensagem de erro.*/

int qualMesCorresponde(int numeroMes){
	
	switch (numeroMes){
		case 1: printf("Janeiro");
		break;
		case 2: printf("Fevereiro");
		break;
		case 3: printf("Março");
		break;
		case 4: printf("Abril");
		break;
		case 5: printf("Maio");
		break;
		case 6: printf("Junho");
		break;
		case 7: printf("Julho");
		break;
		case 8: printf("Agosto");
		break;
		case 9: printf("Setembro");
		break;
		case 10: printf("Outubro");
		break;
		case 11: printf("Novembro");
		break;
		case 12: printf("Dezembro");
		break;
		default: printf("[ERRO] Digite um numero entre 1 e 12!");
	}
	
	return 0;
}

int analisaNumInteiro(){ // Input e chama a função qualMesCorresponde
	int numero;
	printf("Digite um numero (1-12): ");
	scanf("%d",&numero);
	qualMesCorresponde(numero);
	return 0;
}

int main(){
	analisaNumInteiro();
}
