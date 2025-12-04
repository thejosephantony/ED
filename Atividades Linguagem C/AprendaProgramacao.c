#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Escrever programa em C para ler nome, 3 notas e
frequência dos 80 alunos do projeto
“AprendaProgramação”, calcular a média desses
(média da turma) e emitir em tela a situação final
de cada aluno. São aprovados todos os que ficam
com média (aritmética simples) acima da média da
turma e têm frequência acima de 65%. Deve ser
exibido o nome de cada aluno, seguido das notas,
média e da situação final: APROVADO ou
REPROVADO.*/

typedef struct Aluno{
		char nome [20];
		float notas[3];
		int faltas;
		float media;
		char* aprovacao;
} Aluno;
	
	Aluno alunos [2];
	int quantidadeAlunos = sizeof(alunos) / sizeof(alunos[0]);
	int aulasMinistradas = 20;

int lerInfoAluno(){ // Input nome ===> Digita as notas ===> Calcula a média do Aluno ===> Input faltas
	
	for (int n=0; n < quantidadeAlunos; n++) {
		
		printf("Digite o nome do aluno: ");
		scanf("%s",alunos[n].nome);
	
		for (int i=0; i < 3;i++){	
			printf("Digite a nota da avaliacao [%d]: ",i+1);
			scanf("%f",&alunos[n].notas[i]);
		}
		
		alunos[n].media = (alunos[n].notas[0] + 
						  alunos[n].notas[1] + 
						  alunos[n].notas[2]) / 3;						 
				
		printf("Digite a quantidade de faltas do aluno: ");
		scanf("%d",&alunos[n].faltas);
			
	}
	
	return 0;
}


int verificaAprovacao(){ // lerInfoAluno ===> atribui a média a cada aluno  ===> Gera a média da turma   ===> Calcula a frequencia dos alunos
	
		system("clear");
	
		float calculoFrequencia = 0;
		float calculoMedia = 0; 
		
		for (int n=0; n < quantidadeAlunos; n++){
			calculoMedia += alunos[n].media;
		}
		
		calculoMedia = calculoMedia / quantidadeAlunos;
	
		for (int n=0; n < quantidadeAlunos; n++){	// Acho que eu poderia separar em outra função "ExibirRelatorioAluno"
		
			calculoFrequencia = ((aulasMinistradas - alunos[n].faltas) * 100.0) / aulasMinistradas;
			
			printf("Aluno: %s\n",alunos[n].nome); 
			printf("Notas: %.2f %.2f %.2f\n",alunos[n].notas[0],alunos[n].notas[1],alunos[n].notas[2]);
			printf("Media: %.2f\n",alunos[n].media);
			printf("Frequencia: %.2f %%\n",calculoFrequencia);
			printf("Situacao Final: ");
				
			if (calculoFrequencia >= 65 && (alunos[n].media >= calculoMedia) ){
				printf("Aprovado\n\n");
			}
			
			else {
				printf("Reprovado\n\n");			
			}
		
		}
		
		printf("Media da Turma: %.2f",calculoMedia);
	
	
	return 0;
}

int main(){
	lerInfoAluno();
	verificaAprovacao();
	return 0;
} 
