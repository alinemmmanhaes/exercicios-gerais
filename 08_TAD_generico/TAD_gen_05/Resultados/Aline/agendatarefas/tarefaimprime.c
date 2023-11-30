#include "agendatarefas.h"
#include "tarefaimprime.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct impr{
    char* frase;
};

tImpr* CriaTarefaImprimir(char *msg){
    int tam = strlen(msg);
    tam++;
    tImpr* imp = malloc(sizeof(tImpr));
    imp->frase = malloc(tam*sizeof(char));
    strcpy(imp->frase, msg);
    return imp;
}

void ExecutaTarefaImprimir(void *imp){
    tImpr* i = (tImpr*) imp;
    printf("\n%s", i->frase);
}

void DestroiTarefaImprimir(void *imp){
    tImpr* i = (tImpr*) imp;
    free(i->frase);
    free(i);
}