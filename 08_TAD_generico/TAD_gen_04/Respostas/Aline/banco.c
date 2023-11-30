#include "banco.h"
#include <stdio.h>
#include <stdlib.h>

struct Banco
{
    char* nome;
    Vector* agencias;
};

tBanco *CriaBanco(){
    tBanco* banco = malloc(sizeof(tBanco));
    if(banco == NULL){
        exit(1);
    }
    banco->nome = NULL;
    banco->agencias = VectorConstruct();
    return banco;
}

void DestroiBanco(tBanco *banco){
    free(banco->nome);
    VectorDestroy(banco->agencias, DestroiAgencia);
    free(banco);
}

void LeBanco(tBanco *banco){
    int i=0;
    char c = 'a';
    while(1){
        scanf("%c", &c);
        if(c != '\n'){
            i++;
            banco->nome = realloc(banco->nome, i*sizeof(char));
            banco->nome[i-1] = c;
        }
        else{
            i++;
            banco->nome = realloc(banco->nome, i*sizeof(char));
            banco->nome[i-1] = '\0';
            break;
        }
    }
}

void AdicionaAgencia(tBanco *banco, tAgencia *agencia){
    VectorPushBack(banco->agencias, agencia);
}

void InsereContaBanco(tBanco *banco, int numAgencia, tConta *cliente){
    int total = VectorSize(banco->agencias);
    for(int i=0; i<total; i++){
        tAgencia* agencia = VectorGet(banco->agencias, i);
        if(ComparaAgencia(numAgencia, agencia)){
            AdicionaConta(agencia, cliente);
            break;
        }
    }
}

void ImprimeRelatorioBanco(tBanco *banco){
    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");
    int total = VectorSize(banco->agencias);
    for(int i=0; i<total; i++){
        tAgencia* agencia = VectorGet(banco->agencias, i);
        ImprimeDadosAgencia(agencia);
    }
}