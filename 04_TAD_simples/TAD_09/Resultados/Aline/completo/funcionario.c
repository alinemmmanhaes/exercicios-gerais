#include "funcionario.h"
#include <stdio.h>

tFuncionario criaFuncionario(int id, float salario){
    tFuncionario f;
    f.id = id;
    f.salario = salario;
    return f;
}

tFuncionario leFuncionario(){
    int id;
    float salario;
    tFuncionario f;
    scanf("%d %f", &id, &salario);
    f = criaFuncionario(id, salario);
    return f;
}

int getIdFuncionario(tFuncionario funcionario){
    return funcionario.id;
}

void imprimeFuncionario(tFuncionario funcionario){
    printf("- Funcionario %d: RS %.2f\n", funcionario.id, funcionario.salario);
}