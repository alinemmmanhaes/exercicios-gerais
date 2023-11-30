#include "conta.h"
#include <stdio.h>
#include <stdlib.h>

struct Conta
{
    int num;
    char* cliente;
    float saldo;
};

tConta *CriaConta(){
    tConta* conta = malloc(sizeof(tConta));
    if(conta == NULL){
        exit(1);
    }
    conta->cliente = NULL;
    return conta;
}

void DestroiConta(DataType conta){
    tConta* c = (tConta*) conta;
    free(c->cliente);
    free(c);
}

void LeConta(tConta *conta){
    scanf("%d;", &conta->num);
    int i=0;
    char c = 'a';
    while(1){
        scanf("%c", &c);
        if(c != ';'){
            i++;
            conta->cliente = realloc(conta->cliente, i*sizeof(char));
            conta->cliente[i-1] = c;
        }
        else{
            break;
        }
    }
    scanf("%f%*c", &conta->saldo);
}

float GetSaldoConta(tConta *conta){
    return conta->saldo;
}