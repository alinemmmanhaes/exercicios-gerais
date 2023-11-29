#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

struct Aluno{
    char* nome;
    char sexo;
    float nota;
};

tAluno *CriaAluno(){
    tAluno* aluno = malloc(sizeof(tAluno));
    if(aluno == NULL){
        exit(1);
    }
    aluno->nome = NULL;
    return aluno;
}

void DestroiAluno(data_type aluno){
    tAluno* al = (tAluno*) aluno;
    free(al->nome);
    free(al);
}

void LeAluno(tAluno *aluno){
    int i=0;
    char c = 'a';
    while(1){
        scanf("%c", &c);
        if(c != ';'){
            i++;
            aluno->nome = realloc(aluno->nome, i*sizeof(char));
            aluno->nome[i-1] = c;
        }
        else{
            break;
        }
    }
    scanf("%c;%f%*c", &aluno->sexo, &aluno->nota);
}

char GetGeneroAluno(tAluno *aluno){
    return aluno->sexo;
}

float GetNotaAluno(tAluno *aluno){
    return aluno->nota;
}