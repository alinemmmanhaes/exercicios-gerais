#include "pessoa.h"
#include <stdio.h>

int main(){
    int total, i;
    
    scanf("%d\n", &total);
    tPessoa pessoas[total];
    
    for(i=0; i<total; i++){
        pessoas[i] = CriaPessoa();
    }
    
    for(i=0; i<total; i++){
        LePessoa(&pessoas[i]);
        //printf("C\n");
    }
    //printf("A\n");
    AssociaFamiliasGruposPessoas(pessoas, total);
    //printf("L\n");
    
    for(i=0; i<total; i++){
        ImprimePessoa(&pessoas[i]);
    }
    
    return 0;
}