#include <stdio.h>
#include "string_utils.h"

int main(){
    char str[1000], copy[1000];
    int op = 0, tam;

    scanf ( "%[^\n]", str);

    while(op!=6){
        printf("1 - Tamanho da string\n2 - Copiar string\n3 - Converter string para letras maiusculas\n4 - Converter string para letras minusculas\n5 - Imprimir string ao contrario\n6 - Encerrar o programa\nOpcao escolhida: \n");
        scanf("%d", &op);
        if(op==6){
            break;
        }
        if(op==1){
            tam = string_length(str);
            printf("Tamanho da string: %d\n\n", tam);
        }
        else if(op==2){
            string_copy(str, copy);
            printf("String copiada: %s\n\n", copy);
        }
        else if(op==3){
            string_upper(str);
            printf("String convertida para maiusculas: %s\n\n", str);
        }
        else if(op==4){
            string_lower(str);
            printf("String convertida para minusculas: %s\n\n", str);
        }
        else if(op==5){
            string_reverse(str);
            printf("String invertida: %s\n\n", str);
        }
    }
    return 0;
}
