#include "usuario.h"
#include "conta.h"
#include <stdio.h>

tConta CriaConta(int numero, tUsuario user){
	tConta conta;
	conta.numero = numero;
	conta.user = user;
	conta.saldo = 0;
	return conta;
}

void ImprimeConta(tConta conta){
	printf("Conta: %d\n", id);
	printf("Saldo: R$ %.2f\n", saldo);
	ImprimeUsuario(conta.user);
}

int VerificaConta(tConta conta, int numero){
	if(conta.numero = numero){
		return 1;
	}
	return 0;
}

tConta SaqueConta(tConta conta, float valor){
	conta.saldo -= valor;
	return conta;
}

tConta DepositoConta(tConta conta, float valor){
	conta.saldo += valor;
	return conta;
}
