#include "funcionario.h"
#include "empresa.h"
#include <stdio.h>

int main(){
    int n, i, j;
    tFuncionario func;
    
    scanf("%d", &n);
    tEmpresa emp[n];

    for(i=0; i<n; i++){
        emp[i] = leEmpresa();
        for(j=0; j<emp[i].qtdFuncionarios; j++){
            func = leFuncionario();
            emp[i] = contrataFuncionarioEmpresa(emp[i], func);
        }
    }

    for(i=0; i<n; i++){
        imprimeEmpresa(emp[i]);
    }

    return 0;
}