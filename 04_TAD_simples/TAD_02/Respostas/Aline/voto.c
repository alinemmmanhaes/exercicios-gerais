#include "voto.h"
#include <stdio.h>

tVoto inicializaVotos(){
    tVoto voto;
    voto.brancosP = 0;
    voto.brancosM = 0;
    voto.nulosM = 0;
    voto.nulosP = 0;
    voto.dij = 0;
    voto.tur = 0;
    voto.sha = 0;
    voto.ber = 0;
    voto.lin = 0;
    voto.lov = 0;
    return voto;
}

float porcentagem(int valor, int total){
    return (valor/total);
}

tVoto contabilizaVotoPrisidente(tVoto votos, int votoP){
    if(votoP == DIJKSTRA){
        votos.dij++;
    }
    else if(votoP == TURING){
        votos.tur++;
    }
    else if(votoP == SHAW){
        votos.sha++;
    }
    else if(votoP == BRANCO){
        votos.brancosP++;
    }
    else{
        votos.nulosP++;
    }
    return votos;
}

tVoto contabilizaVotoPMinistro(tVoto votos, int votoM){
    if(votoM == BERNERS){
        votos.ber++;
    }
    else if(votoM == LINUS){
        votos.lin++;
    }
    else if(votoM == LOVELACE){
        votos.lov++;
    }
    else if(votoM == BRANCO){
        votos.brancosM++;
    }
    else{
        votos.nulosM++;
    }
    return votos;
}

int vencedorPresidente(tVoto votos){
    int maior = 0, empate = 0, idm = 0, invalidos, validos;
    
    invalidos = votos.nulosP + votos.brancosP;
    validos = votos.dij + votos.tur + votos.sha;
    if(validos<invalidos){
        return SEM_DECISAO;
    }
    
    if(votos.dij > maior){
        maior =  votos.dij;
        idm = DIJKSTRA;
    }
    if(votos.tur > maior){
        maior =  votos.tur;
        idm = TURING;
    }
    else if(votos.tur == maior){
        empate++;
    }
    if(votos.sha > maior){
        maior =  votos.sha;
        idm = SHAW;
    }
    else if(votos.sha == maior){
        empate++;
    }
    if(empate!=0){
        return EMPATE;
    }
    return idm;
}

int vencedorPMinistro(tVoto votos){
    int maior = 0, empate = 0, idm = 0, invalidos, validos;
    
    invalidos = votos.nulosM + votos.brancosM;
    validos = votos.lin + votos.lov + votos.ber;
    if(validos<invalidos){
        return SEM_DECISAO;
    }
    
    if(votos.lin > maior){
        maior =  votos.lin;
        idm = LINUS;
    }
    if(votos.lov > maior){
        maior =  votos.lov;
        idm = LOVELACE;
    }
    else if(votos.lov == maior){
        empate++;
    }
    if(votos.ber > maior){
        maior =  votos.ber;
        idm = BERNERS;
    }
    else if(votos.ber == maior){
        empate++;
    }
    if(empate!=0){
        return EMPATE;
    }
    return idm;
}

int obtemTotalVotosPresidente(tVoto votos){
    int validos, invalidos, total;
    
    invalidos = votos.nulosP + votos.brancosP;
    validos = votos.dij + votos.tur + votos.sha;
    total = invalidos + validos;
    
    return total;
}

int obtemTotalVotosPMinistro(tVoto votos){
    int invalidos, validos, total;
    
    invalidos = votos.nulosM + votos.brancosM;
    validos = votos.lin + votos.lov + votos.ber;
    total = invalidos + validos;
    
    return total;
}

void printaResultado(tVoto votos, int totalP, int totalM, int vencedorP, int vencedorM, int counterQtd, int qtd){
    int invalidosP, invalidosM;
    invalidosP = votos.nulosP + votos.brancosP;
    invalidosM = votos.nulosM + votos.brancosM;
    if(totalP>qtd || totalM>qtd){
        printf("ELEICAO ANULADA");
    }
    else{
        printf("FIM DA ELEICAO\n");
        printf("- PRESIDENTE ELEITO: ");
        if(vencedorP == EMPATE){
            printf("EMPATE\n");
        }
        else if(vencedorP == SEM_DECISAO){
            printf("SEM DECISAO\n");
        }
        else if(vencedorP == DIJKSTRA){
            printf("Edsger Dijkstra (Partido do Melhor Caminho (PMC)), %d, %.2f%\n", votos.dij, porcentagem(votos.dij, totalP));
        }
        else if(vencedorP == TURING){
            printf("Alan Turing (Partido do Avanço Intelectual (PAI)), %d, %.2f%\n", votos.tur, porcentagem(votos.tur, totalP));
        }
        else if(vencedorP == SHAW){
            printf("Carol Shaw (Mulheres Programadoras Unidas (MPU)), %d, %.2f%\n", votos.sha, porcentagem(votos.sha, totalP));
        }
        printf("- PRIMEIRO MINISTRO ELEITO: ");
        if(vencedorM == EMPATE){
            printf("EMPATE\n");
        }
        else if(vencedorM == SEM_DECISAO){
            printf("SEM DECISAO\n");
        }
        else if(vencedorM == LINUS){
            printf("Linus Torvalds (Linux (Linux)), %d, %.2f%\n", votos.lin, porcentagem(votos.lin, totalM));
        }
        else if(vencedorP == LOVELACE){
            printf("Ada Lovelace (Gamers Unidos (GU)), %d, %.2f%\n", votos.lov, porcentagem(votos.lov, totalP));
        }
        else if(vencedorP == BERNERS){
            printf("Tim Berners-Lee (World Wide Web (WWW)), %d, %.2f%\n", votos.ber, porcentagem(votos.ber, totalP));
        }
        printf("- COMPARECIMENTO: %.2f%\n", porcentagem(counterQtd, qtd));
        printf("- NULOS E BRANCOS: %d, %d", invalidosP, invalidosM);
    }
}