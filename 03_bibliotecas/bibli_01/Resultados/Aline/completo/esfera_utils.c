#define PI 3.14

float calcula_volume(float R){
    float vol;
    vol = (PI*R*R*R*4)/3;
    return vol;
}

float calcula_area(float R){
    float area;
    area = 4*PI*R*R;
    return area;
}
