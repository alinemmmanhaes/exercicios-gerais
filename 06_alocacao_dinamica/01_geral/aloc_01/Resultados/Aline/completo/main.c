#include "utils.h"
#include <stdio.h>

int main(){
    int tamanho, *vetor;
    float media;
    scanf("%d", &tamanho);
    vetor = CriaVetor(tamanho);
    LeVetor(vetor, tamanho);
    media = CalculaMedia(vetor, tamanho);
    printf("%.2f", media);
    LiberaVetor(vetor);
}