/*Ajustar código de
forma a exibir os dados
na ordem dada pelo usuário.*/

#include <stdio.h>
#include <stdlib.h> //usado malloc
#include <string.h> //usado strcpy
#include <ctype.h> //usado toupper


// (levando a entender que a ordem dada pelo usuario seja a sequencia digitada)

int main(){

      struct tipo{                  // a estrutura aponta para um nó da lista
	  char Palavra[20];             // armazena a palavra
	  struct tipo *Prox;            // o ponteiro aponta para o proximo elem da lista
  };

  typedef struct tipo TIPO;

  TIPO *Inicio, *Auxiliar, *Anterior;             // declara os ponteiros para manipular a lista
  char Palavra[20],selecao='S';                  // variaveis de entrada

  Inicio=NULL;                   // inicializa a lista como vazia

  printf("--- Acumulador de palavras ---\n");

  while (selecao == 'S' || selecao == 's'){              // enquanto o usuario digitar 'S' ou 's' o loop continua

	  // Input Inicial

	  printf("Digite uma palavra: ");
	  scanf(" %s",Palavra);
	  printf("\n");
	  Auxiliar=(TIPO *) malloc(sizeof(TIPO));                  // aloca a memoria
	  strcpy(Auxiliar->Palavra,Palavra);
	  Auxiliar->Prox = NULL;

	  // Logica

	  if (Inicio == NULL){ // primeiro elemento
         Inicio = Auxiliar;
      }
      else {
		Anterior -> Prox = Auxiliar; // liga o ultimo no ao novo
	  }

	  Anterior = Auxiliar; // atualiza o último nó
	  Auxiliar = Inicio;

	  // Output

	  while (Auxiliar != NULL){
		printf(" %s ",Auxiliar -> Palavra);
		Auxiliar = Auxiliar -> Prox;
	  }

	  // Pós output

	  printf("\n \nDigite S se deseja continuar: ");
	  scanf(" %c",&selecao);
	  printf("\n\n");


  }

}
