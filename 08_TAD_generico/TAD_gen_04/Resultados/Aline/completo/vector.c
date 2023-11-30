#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

struct Vector
{
    int tam;
    DataType* vetor;
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

void VectorPushBack(Vector *v, DataType val){
    (v->tam)++;
    v->vetor = realloc(v->vetor, (v->tam)*sizeof(DataType*));
    v->vetor[(v->tam)-1] = val;
}

DataType VectorGet(Vector *v, int i){
    return v->vetor[i];
}

int VectorSize(Vector *v){
    return v->tam;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)){
    for(int i=0; i<v->tam; i++){
        destroy(v->vetor[i]);
    }
    free(v->vetor);
    free(v);
}