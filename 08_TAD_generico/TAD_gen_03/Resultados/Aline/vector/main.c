#include "relatorio.h"
#include "aluno.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int tam;
    scanf("%d%*c", &tam);
    Vector* vetor = VectorConstruct();

    for(int i=0; i<tam; i++){
        tAluno* aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(vetor, aluno);
    }

    ImprimeRelatorio(vetor);

    VectorDestroy(vetor, DestroiAluno);
    return 0;
}