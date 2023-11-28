#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    char nome[100];
    char data[100];
    char curso[100];
    char periodo[7];
    int conclusao;
    float cr;
};

Aluno** CriaVetorAlunos(int numeroAlunos){
    Aluno** lista = malloc(numeroAlunos*sizeof(Aluno*));
    for(int i=0; i<numeroAlunos; i++){
        lista[i] = NULL;
    }
    return lista;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA){
    Aluno* aluno = malloc(sizeof(Aluno));
    strcpy(aluno->nome, nome);
    strcpy(aluno->data, dtNasc);
    strcpy(aluno->curso, cursoUfes);
    strcpy(aluno->periodo, periodoIngresso);
    aluno->conclusao = percConclusao;
    aluno->cr = CRA;

    return aluno;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos){
    for(int i=0; i<numeroAlunos; i++){
        char nome[100], data[100], curso[100], periodo[100];
        int conclusao;
        float cr;
        scanf("%*c%[^\n]\n", nome);
        scanf("%[^\n]\n", data);
        scanf("%[^\n]\n", curso);
        scanf("%[^\n]\n", periodo);
        scanf("%d\n", &conclusao);
        scanf("%f\n", &cr);
        vetorAlunos[i] = CriaAluno(nome, data, curso, periodo, conclusao, cr);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos){
    for(int i=0; i<numeroAlunos; i++){
        free(alunos[i]);
    }
    free(alunos);
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos){
    int total = 0;
    FILE* arq = NULL;
    arq = fopen(fileName, "wb");
    total += fwrite(&numeroAlunos, sizeof(int), 1, arq);
    for(int i=0; i<numeroAlunos; i++){
        total += fwrite(alunos[i], sizeof(Aluno), 1, arq);
    }
    fclose(arq);
    printf("Numero de bytes salvos: %d\n", total);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName){
    int numeroAlunos = 0;
    FILE* arq = NULL;
    arq = fopen(fileName, "rb");
    fread(&numeroAlunos, sizeof(int), 1, arq);
    for(int i=0; i<numeroAlunos; i++){
        fread(alunos[i], sizeof(Aluno), 1, arq);
    }
    fclose(arq);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos){
    char pc = '%';
    for(int i=0; i<numeroAlunos; i++){
        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->data);
        printf("Curso: %s\n", alunos[i]->curso);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodo);
        printf("%c Conclusao do Curso: %d\n", pc, alunos[i]->conclusao);
        printf("CRA: %.2f\n", alunos[i]->cr);
    }
}