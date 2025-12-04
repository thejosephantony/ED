#include <stdio.h>
#include <string.h>

/* Escrever programa para ler uma string S com
até 15 caracteres e um caractere C, e exibir a
posição da primeira ocorrência de C em S.
Exemplo, se dado ROSANA e A, exibir 4.
IMPORTANTE: Para implementação desta não
pode ser usada função predefinida de
definição de primeira ocorrência de um
caractere numa string. */

int detectaOcorrencia(char str[15],char c){ // Funcao para detectar a ocorrencia de um caractere em uma string
	
	for (int i=0; i < strlen(str) ;i++){
		 if (str[i] == c){
			printf("%d",i+1);
			break;
		 }	
	}	
	
	return 0;	
}

int lerString(char str[15],char c){ // Input e depois chama detectaOcorrencia
	printf("Digite uma palavra: ");
	scanf("%s",str);
	printf("Digite uma letra: ");
	scanf(" %c",&c);
	detectaOcorrencia(str,c); 
	return 0;
}

int main(){
	
	char str[15]; // Na minha solução 's = str' pois 'str' é um nome mais significativo que 's'
	char c = ' '; // 
	
	lerString(str,c);
	return 0;
}
