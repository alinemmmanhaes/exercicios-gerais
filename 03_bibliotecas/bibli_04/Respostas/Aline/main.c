#include <stdio.h>
#include "data.h"

int main(){
    int dia1, mes1, ano1, resp;
    
    scanf("%d/%d/%d", &dia1, &mes1, &ano1);

    if(verificaDataValida(dia1, mes1, ano1) == 0){
        printf("A data informada eh invalida\n");
        return 1;
    }
    
    printf("Data informada: ");
    imprimeDataExtenso(dia1, mes1, ano1);
    
    resp = verificaBissexto(ano1);
    if(resp == 1){
    	printf("O ano informado eh bissexto\n");
    }
    else if(resp == 0){
    	printf("O ano informado nao eh bissexto\n");
    }

    resp = numeroDiasMes(mes1, ano1);
    printf("O mes informado possui %02d dias\n", resp);

    printf("A data seguinte eh: ");
    imprimeProximaData(dia1 + 1, mes1, ano1);
    
    return 0;
}
