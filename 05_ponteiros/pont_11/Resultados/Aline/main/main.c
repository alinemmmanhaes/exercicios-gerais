#include "calculadora.h"
#include <stdio.h>

float soma(float n1, float n2){
    return n1+n2;
}
float sub(float n1, float n2){
    return n1-n2;
}
float mux(float n1, float n2){
    return n1*n2;
}
float div(float n1, float n2){
    return n1/n2;
}

int main(){
    char op;
    float n1, n2, res;
    while(1){
        scanf("%c%*c", &op);
        if(op == 'f'){
            break;
        }
        else if(op == 'a'){
            scanf("%f %f\n", &n1, &n2);
            res = Calcular(n1, n2, soma);
            printf("%.2f + %.2f = %.2f\n", n1, n2, res);
        }
        else if(op == 's'){
            scanf("%f %f\n", &n1, &n2);
            res = Calcular(n1, n2, sub);
            printf("%.2f - %.2f = %.2f\n", n1, n2, res);
        }
        else if(op == 'm'){
            scanf("%f %f\n", &n1, &n2);
            res = Calcular(n1, n2, mux);
            printf("%.2f x %.2f = %.2f\n", n1, n2, res);
        }
        else if(op == 'd'){
            scanf("%f %f\n", &n1, &n2);
            res = Calcular(n1, n2, div);
            printf("%.2f / %.2f = %.2f\n", n1, n2, res);
        }
    }
}