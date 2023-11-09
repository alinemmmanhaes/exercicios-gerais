#include "aluno.h"

int main(){
    int n, i, j, indice;
	scanf("%d", &n);
	tAluno *aluno[n], *aux;
	
	for(i=0; i<n; i++){
		aluno[i] = CriaAluno();
	}

    for(i=0; i<n; i++){
		LeAluno(aluno[i]);
	}
	
	for(i=0; i<n; i++){
		aux = aluno[i];
        indice = i;
		for(j=i+1; j<n; j++){
			if(ComparaMatricula(aux, aluno[j]) == 1){
				aux = aluno[j];
                indice = j;
			}
		}
		aluno[indice] = aluno[i];
        aluno[i] = aux;
	}
	
	for(i=0; i<n; i++){
        //ImprimeAluno(aluno[i]);
		if(VerificaAprovacao(aluno[i])){
			ImprimeAluno(aluno[i]);
		}
        ApagaAluno(aluno[i]);
	}

	return 0;
}