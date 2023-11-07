#include <stdio.h>
#include "utils_char2.h"

int main(){
    char* vetor = CriaVetorTamPadrao();
    int total = 11;

    vetor = LeVetor(vetor, &total);
    ImprimeString(vetor);
    LiberaVetor(vetor);

    return 0;
}