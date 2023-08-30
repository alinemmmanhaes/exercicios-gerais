#include <stdio.h>

int fatorial(int n){
    int fat;
    if(n>1){
        fat = fatorial(n-1);
        fat = fat*n;
    }else if (n==1 || n==0){
        fat = 1;
    }
    return fat;
}

int main(){
    int num, fat;
    scanf("%d", &num);
    fat = fatorial(num);
    printf("%d\n", fat);
    return 0;
}