#include "utils.h"
#include <stdio.h>

void LeNumeros(int *array, int tamanho){
    int i;
    for(i=0; i<tamanho; i++){
        scanf("%d", &array[i]);
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media){
    int i, ma = array[0], me;
    float soma=0;
    me = ma;
    for(i=0; i<tamanho; i++){
        soma += array[i];
        if(array[i]>ma){
            ma = array[i];
        }
        if(array[i]<me){
            me = array[i];
        }
    }
    *media = soma/tamanho;
    *maior = ma;
    *menor = me;
}