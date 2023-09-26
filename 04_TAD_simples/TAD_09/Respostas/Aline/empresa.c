#include "funcionario.h"
#include "empresa.h"
#include <stdio.h>

tEmpresa criaEmpresa(int id){
    tEmpresa emp;
    int i;
    emp.id = id;
    scanf("%d", &emp.qtdFuncionarios);
    for(i=0; i<emp.qtdFuncionarios; i++){
        emp.funcionarios[i].id = -1;
    }
    return emp;
}

tEmpresa leEmpresa(){
    int id, qtd;
    tEmpresa emp;
    scanf("%d", &id);
    emp = criaEmpresa(id);
    return emp;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){
    int i, flag=0;
    for(i=0; i<empresa.qtdFuncionarios; i++){
        if(getIdFuncionario(empresa.funcionarios[i]) == -1){
            break;
        }
        if(getIdFuncionario(empresa.funcionarios[i]) == getIdFuncionario(funcionario)){
            flag = 1;
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, funcionario.id);
            break;
        }
    }
    if(flag == 0){
        empresa.funcionarios[i] = funcionario;
    }
    return empresa;
}

void imprimeEmpresa(tEmpresa empresa){
    int i;
    printf("Empresa %d:\n", empresa.id);
    for(i=0; i<empresa.qtdFuncionarios; i++){
        if(getIdFuncionario(empresa.funcionarios[i]) == -1){
            break;
        }
        imprimeFuncionario(empresa.funcionarios[i]);
    }
    printf("\n");
}