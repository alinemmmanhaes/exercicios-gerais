#include "aluno.h"
#include <stdio.h>

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3){
	tAluno aluno;
	int i;
	for(i=0; i<50; i++){
		aluno.nome[i] = nome[i];
		if(nome[i] == '\0'){
			break;
		}
	}
	aluno.matricula = matricula;
	aluno.n1 = n1;
	aluno.n2 = n2;
	aluno.n3 = n3;
	return aluno;
}

tAluno LeAluno(){
	tAluno aluno;
	char nome[50];
	int matricula, n1, n2, n3;
	scanf("%s", nome);
	scanf("%d", &matricula);
	scanf("%d %d %d", &n1, &n2, &n3);
	aluno = CriaAluno(nome, matricula, n1, n2, n3);
	return aluno;
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2){
	if(aluno1.matricula == aluno2.matricula){
		return 0;
	}
	else if(aluno1.matricula > aluno2.matricula){
		return 1;
	}
	else if(aluno1.matricula < aluno2.matricula){
		return -1;
	}
}

int CalculaMediaAluno(tAluno aluno){
	int media;
	media = aluno.n1 + aluno.n2 + aluno.n3;
	media =  media/3;
	return media;
}

int VerificaAprovacao(tAluno aluno){
	int media;
	media = CalculaMediaAluno(aluno);
	
	if(media>=7){
		return 1;
	}
	else{
		return 0;
	}
}

void ImprimeAluno(tAluno aluno){
	printf("%s\n", aluno.nome);
}
