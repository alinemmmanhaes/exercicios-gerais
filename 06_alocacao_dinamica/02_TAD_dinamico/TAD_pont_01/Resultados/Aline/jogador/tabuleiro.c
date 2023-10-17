#include "tabuleiro.h"
#include <stdio.h>
#include <stdlib.h>

tTabuleiro* CriaTabuleiro(){
    int i, j;
    tTabuleiro* tabuleiro = (tTabuleiro*) malloc(sizeof(tTabuleiro));
    tabuleiro->posicoes = malloc(TAM_TABULEIRO*sizeof(char*));
    for(i=0; i<TAM_TABULEIRO; i++){
        tabuleiro->posicoes[i] = malloc(TAM_TABULEIRO*sizeof(char));
    }
    if(tabuleiro == NULL){
        exit(1);
    }
    for(i=0; i<TAM_TABULEIRO; i++){
        for(j=0; j<TAM_TABULEIRO; j++){
            tabuleiro->posicoes[i][j] = '-';
        }
    }
    return tabuleiro;
}

void DestroiTabuleiro(tTabuleiro* tabuleiro){
    free(tabuleiro->posicoes);
    free(tabuleiro);
}

void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y){
    if(peca == PECA_1){
        tabuleiro->posicoes[y][x] = 'X';
    }
    else if(peca == PECA_2){
        tabuleiro->posicoes[y][x] = '0';
    }
}

int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro){
    int i, j;
    for(i=0; i<TAM_TABULEIRO; i++){
        for(j=0; j<TAM_TABULEIRO; j++){
            if(tabuleiro->posicoes[i][j] == '-'){
                return 1;
            }
        }
    }
    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca){
    if(peca == PECA_1){
        if(tabuleiro->posicoes[y][x] == 'X'){
            return 1;
        }
    }
    else if(peca == PECA_2){
        if(tabuleiro->posicoes[y][x] == '0'){
            return 1;
        }
    }
    return 0;
}

int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y){
    if(tabuleiro->posicoes[y][x] == '-'){
        return 1;
    }
    return 0;
}

int EhPosicaoValidaTabuleiro(int x, int y){
    if(x<TAM_TABULEIRO && x>=0){
        if(y<TAM_TABULEIRO && y>=0){
            return 1;
        }
    }
    return 0;
}

void ImprimeTabuleiro(tTabuleiro* tabuleiro){
    int i, j;
    for(i=0; i<TAM_TABULEIRO; i++){
        printf("\t");
        for(j=0; j<TAM_TABULEIRO; j++){
            printf("%c", tabuleiro->posicoes[i][j]);
        }
        printf("\n");
    }
}