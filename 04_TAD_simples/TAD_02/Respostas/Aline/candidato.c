#include "candidato.h"
#include <stdio.h>

tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id){
    tCandidato cand;
    int i;
    for(i=0; i<50; i++){
        cand.nome[i] = nome[i];
        if(nome[i]!='\0'){
            break;
        }
    }
    for(i=0; i<50; i++){
        cand.partido[i] = partido[i];
        if(partido[i]!='\0'){
            break;
        }
    }
    cand.cargo = cargo;
    cand.id = id;
    cand.votos = 0;
    return cand;
}

tCandidato LeCandidato(){
    char nome[50], part[50], cargo;
    int id;
    tCandidato cand;
    scanf("%[^,], %[^,], %c, %d", nome, part, &cargo, &id);
    cand = CriaCandidato(nome, part, cargo, id);
    return cand;
}

int VerificaIdCandidato(tCandidato candidato, int id){
    if(candidato.id == id){
        return 1;
    }
    return 0;
}

int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2){
    if(candidato1.id == candidato2.id){
    	return 1;
    }
    return 0;
}

char ObtemCargo(tCandidato candidato){
    return candidato.cargo;
}

tCandidato IncrementaVotoCandidato(tCandidato candidato){
    candidato.votos++;
    return candidato;
}

int ObtemVotos(tCandidato candidato){
    return candidato.votos;
}

float CalculaPercentualVotos(tCandidato candidato, int totalVotos){
    float percentual;
    percentual = (candidato.votos/totalVotos);
    return percentual;
}

void ImprimeCandidato (tCandidato candidato, float percentualVotos){
    printf("%s (%s), %d voto(s), %.2f%\n", candidato.nome, candidato.partido, candidato.votos, percentualVotos);
}
