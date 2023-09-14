#include "aluno.h"
#include <stdio.h>

int main(){
	int n, i, j, menor=0, jmen;
	scanf("%d", &n);
	tAluno aluno[n], aux;
	
	for(i=0; i<n; i++){
		aluno[i] = LeAluno();
	}
	
	for(i=0; i<n; i++){
		menor = aluno[i].matricula;
		jmen = i;
		for(j=i+1; j<n; j++){
			if(aluno[j].matricula < menor){
				menor = aluno[j].matricula;
				jmen = j;
			}
		}
		aux = aluno[i];
		aluno[i] = aluno[jmen];
		aluno[jmen] = aux;
	}
	
	for(i=0; i<n; i++){
		if(VerificaAprovacao(aluno[i])){
			ImprimeAluno(aluno[i]);
		}
	}
	return 0;
}
