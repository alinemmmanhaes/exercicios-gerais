#include "pacote.h"
#include <stdio.h>
#include <stdlib.h>

struct pacote{
    Type tipo;
    int total;
    void* vetor;
    int soma;
};

tPacote* CriaPacote(Type type, int numElem){
    tPacote* pacote = malloc(sizeof(tPacote));
    pacote->tipo = type;
    pacote->total = numElem;
    pacote->soma = 0;
    int tam = 0;
    if(type == 2){
        tam = sizeof(char);
    }
    else if(type == 1){
        tam = sizeof(int);
    }
    pacote->vetor = malloc(pacote->total*tam);
    return pacote;
}

void DestroiPacote(tPacote* pac){
    free(pac->vetor);
    free(pac);
}

void LePacote(tPacote* pac){
    scanf("%*c");
    printf("\nDigite o conteúdo do vetor/mensagem: ");
    for(int i=0; i<pac->total; i++){
        if(pac->tipo == INT){
            int* num = (int*) pac->vetor;
            scanf("%d", &num[i]);
        }
        else if(pac->tipo == CHAR){
            scanf("%c", &pac->vetor[i]);
        }
    }
}

void ImprimePacote(tPacote* pac){
    CalculaSomaVerificacaoPacote(pac);
    printf("%d ", pac->soma);
    for(int i=0; i<pac->total; i++){
        if(pac->tipo == INT){
            void* ptr = pac->vetor +(i*sizeof(int));
            int* num = (int*) ptr;
            if(i+1 == pac->total){
                printf("%d", *num);
            }
            else{
                printf("%d ", *num);
            }
        }
        else if(pac->tipo == CHAR){
            void* ptr = pac->vetor +(i*sizeof(char));
            char* c = (char*) ptr;
            printf("%c", *c);
        }
    }
    printf("\n");
}

void CalculaSomaVerificacaoPacote(tPacote* pac){
    pac->soma = 0;
    for(int i=0; i<pac->total; i++){
        if(pac->tipo == INT){
            void* ptr = pac->vetor +(i*sizeof(int));
            int* num = (int*) ptr;
            (pac->soma) += *num;
        }
        else if(pac->tipo == CHAR){
            void* ptr = pac->vetor +(i*sizeof(char));
            char* c = (char*) ptr;
            if(*c != '\n'){
                (pac->soma) += *c;
            }
        }
    }
}