#include "filme.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Filme{
    char nome[MAX_CARACTERES];
    int codigo;
    int valor;
    int qtdalugada;
    int qtdestoque;
};

tFilme* CriarFilme(){
    tFilme* filme = malloc(sizeof(tFilme));
    filme->qtdalugada = 0;
    return filme;
}

void LeFilme(tFilme *filme, int codigo){
    scanf("%[^,],%d,%d", filme->nome, &filme->valor, &filme->qtdestoque);
    filme->codigo = codigo;
}

void DestruirFilme (tFilme* filme){
    free(filme);
}

int ObterCodigoFilme (tFilme* filme){
    return filme->codigo;
}

void ImprimirNomeFilme (tFilme* filme){
    printf("%s", filme->nome);
}

int ObterValorFilme (tFilme* filme){
    return filme->valor;
}

int ObterQtdEstoqueFilme (tFilme* filme){
    return filme->qtdestoque;
}

int ObterQtdAlugadaFilme (tFilme* filme){
    return filme->qtdalugada;
}

int EhMesmoCodigoFilme (tFilme* filme, int codigo){
    if(filme->codigo == codigo){
        return 1;
    }
    return 0;
}

void AlugarFilme (tFilme* filme){
    (filme->qtdalugada)++;
    (filme->qtdestoque)--;
}

void DevolverFilme (tFilme* filme){
    (filme->qtdalugada)--;
    (filme->qtdestoque)++;
}

int CompararNomesFilmes (tFilme* filme1, tFilme* filme2){
    return strcmp(filme1->nome, filme2->nome);
}