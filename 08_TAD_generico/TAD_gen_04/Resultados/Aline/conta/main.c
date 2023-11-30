#include "banco.h"
#include "agencia.h"
#include "conta.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    tBanco* banco = CriaBanco();
    LeBanco(banco);

    char c = 'B';
    while(1){
        scanf("%c", &c);
        if(c == 'A'){
            tAgencia* agencia = CriaAgencia();
            LeAgencia(agencia);
            AdicionaAgencia(banco, agencia);
        }
        else if(c == 'C'){
            tConta* conta = CriaConta();
            LeConta(conta);
            int numAgencia = 0;
            scanf("%d%*c", &numAgencia);
            InsereContaBanco(banco, numAgencia, conta);
        }
        else if(c == 'F'){
            break;
        }
    }

    ImprimeRelatorioBanco(banco);

    DestroiBanco(banco);
    return 0;
}