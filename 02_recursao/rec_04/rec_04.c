#include <stdio.h>

int Palindromo(char* string, int tamanho){
    int i, j, ver=1, resp;
    for(i=0, j=tamanho-1; i<tamanho; i++, j--){
        if(string[i] != string[j]){
            ver = 0;
            break;
        }
    }
    if(ver){
        printf("SIM\n");
    }else{
        printf("NAO\n");
    }

    char pal[1000];
    if(scanf("%s", pal)==1){
        for(i=0; i<1000; i++){
            if(pal[i]=='\0'){
                break;
            }
        }
       resp = Palindromo(pal, i); 
    }
    return ver;
}

int main(){
    int resp, i;
    char pal[1000];
    if(scanf("%s", pal)==1){
        for(i=0; i<1000; i++){
            if(pal[i]=='\0'){
                break;
            }
        }
       resp = Palindromo(pal, i); 
    }
    return 0;
}