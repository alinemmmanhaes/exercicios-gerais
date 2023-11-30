#include "agendatarefas.h"
#include <stdio.h>
#include <stdlib.h>

typedef void (*executar)(void*);
typedef void (*destruir)(void*);

struct agendatarefas
{
    int total;
    int alocadas;
    void** tarefas;
    int* prioridade;
    int* indoriginal;
    executar* exec;
    destruir* dest;
};

tAgendaTarefas* CriaAgendaDeTarefas(int numElem){
    tAgendaTarefas* agenda = malloc(sizeof(tAgendaTarefas));
    agenda->total = numElem;
    agenda->alocadas = 0;
    agenda->tarefas = malloc(numElem*sizeof(void*));
    agenda->prioridade = malloc(numElem*sizeof(int));
    agenda->indoriginal = malloc(numElem*sizeof(int));
    agenda->exec = malloc(numElem*sizeof(executar));
    agenda->dest = malloc(numElem*sizeof(destruir));
    return agenda;
}

void DestroiAgendaDeTarefas(tAgendaTarefas* tar){
    free(tar->prioridade);
    free(tar->indoriginal);
    free(tar->tarefas);
    free(tar->exec);
    free(tar->dest);
    free(tar);
}

void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void *tarefa, void (*executa)(void*), void (*destroi)(void*) ){
    (tar->alocadas)++;
    int i = tar->alocadas;

    tar->tarefas[i-1] = tarefa;
    tar->prioridade[i-1] = prioridade;
    tar->indoriginal[i-1] = i-1;
    tar->exec[i-1] = executa;
    tar->dest[i-1] = destroi;
}

void ExecutarTarefasDaAgenda(tAgendaTarefas* tar){
    for(int i=0; i<tar->total; i++){
        int prioridade = tar->prioridade[i], indice = i, ioriginal = tar->indoriginal[i];
        executar ex = tar->exec[i];
        destruir des = tar->dest[i];
        void* tarefa = tar->tarefas[i];

        for(int j=i+1; j<tar->total; j++){
            if(tar->prioridade[j] > prioridade){
                indice = j;
                tarefa = tar->tarefas[j];
                ex = tar->exec[j];
                des = tar->dest[j];
                prioridade = tar->prioridade[j];
                ioriginal = tar->indoriginal[j];
            }
            else if(tar->prioridade[j] == prioridade){
                if(tar->indoriginal[j] < ioriginal){
                    indice = j;
                    tarefa = tar->tarefas[j];
                    ex = tar->exec[j];
                    des = tar->dest[j];
                    prioridade = tar->prioridade[j];
                    ioriginal = tar->indoriginal[j];
                }
            }
        }
        tar->tarefas[indice] = tar->tarefas[i];
        tar->prioridade[indice] = tar->prioridade[i];
        tar->exec[indice] = tar->exec[i];
        tar->dest[indice] = tar->dest[i];
        tar->indoriginal[indice] = tar->indoriginal[i];
        tar->tarefas[i] = tarefa;
        tar->prioridade[i] = prioridade;
        tar->exec[i] = ex;
        tar->dest[i] = des;
        tar->indoriginal[i] = ioriginal;       
    }

    for(int i=0; i<tar->total; i++){
        //printf(" i%d ind%d ", i, tar->indoriginal[i]);
        tar->exec[i](tar->tarefas[i]);
        tar->dest[i](tar->tarefas[i]);
    }
}