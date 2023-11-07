#include "utils_char.h"
#include <stdio.h>
#include <stdlib.h>

char *CriaVetor(int tamanho){
    char* frase = malloc(tamanho*sizeof(char));
    if(frase == NULL){
        printf("erro de alocacao\n");
        exit(1);
    }
    for(int i=0; i<tamanho; i++){
        frase[i] = '_';
    }
    return frase;
}

void LeVetor(char *vetor, int tamanho){
    char c;
    int i=0;
    while(scanf("%c", &c) == 1){
        if(c == '\n'){
            break;
        }
        vetor[i] = c;
        i++;
        if(i == tamanho){
            break;
        }
    }
}

void ImprimeString(char *vetor, int tamanho){
    for(int i=0; i<tamanho; i++){
        printf("%c", vetor[i]);
    }
    printf("\n");
}

void LiberaVetor(char *vetor){
    free(vetor);
}