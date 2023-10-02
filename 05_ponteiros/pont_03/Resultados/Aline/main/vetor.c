#include "vetor.h"
#include <stdio.h>

void LeDadosParaVetor(int * vet, int tam){
	int i;
	for(i=0; i<tam; i++){
		scanf("%d", &vet[i]);
	}
}

void ImprimeDadosDoVetor(int * n, int tam){
	int i;
	for(i=0; i<tam; i++){
		printf("%d ", n[i]);
	}
	printf("\n");
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar){
	int i, menor, im, flag=0;
	menor = *paraTrocar;
	for(i=0; i<tam; i++){
		if(vet[i] == *paraTrocar){
			flag = 1;
		}
		if(vet[i]<menor && flag){
			menor = vet[i];
			im = i;
		}
	}
	
	if(*paraTrocar != menor){
		vet[im] = *paraTrocar;
		*paraTrocar = menor;
	}
}

void OrdeneCrescente(int * vet, int tam){
	int i, paraTrocar;
	for(i=0; i<tam; i++){
		paraTrocar = vet[i];
		TrocaSeAcharMenor(vet, tam, &paraTrocar);
		vet[i] = paraTrocar;
	}
}
