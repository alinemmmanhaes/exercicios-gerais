#include "jogada.h"
#include <stdio.h>
#include <stdlib.h>

tJogada* CriaJogada(){
    tJogada* jogada = (tJogada*) malloc(sizeof(tJogada));
    if(jogada == NULL){
        exit(1);
    }
    jogada->sucesso = 0;
    return jogada;
}

void DestroiJogada(tJogada* jogada){
    free(jogada);
}

void LeJogada(tJogada* jogada){
    printf("Digite uma posicao (x e y):\n");
    scanf("%d %d", &jogada->x, &jogada->y);
}

int ObtemJogadaX(tJogada* jogada){
    return jogada->x;
}

int ObtemJogadaY(tJogada* jogada){
    return jogada->y;
}

int FoiJogadaBemSucedida(tJogada* jogada){
    if(jogada->sucesso){
        return 1;
    }
    return 0;
}
