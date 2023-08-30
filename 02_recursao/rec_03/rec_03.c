#include <stdio.h>

int ContaOcorrencias(int* vet, int numElementos, int numProcurado){
    int i, ocorrencias = 0;
    for(i=0; i<numElementos; i++){
        if(vet[i] == numProcurado){
            ocorrencias++;
        }
    }
    printf("%d\n", ocorrencias);
    
    int qtd, oco, x;
    if(scanf("%d", &x)==1){
        scanf("%d", &qtd);
        int v[qtd];
        for(i=0; i<qtd; i++){
            scanf("%d", &v[i]);
        }
        oco = ContaOcorrencias(v, qtd, x);
    }
    
    return ocorrencias;
}

int main(){
    int n, qtd, i, oco, x;
    
    scanf("%d", &n);
    scanf("%d", &x);
    scanf("%d", &qtd);

    int v[qtd];
    for(i=0; i<qtd; i++){
        scanf("%d", &v[i]);
    }
    
    oco = ContaOcorrencias(v, qtd, x);
    return 0;
}