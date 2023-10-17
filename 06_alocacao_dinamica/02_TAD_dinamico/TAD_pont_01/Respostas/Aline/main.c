#include "tabuleiro.h"
#include "jogada.h"
#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main(){
    tJogo* jogo;
    while(1){
        jogo = CriaJogo();
        ComecaJogo(jogo);
        DestroiJogo(jogo);
        if(ContinuaJogo() == 0){
            break;
        }
    }
    return 0;
}
