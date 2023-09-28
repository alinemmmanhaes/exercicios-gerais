#include "funcionario.h"
#include "empresa.h"
#include <stdio.h>

tEmpresa criaEmpresa(int id){
    tEmpresa emp;
    emp.id = id;
    emp.qtdFuncionarios = 0;
    return emp;
}

tEmpresa leEmpresa(){
    int id=-1, qtd=-1, i=-1, j=-1, flag=-1;
    tEmpresa emp;
    tFuncionario func;
    scanf("%d %d", &id, &qtd);
    emp = criaEmpresa(id);
    for(i=0; i<qtd; i++){
    	func = leFuncionario();
    	flag = 0;
    	for(j=0; j<i; j++){
    	    if(getIdFuncionario(emp.funcionarios[j]) == getIdFuncionario(func)){
    	    	printf("A empresa %d ja possui um funcionario com o id %d\n", emp.id, func.id);
    	    	flag = 1;
    	    	break;
    	    }
    	}
    	if(flag == 0){
    	    emp = contrataFuncionarioEmpresa(emp, func);
    	}
    }
    return emp;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){
    int i;
    for(i=0; i<empresa.qtdFuncionarios; i++){
        if(getIdFuncionario(empresa.funcionarios[i]) == -1){
            break;
        }
    }
    empresa.funcionarios[i] = funcionario;
    empresa.qtdFuncionarios++;
    
    return empresa;
}

void imprimeEmpresa(tEmpresa empresa){
    int i;
    printf("Empresa %d:\n", empresa.id);
    for(i=0; i<empresa.qtdFuncionarios; i++){
        imprimeFuncionario(empresa.funcionarios[i]);
    }
    printf("\n");
}
