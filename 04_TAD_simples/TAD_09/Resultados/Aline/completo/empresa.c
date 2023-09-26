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
    }
    empresa.funcionarios[i] = funcionario;
    
    return empresa;
}

void imprimeEmpresa(tEmpresa empresa){
    int i;
    printf("Empresa %d:\n", empresa.id);
}
