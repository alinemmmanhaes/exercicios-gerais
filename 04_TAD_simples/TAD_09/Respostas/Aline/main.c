#include "funcionario.h"
#include "empresa.h"
#include <stdio.h>

int main(){
    int n, i, j, k, flag;
    tFuncionario func;
    
    scanf("%d", &n);
    tEmpresa emp[n];

    for(i=0; i<n; i++){
        emp[i] = leEmpresa();
    }

    for(i=0; i<n; i++){
        imprimeEmpresa(emp[i]);
    }

    return 0;
}
