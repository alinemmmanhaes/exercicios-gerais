#include <stdio.h>
#include "utils_char.h"

int main(){
    int total=0;
    scanf("%d\n", &total);

    char* vetor = CriaVetor(total);

    ImprimeString(vetor, total);
    LeVetor(vetor, total);
    ImprimeString(vetor, total);

    LiberaVetor(vetor);

    return 0;
}