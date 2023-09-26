#include "departamento.h"
#include <stdio.h>
#include <math.h>

double calculaMediaGeralDepartamento(tDepartamento depto){
    double media;
    media = (double)(depto.m1+depto.m2+depto.m3)/3;
    return media;
}

tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor){
    int i;
    tDepartamento dep;
    for(i=0; i<101; i++){
        dep.c1[i] = c1[i];
        if(c1[i] == '\0'){
            break;
        }
    }
    for(i=0; i<101; i++){
        dep.c2[i] = c2[i];
        if(c2[i] == '\0'){
            break;
        }
    }
    for(i=0; i<101; i++){
        dep.c3[i] = c3[i];
        if(c3[i] == '\0'){
            break;
        }
    }
    for(i=0; i<101; i++){
        dep.nome[i] = nome[i];
        if(nome[i] == '\0'){
            break;
        }
    }
    for(i=0; i<101; i++){
        dep.diretor[i] = diretor[i];
        if(diretor[i] == '\0'){
            break;
        }
    }
    dep.m1 = m1;
    dep.m2 = m2;
    dep.m3 = m3;
    dep.media_geral = calculaMediaGeralDepartamento(dep);
    return dep;
}

double calculaDesvioPadraoDepartamento(tDepartamento depto){
    double dp;
    dp = (double)(pow(depto.m1 - depto.media_geral, 2) + pow(depto.m2 - depto.media_geral, 2) + pow(depto.m3 - depto.media_geral, 2));
    dp = dp/3;
    dp = sqrt(dp);
    return dp;
}

void imprimeAtributosDepartamento (tDepartamento depto){
    double dp;
    dp = calculaDesvioPadraoDepartamento(depto);
    printf("ATRIBUTOS:\ndepartamento => %s\ndiretor => %s\ncurso1 => %s, media1 => %d\ncurso2 => %s, media2 => %d\ncurso3 => %s, media3 => %d\nmedia geral => %.2lf\ndesvio padrao => %.2lf\n", depto.nome, depto.diretor, depto.c1, depto.m1, depto.c2, depto.m2, depto.c3, depto.m3, depto.media_geral, dp);
}

int validaMediaDepartamento (int media){
    if(media>=0 && media<=10){
        return 1;
    }
    return 0;
}

void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho){
    double maior = 0;
    tDepartamento aux;
    int im, i, j;
    for(i=0; i<tamanho; i++){
        maior = d[i].media_geral;
        im = i;
        for(j=i+1; j<tamanho; j++){
            if(d[j].media_geral>maior){
                maior = d[j].media_geral;
                im = j;
            }
        }
        aux = d[i];
        d[i] = d[im];
        d[im] = aux;
    }
}