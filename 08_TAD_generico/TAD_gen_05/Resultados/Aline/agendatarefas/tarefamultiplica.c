#include "agendatarefas.h"
#include "tarefamultiplica.h"
#include <stdio.h>
#include <stdlib.h>

struct mult
{
    float n1;
    float n2;
};

tMult* CriaTarefaMultiplicar(float n1, float n2){
    tMult* mult = malloc(sizeof(tMult));
    mult->n1 = n1;
    mult->n2 = n2;
    return mult;
}

void ExecutaTarefaMultiplicar(void *mult){
    tMult* multi = (tMult*)mult;
    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f", multi->n1, multi->n2, multi->n1*multi->n2);
}

void DestroiTarefaMultiplicar(void *mult){
    tMult* m = (tMult*) mult;
    free(m);
}