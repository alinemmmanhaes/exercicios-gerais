#include "agencia.h"
#include <stdio.h>
#include <stdlib.h>

struct Agencia
{
    char* nome;
    int numero;
    Vector* contas;
};

tAgencia *CriaAgencia(){
    tAgencia* agencia = malloc(sizeof(tAgencia));
    if(agencia == NULL){
        exit(1);
    }
    agencia->nome = NULL;
    agencia->contas = VectorConstruct();
    return agencia;
}

void DestroiAgencia(DataType agencia){
    tAgencia* ag = (tAgencia*)agencia;
    free(ag->nome);
    VectorDestroy(ag->contas, DestroiConta);
    free(ag);
}

void LeAgencia(tAgencia *agencia){
    scanf("%d;", &agencia->numero);
    int i=0;
    char c = 'a';
    while(1){
        scanf("%c", &c);
        if(c != '\n'){
            i++;
            agencia->nome = realloc(agencia->nome, i*sizeof(char));
            agencia->nome[i-1] = c;
        }
        else{
            i++;
            agencia->nome = realloc(agencia->nome, i*sizeof(char));
            agencia->nome[i-1] = '\0';
            break;
        }
    }
}

void AdicionaConta(tAgencia *agencia, tConta *conta){
    VectorPushBack(agencia->contas, conta);
}

int ComparaAgencia(int numAgencia, tAgencia *agencia2){
    if(numAgencia == agencia2->numero){
        return 1;
    }
    return 0;
}

float GetSaldoMedioAgencia (tAgencia *agencia){
    int total = VectorSize(agencia->contas);
    float media = 0;
    for(int i=0; i<total; i++){
        tConta* conta = VectorGet(agencia->contas, i);
        media += GetSaldoConta(conta);
    }
    media = media/total;
    return media;
}

void ImprimeDadosAgencia(tAgencia *agencia){
    printf("\tNome: %s\n", agencia->nome);
    
    printf("\tNumero: %d\n", agencia->numero);

    int total = VectorSize(agencia->contas);
    printf("\tNumero de contas cadastradas: %d\n", total);

    float media = GetSaldoMedioAgencia(agencia);
    printf("\tSaldo médio: R$%.2f\n\n", media);
}