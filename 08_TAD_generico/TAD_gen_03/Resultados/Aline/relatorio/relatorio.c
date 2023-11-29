#include "relatorio.h"
#include "aluno.h"

void ImprimeRelatorio(Vector *alunos){
    int total = VectorSize(alunos);
    char pc = '%';

    float media = 0, nota = 20;
    int aprovados = 0;
    for(int i=0; i<total; i++){
        tAluno* aluno = (tAluno*)VectorGet(alunos, i);
        nota = GetNotaAluno(aluno);
        media += nota;
        if(nota >= 6){
            aprovados++;
        }
    }
    media = media/total;
    printf("Media das notas: %.2f\n", media);
    printf("Porcentagem de alunos aprovados: %.2f%c\n", 100*((float)aprovados/total), pc);

    printf("Porcentagem de cada genero:\n");
    float masc = 0, fem = 0, outros = 0;
    char sex;
    for(int i=0; i<total; i++){
        tAluno* aluno = (tAluno*)VectorGet(alunos, i);
        sex = GetGeneroAluno(aluno);
        if(sex == 'F'){
            fem++;
        }
        if(sex == 'M'){
            masc++;
        }
        if(sex == 'O'){
            outros++;
        }
    }
    printf("Masculino: %.2f%c\n", 100*(masc/total), pc);
    printf("Feminino: %.2f%c\n", 100*(fem/total), pc);
    printf("Outro: %.2f%c\n", 100*(outros/total), pc);
}