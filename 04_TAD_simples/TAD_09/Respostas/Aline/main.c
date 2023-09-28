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
        for(j=0; j<emp[i].qtdFuncionarios; j++){
            flag = 0;
            func = leFuncionario();
            for(k=0; k<j; k++){
                if(getIdFuncionario(emp[i].funcionarios[k]) == getIdFuncionario(func)){
                    printf("A empresa %d ja possui um funcionario com o id %d\n", emp[i].id, func.id);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                emp[i] = contrataFuncionarioEmpresa(emp[i], func);
            }
        }
    }

    for(i=0; i<n; i++){
        imprimeEmpresa(emp[i]);
    }

    return 0;
}