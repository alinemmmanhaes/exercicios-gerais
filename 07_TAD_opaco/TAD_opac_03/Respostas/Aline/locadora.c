#include "filme.h"
#include "locadora.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct Locadora{
    tFilme** filmes;
    int numFilmes;
    int lucro;
};

tLocadora* CriarLocadora (){
    tLocadora* locadora = malloc(sizeof(tLocadora));
    locadora->filmes = NULL;
    locadora->numFilmes = 0;
    locadora->lucro = 0;

    return locadora;
}

void DestruirLocadora (tLocadora* locadora){
    for(int i=0; i<locadora->numFilmes; i++){
        DestruirFilme(locadora->filmes[i]);
    }
    free(locadora->filmes);
    free(locadora);
}

int VerificarFilmeCadastrado (tLocadora* locadora, int codigo){
    for(int i=0; i<locadora->numFilmes; i++){
        if(EhMesmoCodigoFilme(locadora->filmes[i], codigo)){
            return 1;
        }
    }
    return 0;
}

void CadastrarFilmeLocadora (tLocadora *locadora, tFilme *filme){
    (locadora->numFilmes)++;
    int i = locadora->numFilmes;
    locadora->filmes = realloc(locadora->filmes, i*sizeof(tFilme*));
    locadora->filmes[i-1] = filme;
}

void LerCadastroLocadora (tLocadora* Locadora){
    int cod;
    scanf("%d,", &cod);
    tFilme* filme = CriarFilme();
    LeFilme(filme, cod);
    CadastrarFilmeLocadora(Locadora, filme);
}

void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    for(int i=0; i<quantidadeCodigos; i++){
        for(int j=0; j<locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(locadora->filmes[j], codigos[i])){
                if(ObterQtdEstoqueFilme(locadora->filmes[j]) > 0 ){
                    AlugarFilme(locadora->filmes[j]);
                    break;
                }
            }
        }
    }
}

void LerAluguelLocadora (tLocadora* locadora){
    int c, total=0;
    int*codigos = NULL;
    while (scanf("%d",&c) == 1){
        total++;
        codigos = realloc(codigos, total*sizeof(int));
        codigos[total-1] = c;
    }
    AlugarFilmesLocadora(locadora, codigos, total);
}

void DevolverFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    
}