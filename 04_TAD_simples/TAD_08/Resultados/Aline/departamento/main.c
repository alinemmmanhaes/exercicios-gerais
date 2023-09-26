#include "departamento.h"
#include <stdio.h>

int main(){
    int n, m1, m2, m3, i;
    char nome[101], c1[101], c2[101], c3[101], dir[101];
    
    scanf("%d", &n);
    tDepartamento dep[n];
    
    for(i=0; i<n; i++){
        scanf("%s", nome);
        scanf("%s", dir);
        scanf("%s", c1);
        scanf("%s", c2);
        scanf("%s", c3);
        scanf("%d %d %d", &m1, &m2, &m3);
        if(validaMediaDepartamento(m1) && validaMediaDepartamento(m2) && validaMediaDepartamento(m3)){
            dep[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, dir);
        }
    }
    ordenaPorMediaDepartamentos(dep, n);

    for(i=0; i<n; i++){
        imprimeAtributosDepartamento(dep[i]);
        printf("\n");
    }

    return 0;
}