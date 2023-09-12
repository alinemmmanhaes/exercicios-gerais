#include "esfera_utils.h"
#include <stdio.h>

int main(){
    float r, area, vol;

    scanf("%f", &r);
    area = calcula_area(r);
    vol = calcula_volume(r);
    printf("Area: %.2f\n", area);
    printf("Volume: %.2f\n", vol);
    return 0;
}