#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>   //usado toupper

/* Escrever programa em C para cadastrar nome, 3 notas e
frequência dos alunos do projeto “AprendaProgramação”. São
três notas, e são aprovados todos os que ficam com média
acima 7 e têm frequência acima de 65%. Deve haver opção para
exibir o nome de cada aluno, seguido das notas, média e da
situação final: APROVADO ou REPROVADO.*/

/* Considerar que o curso ocorre ao longo de 18
semanas, as inscrições ocorrem antes do início
das aulas quando os alunos apresentam o nome, 
a 1a nota é definida na 6a semana, 
a 2a nota, na 12a semana e 
a 3a nota na 18a semana quando também é informada a
frequência e a relação de alunos com sua situação
final: APROVADO ou REPROVADO.? */

typedef struct Aluno{
		char nome [20];
		float notas[3];
		float frequencia;
		float media;
		char aprovacao [9];
} Aluno;

	FILE *ArqAluno;
	Aluno aluno;
	
	long int Tamanho = 20*sizeof(char) + 3*sizeof(float) + sizeof(int) + sizeof(float) + 9*sizeof(char);
	
	int semanasCurso = 18;
	
	// old script
	
	Aluno alunos [2];
	
	int quantidadeAlunos = sizeof(alunos) / sizeof(alunos[0]);
	int aulasMinistradas = 20;
	
void limparTela(){
  #ifdef _WIN32
    system("cls");
  #elif __linux__
    system("clear"); 
  #endif
}

long int TArquivo(){
	fseek(ArqAluno,0,2);
	long int R=ftell(ArqAluno)/Tamanho;
	return R;
}	
	
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);}

void pausar() {
    printf("\nPressione ENTER para continuar...\n");
    limpar_buffer();  // Limpa qualquer lixo no buffer
    getchar();}       // Agora espera o ENTER}

void printAluno(){

	printf("Aluno: %s\n",aluno.nome); 
	printf("Notas: %.2f %.2f %.2f\n",aluno.notas[0],aluno.notas[1],aluno.notas[2]);
	printf("Media: %.2f\n",aluno.media);
	printf("Frequencia: %.2f %%\n",aluno.frequencia);
	printf("Situacao Final: %s \n\n",aluno.aprovacao);
	
}

void inscreverAluno(){
	
	char R;
	do{
	
	printf("*** Inscricao ***\n\n");
	
	char nomeAluno [20];
	
	printf("Digite o nome do aluno: ");
	scanf("%s",nomeAluno);
	
	int Achou = 0;
	
	if (TArquivo()!=0){
		
		ArqAluno=fopen("alunos.dat","r+b");
		fseek(ArqAluno,0,0);
		
		while (!feof(ArqAluno)&&(Achou==0)){
			
			fread(&aluno,Tamanho,1,ArqAluno);
			
			if (strcmp(aluno.nome,nomeAluno)==0){
				Achou=1;
			}
			
		}
	
	}
	
	if (Achou==1){
		printf("Este aluno ja foi cadastrado em nosso sistema\n");
	}
    
    else {
		
    // Resto
    
    ArqAluno=fopen("alunos.dat","a+b");
    
    strcpy(aluno.nome,nomeAluno);
    
    fseek(ArqAluno,0,2);
    fwrite(&aluno,Tamanho,1,ArqAluno);
    
    }

    printf("\nNova inclusao? S/N ");
    scanf(" %c",&R);
    R=toupper(R);
}  
    while (R!='N');
	
	fclose(ArqAluno);
	return;

}

int exibirInfoAlunos(){
	
	limparTela();
	
	ArqAluno=fopen("alunos.dat","r+b");
	
	if (TArquivo()!=0){
		
		fseek(ArqAluno,0,0);
		
		while (!feof(ArqAluno)){
			
			fread(&aluno,Tamanho,1,ArqAluno);
			
			if (!feof(ArqAluno)){
				printAluno();
			}
			
		}
	
	}
	
	else {
      printf("\n\nArquivo Vazio. Nao existem dados a listar.");
      //pausar();
	}
	pausar();
	//fclose(ArqAluno);
	
	return 0;
	
}

int registrarNota(){
	
	char R;
	do{
	
	printf("*** Atribuir Nota ***\n\n");
	
	char nomeAluno [20];
	
	printf("Digite o nome do aluno: ");
	scanf("%s",nomeAluno);
	
	int Achou = 0;
	
	if (TArquivo()!=0){
		
		ArqAluno=fopen("alunos.dat","r+b");
		fseek(ArqAluno,0,0);
		
		while (!feof(ArqAluno)&&(Achou==0)){
			
			fread(&aluno,Tamanho,1,ArqAluno);
			
			if (strcmp(aluno.nome,nomeAluno)==0){
				Achou=1;
				printAluno();		
			}
			
		}
	
	}
	
	if (Achou==1){
	
		char notaEscolhida;
	
		printf("Qual nota deseja alterar? (1|2|3)\n");
		scanf(" %c",&notaEscolhida);
	
		if (notaEscolhida == '1'){
			printf("Digite a nota: ");
			scanf("%f",&aluno.notas[0]);
		}
		else if (notaEscolhida == '2'){
			printf("Digite a nota: ");
			scanf("%f",&aluno.notas[1]);
		}
		else if (notaEscolhida == '3'){
			printf("Digite a nota: ");
			scanf("%f",&aluno.notas[2]);
		}
	
		if (notaEscolhida == '1' || notaEscolhida == '2' || notaEscolhida == '3'){
			
			aluno.media = (aluno.notas[0] + 
						   aluno.notas[1] + 
						   aluno.notas[2]) / 3;	
    
			fseek(ArqAluno,-Tamanho,1);
			fwrite(&aluno,Tamanho,1,ArqAluno);
			printf("\nAlteracao efetuada com sucesso!\n");
    
		}
		
	}
    
    else {	
		printf("Registro inexistente!");
	}

    printf("\nNova inclusao? S/N ");
    scanf(" %c",&R);
    R=toupper(R);
}  
    while (R!='N');
	
	fclose(ArqAluno);
	
	//pausar();
	return 0;
	
}

int cadastrarFrequencia(){
	
	char R;
	do{
	
	printf("*** Atribuir Frequencia ***\n\n");
	
	char nomeAluno [20];
	
	printf("Digite o nome do aluno: ");
	scanf("%s",nomeAluno);
	
	int Achou = 0;
	
	if (TArquivo()!=0){
		
		ArqAluno=fopen("alunos.dat","r+b");
		fseek(ArqAluno,0,0);
		
		while (!feof(ArqAluno)&&(Achou==0)){
			
			fread(&aluno,Tamanho,1,ArqAluno);
			
			if (strcmp(aluno.nome,nomeAluno)==0){
				Achou=1;
				printAluno();		
			}
			
		}
	
	}
	
	if (Achou==1){
		printf("Digite a frequencia: ");
		scanf("%f",&aluno.frequencia);
		
			aluno.media = (aluno.notas[0] + 
						   aluno.notas[1] + 
						   aluno.notas[2]) / 3;	
		
		if (aluno.frequencia > 65 && aluno.media >= 7){
			strcpy(aluno.aprovacao,"APROVADO");
			printf("\nAlteracao efetuada com sucesso!\n");
		}
		else {
			strcpy(aluno.aprovacao,"REPROVADO");
			printf("\nAlteracao efetuada com sucesso!\n");
		}
				
		fseek(ArqAluno,-Tamanho,1);
		fwrite(&aluno,Tamanho,1,ArqAluno);		
	}
	
	else {	
		printf("Registro inexistente!");
	}
	
	printf("\nNova inclusao? S/N ");
    scanf(" %c",&R);
    R=toupper(R);
}  
    while (R!='N');
	
	fclose(ArqAluno);
	//pausar();
	
	return 0;
	
}

int main(){
	
	ArqAluno=fopen("alunos.dat","a+b");
	
	char escolha;	
	
	do {
		
		printf("\n\n### Aprenda Programacao ###\n\n");
		printf("(1) Inscrever Aluno\n");
		printf("(2) Registrar Nota\n");
		printf("(3) Cadastrar Frequencia\n");
		printf("(4) Exibir Situacao Final\n");
		printf("(S) Sair\n\n");
		scanf(" %c",&escolha);
		escolha = toupper(escolha);
		
	switch (escolha){
		case '1': inscreverAluno(); break;	
		case '2': registrarNota(); break;
		case '3': cadastrarFrequencia(); break;
		case '4': exibirInfoAlunos(); break;
		//default: printf("Opcao invalida\n"); 
	}
	
	} while (escolha != 'S');
	
	fclose(ArqAluno);
	
	return 0;
}
