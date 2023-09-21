#include <stdio.h>
#include "eleitor.h"
#include "voto.h"

int main(){
    int id, vp, vm, eleitores, javotou[1000], i, pres, pmin, totalP, totalM;
    tVoto votos;
    
    scanf("%d", &eleitores);
    votos = inicializaVotos();

    for(i=0; i<1000; i++){
        javotou[i] = -1;
    }
    
    while(scanf("%d %d %d", &id, &vp, &vm)==3){
        tEleitor eleitor;
        eleitor = criaEleitor(id, vp, vm);
        
        for(i=0; i<1000; i++){
            if(javotou[i] == -1){
                break;
            }
            if(jaVotou(eleitor, javotou[i])){
                printf("ELEICAO ANULADA");
                return 1;
            }
        }
        
        votos = contabilizaVotoPrisidente(votos, obtemVotoPresidente(eleitor));
        votos = contabilizaVotoPMinistro(votos, obtemVotoPMinistro(eleitor));
        
        for(i=0; i<1000; i++){
            if(javotou[i] == -1){
                javotou[i] = id;
                break;
            }
        }
    }
    scanf("%*c");

    pres = vencedorPresidente(votos);
    pmin = vencedorPMinistro(votos);
    totalP = obtemTotalVotosPresidente(votos);
    totalM = obtemTotalVotosPMinistro(votos);

    printaResultado(votos, totalP, totalM, pres, pmin, i+1, eleitores);
    
    return 0;
}