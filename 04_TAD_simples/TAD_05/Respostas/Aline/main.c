#include "usuario.h"
#include "conta.h"
#include <stdio.h>

int main(){
	int n, op=9, c=0, id, i;
	float valor;
	tConta conta[n];
	
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
	}
	return 0;
}
