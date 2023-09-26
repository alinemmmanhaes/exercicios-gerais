#include "eleitor.h"
#include <stdio.h>

tEleitor CriaEleitor(int id, int votoP, int votoG){
    tEleitor eleitor;
    eleitor.id = id;
    eleitor.votoP = votoP;
    eleitor.votoG = votoG;
    return eleitor;
}

tEleitor LeEleitor(){
    int id, p, g;
    tEleitor eleitor;
    scanf("%d %d %d", &id, &p, &g);
    eleitor = CriaEleitor(id, p, g);
    return eleitor;
}

int ObtemVotoPresidente(tEleitor eleitor){
    return eleitor.votoP;
}

int ObtemVotoGovernador(tEleitor eleitor){
    return eleitor.votoG;
}

int EhMesmoEleitor(tEleitor eleitor1, tEleitor eleitor2){
    if(eleitor1.id == eleitor2.id){
        return 1;
    }
    return 0;
}
