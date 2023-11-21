#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct generic{
   Type type;
   int numElem;
   void** vetor;
};

tGeneric* CriaGenerico(Type type, int numElem){
    tGeneric* generico = malloc(sizeof(tGeneric));
    generico->type = type;
    generico->numElem = numElem;
    int tam;
    if(type == 0){
        tam = sizeof(float);
    }
    else if(type == 1){
        tam = sizeof(int);
    }
    generico->vetor = malloc(numElem* tam);
    return generico;
}

void DestroiGenerico(tGeneric* gen){
    free(gen->vetor);
    free(gen);
}

void LeGenerico(tGeneric* gen){
    if(gen->type == 0){
        float fnum;
        for(int i=0; i<gen->numElem; i++){
            void* ptr = gen->vetor +(i*sizeof(float));
            scanf("%f", &fnum);
            memcpy(ptr, &fnum, sizeof(float));
        }
    }
    else if(gen->type == 1){
        int inum;
        for(int i=0; i<gen->numElem; i++){
            void* ptr = gen->vetor +(i*sizeof(int));
            scanf("%d", &inum);
            memcpy(ptr, &inum, sizeof(int));
        }
    }
}

void ImprimeGenerico(tGeneric* gen){
    printf("Digite o vetor:\n");
    if(gen->type == 0){
        for(int i=0; i<gen->numElem; i++){
            float fnum;
            void* ptr = gen->vetor +(i*sizeof(float));
            memcpy(&fnum, ptr, sizeof(float));
            printf("%.2f", fnum);
        }
    }
    else if(gen->type == 1){
        for(int i=0; i<gen->numElem; i++){
            int inum;
            void* ptr = gen->vetor +(i*sizeof(int));
            memcpy(&inum, ptr, sizeof(int));
            printf("%d", inum);
        }
    }
}