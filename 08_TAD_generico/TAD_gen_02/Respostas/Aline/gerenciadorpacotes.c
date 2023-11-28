#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <stdlib.h>

struct gerenciadorpacotes
{
    tPacote** pacotes;
    int numPacotes;
};


tGerenciador* CriaGerenciador(){
    tGerenciador* gerenciador = malloc(sizeof(tGerenciador));
    gerenciador->numPacotes = 0;
    gerenciador->pacotes = NULL;
    return gerenciador;
}

void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac){
    (geren->numPacotes)++;
    int total = geren->numPacotes;
    geren->pacotes = realloc(geren->pacotes, total*sizeof(tPacote*));
    geren->pacotes[total-1] = pac;
}

void DestroiGerenciador(tGerenciador* geren){
    for(int i=0; i<geren->numPacotes; i++){
        DestroiPacote(geren->pacotes[i]);
    }
    free(geren->pacotes);
    free(geren);
}

void ImprimirPacoteNoIndice(tGerenciador* geren, int idx){
    ImprimePacote(geren->pacotes[idx]);
}

void ImprimirTodosPacotes(tGerenciador* geren){
    for(int i=0; i<geren->numPacotes; i++){
        ImprimirPacoteNoIndice(geren, i);
    }
}