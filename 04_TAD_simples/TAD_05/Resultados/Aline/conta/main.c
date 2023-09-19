#include "usuario.h"
#include "conta.h"
#include <stdio.h>

int main(){
	int n, op=9, c=0, id, i;
	float valor;

    scanf("%d", &n);
	tConta conta[n];
    tUsuario user[n];
	
	while(op!=0){
		scanf("%d", &op);
		if(op == 0){
			break;
		}
		else if(op == 1){
			scanf("%d %f", &id, &valor);
			for(i=0; i<c; i++){
				if(VerificaConta(conta[i], id)){
					conta[i] = SaqueConta(conta[i], valor);
					break;
				}
			}
		}
		else if(op == 2){
			scanf("%d %f", &id, &valor);
			for(i=0; i<c; i++){
				if(VerificaConta(conta[i], id)){
					conta[i] = DepositoConta(conta[i], valor);
					break;
				}
			}
		}
        else if(op == 3){
            char nome[50], cpf[15];
            int numero;
            scanf("%s %s %d", nome, cpf, &numero);
            if(c<n){
                user[c] = CriaUsuario(nome, cpf);
                conta[c] = CriaConta(numero, user[c]);
                c++;
            }
        }
        else if(op == 4){
            printf("===| Imprimindo Relatorio |===\n");
            for(i=0; i<c; i++){
				ImprimeConta(conta[i]);
                printf("\n");
			}
        }
	}
	return 0;
}
