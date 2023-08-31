#include <stdio.h>

int somaDigitos(int n){
    int soma=0;
    
    soma+=n%10;
    n = n/10;
        
    if(n>0){
        soma+= somaDigitos(n);
    }
    return soma;
}

int main(){
    int n, soma;
    scanf("%d", &n);
    soma = somaDigitos(n);
    printf("%d\n", soma);
}