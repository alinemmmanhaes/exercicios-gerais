#include "pessoa.h"
#include <stdio.h>

tPessoa CriaPessoa(){
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    pessoa.irmao = NULL;
    return pessoa;
}

void LePessoa(tPessoa *pessoa){
    scanf("\n%[^\n]", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    if(pessoa->mae!=NULL || pessoa->pai!=NULL){
        return 1;
    }
    return 0;
}

void ImprimePessoa(tPessoa *pessoa){
    if(VerificaSeTemPaisPessoa(pessoa)){
        printf("NOME COMPLETO: %s\n", pessoa->nome);
        if(pessoa->pai!=NULL){
            printf("PAI: %s\n", pessoa->pai->nome);
        }else{
            printf("PAI: NAO INFORMADO\n");
        }
        if(pessoa->mae!=NULL){
            printf("MAE: %s\n", pessoa->mae->nome);
        }else{
            printf("MAE: NAO INFORMADO\n");
        }
        if(pessoa->irmao!=NULL){
            printf("IRMAO: %s\n\n", pessoa->irmao->nome);
        }else{
            printf("IRMAO: NAO INFORMADO\n\n");
        }
    }
}

int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2){
    if(pessoa1->mae == pessoa2->mae && pessoa1->pai == pessoa2->pai){
        return 1;
    }
    return 0;
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas){
    int total, i, j, ma, pa, filho;
    //printf("AT\n");
    scanf("%d\n", &total);
    //printf("DT\n");
    for(i=0; i<total; i++){
        scanf("mae: %d, pai: %d, filho: %d%*c", &ma, &pa, &filho);
        if(ma!=-1){
            pessoas[filho].mae = &pessoas[ma];
        }
        if(pa!=-1){
            pessoas[filho].pai = &pessoas[pa];
        }
    }
    for(i=0; i<numPessoas; i++){
        for(j=0; j<numPessoas; j++){
            if(VerificaIrmaoPessoa(&pessoas[i], &pessoas[j]) && i!=j){
                pessoas[i].irmao = &pessoas[j];
            }
        }
    }
}
