#include "tabuleiro.h"
#include "jogador.h"

tJogador CriaJogador(int idJogador){
	tJogador jog;
	jog.id = idJogador;
	return jog;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro){

}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro){
	if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, jogador.id)){
		if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, jogador.id)){
			if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, jogador.id)){
				return 1;
			}
		}
		else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, jogador.id)){
			if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, jogador.id)){
				return 1;
			}
		}
	}
	else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador.id)){
		if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, jogador.id)){
			if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, jogador.id)){
				return 1;
			}
		}
		else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, jogador.id)){
			if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, jogador.id)){
				return 1;
			}
		}
	}
	else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, jogador.id)){
		if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 1, jogador.id)){
			if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 1, jogador.id)){
				return 1;
			}
		}
		else if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 0, jogador.id)){
			if(EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 2, jogador.id)){
				return 1;
			}
		}
	}
}
