#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int total = 0;
    printf("Digite o numero de alunos: ");
    scanf("%d", &total);
    Aluno** lista = CriaVetorAlunos(total);
    LeAlunos(lista, total);
    
    SalvaAlunosBinario(lista, "alunos.bin", total);
    LiberaAlunos(lista, total);

    lista = CriaVetorAlunos(total);
    CarregaAlunosBinario(lista, "alunos.bin");
    ImprimeAlunos(lista, total);
    LiberaAlunos(lista, total);

    return 0;
}