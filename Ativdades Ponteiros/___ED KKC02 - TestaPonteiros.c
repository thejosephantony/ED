#include <stdio.h>
#include <stdlib.h> //usado malloc
#include <string.h> //usado strcpy 
#include <ctype.h> //usado toupper

/*Ajustar código de
forma a exibir os dados
na ordem dada pelo
usuário*/


int main(){
	
      struct tipo{
	  char Palavra[20];
	  void *Prox; 
  };
  
  typedef struct tipo TIPO;
  
  TIPO *Inicio, *Auxiliar, *Anterior;
  char Palavra[20],selecao='S';

  Inicio=NULL;
  
  printf("--- Acumulador de palavras ---\n");
	
  while (selecao == 'S' || selecao == 's'){  
	   
	  // Input Inicial
	  
	  printf("Digite uma palavra: ");
	  scanf(" %s",Palavra);
	  printf("\n");
	  Auxiliar=(TIPO *) malloc(sizeof(TIPO));
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
