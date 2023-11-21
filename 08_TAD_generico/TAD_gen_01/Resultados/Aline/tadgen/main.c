#include "tadgen.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int type, qtd;
    printf("tad_gen_01\nDigite o tipo e numero de elementos: \n");
    scanf("%d %d", &type, &qtd);
    tGeneric* gen = CriaGenerico(type, qtd);
    LeGenerico(gen);
    ImprimeGenerico(gen);
    DestroiGenerico(gen);
    return 0;
}