#include "tabuleiro.h"
#include "jogada.h"
#include "jogador.h"
#include <stdio.h>
#include <stdlib.h>

tJogador* CriaJogador(int idJogador){
    tJogador* jogador = (tJogador*) malloc(sizeof(tJogador));
    if(jogador == NULL){
        exit(1);
    }
    jogador->id = idJogador;
    return jogador;
}

void DestroiJogador(tJogador* jogador){
    free(jogador);
}

void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    tJogada* jogada;
    int x, y;
    jogada = CriaJogada();
    while(1){
        printf("Jogador %d\n", jogador->id);
        LeJogada(jogada);
        x = ObtemJogadaX(jogada);
        y = ObtemJogadaY(jogada);
        if(EhPosicaoValidaTabuleiro(x, y)){
            if(EstaLivrePosicaoTabuleiro(tabuleiro, x, y)){
                MarcaPosicaoTabuleiro(tabuleiro, jogador->id, x, y);
                printf("Jogada [%d,%d]!\n", x, y);
                jogada->sucesso = 1;
            }
            else{
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", x, y);
            }
        }
        else{
            printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", x, y);
        }
        if(FoiJogadaBemSucedida(jogada)){
            DestroiJogada(jogada);
            break;
        }
    }
}

int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro){
    if(jogador->id == 1){
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, 1)){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, 1)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, 1)){
                    return 1;
                }
            }
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, 1)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, 1)){
                    return 1;
                }
            }
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, 1)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, 1)){
                    return 1;
                }
            }
        }
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, 1)){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, 1)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, 1)){
                    return 1;
                }
            }
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, 1)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, 1)){
                    return 1;
                }
            }
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, 1)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, 1)){
                    return 1;
                }
            }
        }
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, 1)){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, 1)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, 1)){
                    return 1;
                }
            }
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, 1)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, 1)){
                    return 1;
                }
            }
        }
    }
    else if(jogador->id == 2){
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, 2)){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, 2)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, 2)){
                    return 1;
                }
            }
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, 2)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, 2)){
                    return 1;
                }
            }
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, 2)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, 2)){
                    return 1;
                }
            }
        }
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, 2)){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, 2)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, 2)){
                    return 1;
                }
            }
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, 2)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, 2)){
                    return 1;
                }
            }
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, 2)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, 2)){
                    return 1;
                }
            }
        }
        if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, 2)){
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, 2)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, 2)){
                    return 1;
                }
            }
            if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, 2)){
                if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, 2)){
                    return 1;
                }
            }
        }
    }
    return 0;
}
