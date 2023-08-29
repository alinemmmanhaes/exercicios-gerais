#include <stdio.h>

void ImprimeInvertido(char* string){
    int i, j;
    for(i=0; i<1000; i++){
        if(string[i]=='\0' || string[i] == 32){
            break;
        }
    }
    
    if(i!=0){
        for(j=i-1; j>=0; j--){
            printf("%c", string[j]);
        }
        printf(" ");
        
        if(scanf("%s", string) == 1){
            ImprimeInvertido(string);
        }
    }    
}

int main(){
    char string[1000];
    int i;
    
    if(scanf("%s", string) == 1){
        ImprimeInvertido(string);
    }
    
    return 0;
}