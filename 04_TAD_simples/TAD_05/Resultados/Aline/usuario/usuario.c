#include "usuario.h"
#include <stdio.h>

tUsuario CriaUsuario(char nome[20], char cpf[15]){
	tUsuario user;
	int i;
	for(i=0; i<20; i++){
		user.nome[i] = nome[i];
		if(nome[i] == '\0'){
			break;
		}
	}
	for(i=0; i<15; i++){
		user.cpf[i] = cpf[i];
		if(cpf[i] == '\0'){
			break;
		}
	}
	
	return user;
}

void ImprimeUsuario(tUsuario user){
	printf("Nome: %s\n", user.nome);
	printf("CPF: %s\n", user.cpf);
}
