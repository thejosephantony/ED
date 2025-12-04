#include <stdio.h>
#include <stdlib.h>  //usado system
#include <ctype.h>   //usado toupper
#include <string.h>  //usado strcmp

struct TpFarma{
	char Nome[20];
	float Preco;
	int QEstoque;
  };
  
typedef struct TpFarma TpFARMA;

TpFARMA RgFarma;
  
FILE *ArqFarma;

long int Tamanho=20*sizeof(char)+sizeof(float)+sizeof(int);

// Para limpar o codigo

void exibeFarmaco(){
	printf("Nome: %s\n",RgFarma.Nome);
    printf("Valor: %f\n",RgFarma.Preco);
    printf("Estoque: %d\n",RgFarma.QEstoque);
}

void limparTela(){
  #ifdef _WIN32
    system("cls");
  #elif __linux__
    system("clear"); 
  #endif
}

// Funcoes Auxiliares

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);}

void pausar() {
    printf("\nPressione ENTER para continuar...\n");
    limpar_buffer();  // Limpa qualquer lixo no buffer
    getchar();}       // Agora espera o ENTER}
    
long int TArquivo(){
	fseek(ArqFarma,0,2);
	long int R=ftell(ArqFarma)/Tamanho;
	return R;}
	
// Funcoes Principais

void Incluir() {
  char R;
  do{
    limparTela();
    printf("*** inclusao ***\n\n");
    printf("Nome: ");
    
    char Farmaco[20];
	scanf("%s",Farmaco);
    
    int Achou=0;
    
    // Logica
    
    if (TArquivo()!=0){
		
		ArqFarma=fopen("Famacos.dat","r+b");
		fseek(ArqFarma,0,0);
		
		while (!feof(ArqFarma)&&(Achou==0)){
			
			fread(&RgFarma,Tamanho,1,ArqFarma);
			
			if (strcmp(RgFarma.Nome,Farmaco)==0){
				Achou=1;
			}
			
		}
	
	}
	
	if (Achou==1){
		printf("Este Farmaco ja foi cadastrado em nosso sistema");
	}
    
    else {
		
    // Resto
    
    ArqFarma=fopen("Famacos.dat","a+b");
    
    strcpy(RgFarma.Nome,Farmaco);
    printf("Preco: ");    
    scanf("%f",&RgFarma.Preco);
    printf("Estoque: ");
    scanf("%d",&RgFarma.QEstoque);
    fseek(ArqFarma,0,2);
    fwrite(&RgFarma,Tamanho,1,ArqFarma);
    
    }

    printf("\nNova inclusao? S/N ");
    scanf(" %c",&R);
    R=toupper(R);
    
} 
    while (R!='N');
    
    fclose(ArqFarma);
	return;
  
}

void Excluir(){
	
	if (TArquivo()!=0){
	
	ArqFarma=fopen("Famacos.dat","r+b");
	limparTela();//system("clear");
	printf("*** Excluir ***\n\n"); 
	printf("Qual farmaco? ");
	char Farmaco[20];
	scanf("%s",Farmaco);
	
	fseek(ArqFarma,0,0);
	int Achou=0;
	
	do {
	
	fread(&RgFarma,Tamanho,1,ArqFarma);
	
	if (strcmp(RgFarma.Nome,Farmaco)==0){
	  Achou=1;
	}
	
	else {

    } 
    
    }
    while (!feof(ArqFarma)&&(Achou==0));
		
	if (Achou==0)
		printf("Registro inexistente!");
		
	else {		
	  strcpy(RgFarma.Nome,"Excluido");
	  RgFarma.Preco = 0.0;
	  RgFarma.QEstoque = 0;
	  fseek(ArqFarma,-Tamanho,1);
	  fwrite(&RgFarma,Tamanho,1,ArqFarma);
      printf("\nExclusao efetuada com sucesso!\n");
	}

	pausar();	
	}
	
	else{
    printf("\n\nArquivo Vazio.  Nao existem dados a alterar.");
    pausar();
    }
	
	fclose(ArqFarma);
	ArqFarma=fopen("Famacos.dat","a+b");
	return;

}
	
void Alterar(){
  
  if (TArquivo()!=0){
  
	fclose(ArqFarma);
	ArqFarma=fopen("Famacos.dat","r+b");
	limparTela();
  
	printf("*** alterar ***\n\n");  
	fseek(ArqFarma,0,0);
	printf("Qual farmaco? ");
	char Farmaco[20];
	scanf("%s",Farmaco);
	int Achou=0;
  
  do {
	fread(&RgFarma,Tamanho,1,ArqFarma);
	
	if (strcmp(RgFarma.Nome,Farmaco)==0){
	  Achou=1;	
      exibeFarmaco();
      }
     }
      
  while (!feof(ArqFarma)&&(Achou==0));
  
  if (Achou==0)
    printf("Registro inexistente!"); 
    
  else {
    printf("Qual o novo preco? \n"); 
    scanf("%f",&RgFarma.Preco);
    printf("Qual a nova quantidade? \n");
    scanf("%d",&RgFarma.QEstoque);
    fseek(ArqFarma,-Tamanho,1);
    fwrite(&RgFarma,Tamanho,1,ArqFarma);
    printf("\nAlteracao efetuada com sucesso!\n");
  }
    pausar();
  }
  
  else {
    printf("\n\nArquivo Vazio.  Nao existem dados a alterar.");
    pausar();
  }
  
  fclose(ArqFarma);
  ArqFarma=fopen("Famacos.dat","a+b");
  return;}

void Consultar() {
  if (TArquivo()==0){
      printf("\n\nArquivo Vazio.  Nao existem dados a consultar.");
      pausar();
  }
  else{
	  limparTela();
	  printf("*** consulta ***\n\n");  
	  fseek(ArqFarma,0,0);
	  printf("Qual farmaco? ");
	  char Farmaco[20];
	  scanf("%s",Farmaco);
	  int Achou=0;
  do {
	fread(&RgFarma,Tamanho,1,ArqFarma);
	if (strcmp(RgFarma.Nome,Farmaco)==0){
	  Achou=1;
	  exibeFarmaco();
      }
  }
    while (!feof(ArqFarma)&&(Achou==0));
  if (Achou==0){
    printf("\nRegistro inexistente!");}  
	pausar();
  }
  return;}

void LTodos() {
	
  ArqFarma=fopen("Famacos.dat","a+b"); // Para garantir que funcione quando a função for chamada
	
  if (TArquivo()==0){
      printf("\n\nArquivo Vazio.  Nao existem dados a listar.");
      pausar();
  }
  
  else {
	limparTela();
	printf("*** lista todos ***\n\n");  
	fseek(ArqFarma,0,0);
	
  do {
	fread(&RgFarma,Tamanho,1,ArqFarma);
	
	if (!feof(ArqFarma) && strcmp(RgFarma.Nome,"Excluido")!=0){
		exibeFarmaco();
		printf("***\n\n");
    }
    }
    while (!feof(ArqFarma));
		pausar();
	}
  
  return;
  
}

int main(){
  ArqFarma=fopen("Famacos.dat","a+b");
  char Opcao;
  do{
	limparTela();
    printf("\n\n> > > Pague Pouco < < < \n\n");
    printf("Que deseja fazer? \n\n");
    printf("I - Incluir \n");  
    printf("E - Exluir \n");
    printf("A - Alterar \n");
    printf("C - Consultar \n");
    printf("T - Listar Todos \n");
    printf("S - Sair \n\n");
    printf("Opcao: ");
    scanf(" %c", &Opcao);
    Opcao=toupper(Opcao);
    switch (Opcao){
      case 'I': Incluir(); break;
      case 'E': Excluir(); break;
      case 'A': Alterar(); break;
      case 'C': Consultar(); break;
      case 'T': LTodos(); break;}}
  while (Opcao != 'S');
  fclose(ArqFarma);
  return 0;}
