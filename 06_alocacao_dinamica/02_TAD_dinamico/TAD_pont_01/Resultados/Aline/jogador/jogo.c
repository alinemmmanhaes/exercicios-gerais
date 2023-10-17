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
    
    int gameover = 0, jog = 1;
    
    while(1){
        if(AcabouJogo(jogo) || gameover){
            if(gameover == 0){
                printf("Sem vencedor!\n");
            }
            break;
        }
        if(jog == 1){
            JogaJogador(jogo->jogador1, jogo->tabuleiro);
            jog = 2;
        }
        else if(jog == 2){
            JogaJogador(jogo->jogador2, jogo->tabuleiro);
            jog = 1;
        }
        ImprimeTabuleiro(jogo->tabuleiro);
        if(VenceuJogador(jogo->jogador1, jogo->tabuleiro)){
            printf("JOGADOR 1 Venceu!\n");
            gameover = 1;
        }
        else if(VenceuJogador(jogo->jogador2, jogo->tabuleiro)){
            printf("JOGADOR 2 Venceu!\n");
            gameover = 1;
        }
    }
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
    scanf("%*[^sn]%c" , &resp);
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
