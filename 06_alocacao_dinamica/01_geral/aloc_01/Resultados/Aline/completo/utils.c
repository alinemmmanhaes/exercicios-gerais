#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int *CriaVetor(int tamanho){
    int* vet = (int*) malloc(tamanho * sizeof(int));
    if(vet == NULL){
        printf("ERRO\n");
        exit(1);
    }
    return vet;
}

void LeVetor(int *vetor, int tamanho){
    int i;
    for(i=0; i<tamanho; i++){
        scanf("%d", &vetor[i]);
    }
}

float CalculaMedia(int *vetor, int tamanho){
    float soma = 0;
    int i;
    for(i=0; i<tamanho; i++){
        soma += vetor[i];
    }
    soma = soma/tamanho;
    return soma;
}

void LiberaVetor(int *vetor){
    free(vetor);
}