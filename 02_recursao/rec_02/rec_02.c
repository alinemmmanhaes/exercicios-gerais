#include <stdio.h>

int SomaElementosPares(int* vet, int numElementos){
    int i, somapar = 0;
    for(i=0; i<numElementos; i++){
        if(vet[i]%2 == 0){
            somapar += vet[i];
        }
    }
    printf("%d\n", somapar);
    
    int qtd, soma;
    if(scanf("%d", &qtd)==1){
        int v[qtd];
        for(i=0; i<qtd; i++){
            scanf("%d", &v[i]);
        }
        soma = SomaElementosPares(v, qtd);
    }
    
    return somapar;
}

int main(){
    int n, qtd, i, soma;
    
    scanf("%d", &n);
    scanf("%d", &qtd);
    
    int v[qtd];
    for(i=0; i<qtd; i++){
        scanf("%d", &v[i]);
    }
    
    soma = SomaElementosPares(v, qtd);
    return 0;
}