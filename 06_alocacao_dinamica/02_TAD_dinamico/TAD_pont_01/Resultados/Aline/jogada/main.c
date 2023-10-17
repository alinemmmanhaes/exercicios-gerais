#include "tabuleiro.h"
#include "jogada.h"
#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main(){
    tJogo* jogo;
    int jog = 1, gameover = 0;
    jogo = CriaJogo();
    ComecaJogo(jogo);
    while(1){
        if(AcabouJogo(jogo) || gameover){
            if(gameover == 0){
                printf("Sem vencedor!\n");
            }
            if(ContinuaJogo() == 0){
                DestroiJogo(jogo);
                break;
            }
            jogo = CriaJogo();
            ComecaJogo(jogo);
            jog = 1;
            gameover = 0;
        }
        if(jog == 1){
            JogaJogador(jogo->jogador1, jogo->tabuleiro);
            jog = 2;
        }
        else if(jog == 2){
            JogaJogador(jogo->jogador2, jogo->tabuleiro);
            jog = 1;
        }
        if(VenceuJogador(jogo->jogador1, jogo->tabuleiro)){
            printf("JOGADOR 1 Venceu!\n");
            gameover = 1;
        }
        else if(VenceuJogador(jogo->jogador2, jogo->tabuleiro)){
            printf("JOGADOR 2 Venceu!\n");
            gameover = 1;
        }
    }
    return 0;
}