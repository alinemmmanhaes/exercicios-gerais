#include <stdio.h>
#include "evento.h"

void cadastrarEvento(Evento* eventos, int* numEventos){
    Evento ev;
    int total;
    total = *numEventos;
    if(*numEventos < MAX_EVENTOS){
        scanf("%s", ev.nome);
        scanf("%d %d %d", &ev.dia, &ev.mes, &ev.ano);
        eventos[*numEventos] = ev;
        total++;
        *numEventos = total;
        printf("Evento cadastrado com sucesso!\n");
    }
    else{
        printf("Limite de eventos atingido!\n");
    }
}

void exibirEventos(Evento* eventos, int* numEventos){
    int i;
    printf("Eventos cadastrados:\n");
    for(i=0; i<*numEventos; i++){
        printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos){
    int indice, dia, mes, ano;
    scanf("%d", &indice);
    if(indice<*numEventos){
        scanf("%d %d %d", &dia, &mes, &ano);
        eventos[indice].dia = dia;
        eventos[indice].mes = mes;
        eventos[indice].ano = ano;
        printf("Data modificada com sucesso!\n");
    }else{
        printf("Indice invalido!\n");
    }
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    if(*indiceA < *numEventos && *indiceB < *numEventos){
        Evento aux;
        aux = eventos[*indiceA];
        eventos[*indiceA] = eventos[*indiceB];
        eventos[*indiceB] = aux;
        printf("Eventos trocados com sucesso!\n");
    }
    else{
        printf("Indices invalidos!\n");
    }
}