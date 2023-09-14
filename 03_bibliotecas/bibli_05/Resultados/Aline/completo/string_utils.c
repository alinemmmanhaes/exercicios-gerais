#include <stdio.h>
#include "string_utils.h"

int string_length(char *str){
    int i;
    for(i=0; i<1000; i++){
        if(str[i] == '\0'){
            break;
        }
    }
    
    return i+2;
}

void string_copy(char *src, char *dest){
    int i, tam;
    tam = string_length(src);
    for(i=0; i<tam-1; i++){
        dest[i] = src[i];
    }
}

void string_upper(char *str){
    int i, tam;
    tam = string_length(str);
    for(i=0; i<tam-1; i++){
        if(str[i]>='a' && str[i]<='z'){
            str[i] -= 32;
        }
    }
}

void string_lower(char *str){
    int i, tam;
    tam = string_length(str);
    for(i=0; i<tam-1; i++){
        if(str[i]>='A' && str[i]<='Z'){
            str[i] += 32;
        }
    }
}

void string_reverse(char *str){
    char copia[1000];
    int tam, i, j;
    
    string_copy(str, copia);
    tam = string_length(str);
    
    for(i=tam-3, j=0; i>=0; i--, j++){
        str[j] = copia[i];
    }
}
