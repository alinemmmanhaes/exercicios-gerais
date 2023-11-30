#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefamultiplica.h"
#include "tarefasoma.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int total = 0;
    printf("Digite o numero de tarefas: ");
    scanf("%d%*c", &total);
    tAgendaTarefas* agenda = CriaAgendaDeTarefas(total);

    char c;
    int prioridade = 0;
    for(int i=0; i<total; i++){
        scanf("%d %c ", &prioridade, &c);
        if(c == 'S'){
            float n1, n2;
            scanf("%f %f", &n1, &n2);
            tSoma* soma = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, soma, ExecutaTarefaSoma, DestroiTarefaSoma);
        }
        else if(c == 'M'){
            float n1, n2;
            scanf("%f %f", &n1, &n2);
            tMult* mult = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, mult, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
        }
        else if(c == 'I'){
            char frase[100];
            scanf("%[^\n]%*c", frase);
            tImpr* imp = CriaTarefaImprimir(frase);
            CadastraTarefaNaAgenda(agenda, prioridade, imp, ExecutaTarefaImprimir, DestroiTarefaImprimir);
        }
        else{
            printf("\nDigite um tipo de tarefa suportado (I/S/M))");
            char frase[100];
            scanf("%[^\n]%*c", frase);
        }
    }
    ExecutarTarefasDaAgenda(agenda);
    DestroiAgendaDeTarefas(agenda);
    return 0;
}