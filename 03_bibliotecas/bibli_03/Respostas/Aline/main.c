#include <stdio.h>
#include "data.h"

int main(){
    int dia1, mes1, ano1, dia2, mes2, ano2, resp;
    
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);
    scanf("%d/%d/%d", &dia2, &mes2, &ano2);

    if(verificaDataValida(dia1, mes1, ano1) == 0 || verificaDataValida(dia2, mes2, ano2) == 0){
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        return 1;
    }
    
    printf("Primeira data: ");
    imprimeDataExtenso(dia1, mes1, ano1);
    printf("Segunda data: ");
    imprimeDataExtenso(dia2, mes2, ano2);
    
    resp = comparaData( dia1, mes1, ano1, dia2, mes2, ano2);
    if(resp == 1){
    	printf("A segunda data eh mais antiga\n");
    }
    else if(resp == -1){
    	printf("A primeira data eh mais antiga\n");
    }
    else if(resp == 0){
    	printf("As datas sao iguais\n");
    }

    resp = calculaDiferencaDias(dia1, mes1, ano1, dia2, mes2, ano2);
    printf("A diferenca em dias entre as datas eh: %02d dias\n", resp);
    return 0;
}
