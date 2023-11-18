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
    if(VerificarFilmeCadastrado(locadora, ObterCodigoFilme(filme)) == 0){
        if(locadora->numFilmes < 100){
            (locadora->numFilmes)++;
            int i = locadora->numFilmes;
            locadora->filmes = realloc(locadora->filmes, i*sizeof(tFilme*));
            locadora->filmes[i-1] = filme;
        }
    }
    else{
        printf("Filme ja cadastrado no estoque.\n");
    }
}

void LerCadastroLocadora (tLocadora* Locadora){
    int cod;
    scanf("%d,", &cod);
    tFilme* filme = CriarFilme();
    LeFilme(filme, cod);
    CadastrarFilmeLocadora(Locadora, filme);
}

void AlugarFilmesLocadora (tLocadora* locadora, int* codigos, int quantidadeCodigos){
    int flag = 0;
    for(int i=0; i<quantidadeCodigos; i++){
        flag = 0;
        for(int j=0; j<locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(locadora->filmes[j], codigos[i])){
                flag++;
                if(ObterQtdEstoqueFilme(locadora->filmes[j]) > 0 ){
                    AlugarFilme(locadora->filmes[j]);
                    break;
                }
                else{
                    printf("Filme ");
                    ImprimirNomeFilme(locadora->filmes[j]);
                    printf(" - %d nao disponivel no estoque. Volte mais tarde.\n", codigos[i]);
                }
            }
        }
        if(flag == 0){
            printf("Filme %d nao  cadastrado\n", codigos[i]);
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
    int flag = 0;
    for(int i=0; i<quantidadeCodigos; i++){
        flag = 0;
        for(int j=0; j<locadora->numFilmes; j++){
            if(EhMesmoCodigoFilme(locadora->filmes[j], codigos[i])){
                flag++;
                if(ObterQtdAlugadaFilme(locadora->filmes[j]) == 0){
                    printf("Nao e possivel devolver o filme ");
                    ImprimirNomeFilme(locadora->filmes[j]);
                    printf(" - %d\n", codigos[i]);
                }
                else{
                    DevolverFilme(locadora->filmes[j]);
                }
                break;
            }
        }
        if(flag == 0){
            printf("Filme %d nao  cadastrado\n", codigos[i]);
        }
    }
}

void LerDevolucaoLocadora (tLocadora* locadora){
    int c, total=0;
    int*codigos = NULL;
    while (scanf("%d",&c) == 1){
        total++;
        codigos = realloc(codigos, total*sizeof(int));
        codigos[total-1] = c;
    }
    DevolverFilmesLocadora(locadora, codigos, total);
}

void OrdenarFilmesLocadora (tLocadora* locadora){
    tFilme* aux;
    int indice = 0;
    for(int i=0; i<locadora->numFilmes; i++){
        aux = locadora->filmes[i];
        indice = i;
        for(int j=i+1; j<locadora->numFilmes; j++){
            if(CompararNomesFilmes(locadora->filmes[i], locadora->filmes[j]) == 1){
                aux = locadora->filmes[j];
                indice = j;
            }
        }
        locadora->filmes[indice] = locadora->filmes[i];
        locadora->filmes[i] = aux;
    }
}

void ConsultarEstoqueLocadora (tLocadora* locadora){
    
}