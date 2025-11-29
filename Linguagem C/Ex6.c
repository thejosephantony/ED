#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define NUM_ALUNOS 80
#define NUM_NOTAS 3

struct Aluno{
    char nome[50];
    float notas[NUM_NOTAS];
    int frequencia;
    float media;
};

int main(){
    struct Aluno alunos[NUM_ALUNOS];
    float media_turma = 0;

    for(int i = 0; i < NUM_ALUNOS; i++){
        printf("----------CADASTRO DO ALUNO %d----------\n", i+ 1);
        printf("NOME:  \n");
        fgets(alunos[i].nome, 50, stdin);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;

        printf("Digite as tres notas: \n");
        for(int j = 0; j < NUM_NOTAS; j++){
            printf("NOTA %d\n", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }


        printf("FREQUENCIA: ");
        scanf("%d", &alunos[i].frequencia);

        alunos[i].media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2])/3;

        while(getchar() != '\n');


    }
     // CALCULA MÉDIA DA TURMA
    for(int i = 0; i < NUM_ALUNOS; i++) {
        media_turma += alunos[i].media;
    }
    media_turma /= NUM_ALUNOS;


    printf("----------RELATORIO FINAL DOS ALUNOS-----------\n");
    printf("A MEDIA DA TURMA: %.2f\n", media_turma);
    for(int k = 0; k < NUM_ALUNOS; k++){
        printf("ALUNO %d\n", k + 1);
        printf("NOME: %s\n", alunos[k].nome);
        printf("NOTAS: %.2f, %.2f, %.2f\n", alunos[k].notas[0], alunos[k].notas[1], alunos[k].notas[2]);
        printf("FREQUENCIA: %d\n", alunos[k].frequencia);
        printf("MEDIA: %.2f\n", alunos[k].media);

        if(alunos[k].media > media_turma && alunos[k].frequencia > 65){
            printf("SITUACAO FINAL: APROVADO!\n");
        }
        else{
            printf("SITUACAO FINAL: REPROVADO!\n");
        }
    }

    return 0;

}
