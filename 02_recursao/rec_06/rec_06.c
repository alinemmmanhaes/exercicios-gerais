#include <stdio.h>

int fibonacci(int n){
    int resp;
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    
    resp = fibonacci(n-1) + fibonacci(n-2);
    return resp;
}

int main(){
    int n, fib;
    
    scanf("%d", &n);
    
    fib = fibonacci(n);
    printf("%d\n", fib);
    
    return 0;
}