#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int l, c, **mat;
    scanf("%d %d", &l, &c);
    mat = CriaMatriz(l, c);
    LeMatriz(mat, l, c);
    ImprimeMatrizTransposta(mat, l, c);
    LiberaMatriz(mat, l);
    return 0;
}