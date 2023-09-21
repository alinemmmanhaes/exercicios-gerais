#include "candidato.h"
#include "eleitor.h"
#include <stdio.h>

tEleicao InicializaEleicao(){
	tEleicao eleicao;
	tCandidato cand;
	int totalc, i, p=0, g=0;
	eleicao.totalPresidentes = 0;
	eleicao.totalGovernadores = 0;
	eleicao.votosBrancosPresidente = 0;
	eleicao.votosNulosPresidente = 0;
	eleicao.votosBrancosGovernador = 0;
	eleicao.votosNulosGovernador = 0;
	scanf("%d", &totalc);
	for(i=0; i<totalc; i++){
		cand = LeCandidato();
		if(ObtemCargo(cand) == 'P'){
			eleicao.totalPresidentes++;
			presidentes[p] = cand;
			p++;
		}
		else if(ObtemCargo(cand) == 'G'){
			eleicao.totalGovernadores++;
			governadores[g] = cand;
			g++;
		}
	}
	return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao){
	int i, p, g, j;
	tEleitor eleitor;
	scanf("%d", &eleicao.totalEleitores);
	for(i=0; i<eleicao.totalEleitores; i++){
		eleitor[i] = LeCandidato();
		p = ObtemVotoPresidente(eleitor[i]);
		g = ObtemVotoGovernador(eleitor[i]);
		for(j=0; j<eleicao.totalPresidentes; j++){
			if(VerificaIdCandidato(presidentes[j], p){
				IncrementaVotoCandidato(presidentes[j]);
				break;
			}
			if(j == eleicao.totalPresidentes-1){
				if(p == 0){
					eleicao.votosBrancosPresidente++;
				}else{
					eleicao.votosNulosPresidente++;
				}
			}
		}
		for(j=0; j<eleicao.totalGovernadores; j++){
			if(VerificaIdCandidato(governadores[j], g){
				IncrementaVotoCandidato(governadores[j]);
				break;
			}
			if(j == eleicao.totalGovernadores-1){
				if(g == 0){
					eleicao.votosBrancosGovernador++;
				}else{
					eleicao.votosNulosGovernador++;
				}
			}
		}
	}
}
