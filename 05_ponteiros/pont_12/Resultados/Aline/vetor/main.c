#include "vetor.h"
#include <stdio.h>

int soma(int n1, int n2){
    return n1 + n2;
}
int produto(int n1, int n2){
    return n1*n2;
}

int main(){
    Vetor vetor;
    int s, p;
    
    LeVetor(&vetor);
    s = AplicarOperacaoVetor(&vetor, soma);
    p = AplicarOperacaoVetor(&vetor, produto);
    
    printf("Soma: %d\nProduto: %d\n", s, p);
    
    return 0;
}