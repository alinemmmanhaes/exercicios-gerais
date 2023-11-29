#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

struct Vector
{
    int tam;
    data_type* vetor;
};

Vector *VectorConstruct(){
    Vector* vetor = malloc(sizeof(Vector));
    if(vetor == NULL){
        exit(1);
    }
    vetor->tam = 0;
    vetor->vetor = NULL;
    return vetor;
}

void VectorPushBack(Vector *v, data_type val){
    (v->tam)++;
    v->vetor = realloc(v->vetor, (v->tam)*sizeof(data_type*));
    v->vetor[(v->tam)-1] = val;
}

data_type VectorGet(Vector *v, int i){
    return v->vetor[i];
}

int VectorSize(Vector *v){
    return v->tam;
}

void VectorDestroy(Vector *v, void (*destroy)(data_type)){
    for(int i=0; i<v->tam; i++){
        destroy(v->vetor[i]);
    }
    free(v->vetor);
    free(v);
}