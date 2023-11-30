#include "agendatarefas.h"
#include "tarefasoma.h"
#include <stdio.h>
#include <stdlib.h>

struct soma
{
    float n1;
    float n2;
};

tSoma* CriaTarefaSoma(float n1, float n2){
    tSoma* soma = malloc(sizeof(tSoma));
    soma->n1 = n1;
    soma->n2 = n2;

    return soma;
}

void ExecutaTarefaSoma(void *sum){
    tSoma* soma = (tSoma*)sum;
    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f", soma->n1, soma->n2, soma->n1+soma->n2);
}

void DestroiTarefaSoma(void *sum){
    tSoma* soma = (tSoma*)sum;
    free(soma);
}