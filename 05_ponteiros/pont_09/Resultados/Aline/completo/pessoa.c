#include "pessoa.h"
#include <stdio.h>

tPessoa CriaPessoa(){
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    return pessoa;
}

void LePessoa(tPessoa *pessoa){
    scanf("%[^\n]\n", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    printf("tchau\n");
    if(pessoa->mae!=NULL || pessoa->pai!=NULL){
        printf("entrou\n");
        return 1;
    }
    return 0;
}

void ImprimePessoa(tPessoa *pessoa){
    printf("oi\n");
    if(VerificaSeTemPaisPessoa(pessoa)){
        printf("NOME COMPLETO: %s\n", pessoa->nome);
        if(pessoa->pai!=NULL){
            printf("PAI: %s\n", pessoa->pai->nome);
        }else{
            printf("PAI: NAO INFORMADO\n");
        }
        if(pessoa->mae!=NULL){
            printf("MAE: %s\n\n", pessoa->mae->nome);
        }else{
            printf("MAE: NAO INFORMADO\n\n");
        }
    }
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas){
    int total, i, ma, pa, filho;
    //printf("AT\n");
    scanf("%d\n", &total);
    printf("%d\n", total);
    //printf("DT\n");
    for(i=0; i<total; i++){
        printf("%d\n", i);
        scanf("mae: %d, pai: %d, filho: %d%*c", &ma, &pa, &filho);
        if(ma!=-1){
            pessoas[filho].mae = &pessoas[ma];
        }
        if(pa!=-1){
            pessoas[filho].pai = &pessoas[pa];
        }
    }
}
