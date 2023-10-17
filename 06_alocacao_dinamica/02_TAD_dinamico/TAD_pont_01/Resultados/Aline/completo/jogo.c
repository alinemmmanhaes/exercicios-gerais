#include "tabuleiro.h"
#include "jogada.h"
#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

tJogo* CriaJogo(){
    tJogo* jogo = (tJogo*)malloc(sizeof(tJogo));
    if(jogo == NULL){
        exit(1);
    }
    return jogo;
}

void ComecaJogo(tJogo* jogo){
    jogo->tabuleiro = CriaTabuleiro();
    jogo->jogador1 = CriaJogador(1);
    jogo->jogador2 = CriaJogador(2);
}

int AcabouJogo(tJogo* jogo){
    if(TemPosicaoLivreTabuleiro(jogo->tabuleiro)){
        return 0;
    }
    return 1;
}

int ContinuaJogo(){
    char resp;
    printf("Jogar novamente? (s,n)\n");
    scanf("%*c%c" , &resp);
    if(resp == 's'){
        return 1;
    }
    return 0;
}

void DestroiJogo(tJogo* jogo){
    DestroiJogador(jogo->jogador1);
    DestroiJogador(jogo->jogador2);
    DestroiTabuleiro(jogo->tabuleiro);
    free(jogo);
}