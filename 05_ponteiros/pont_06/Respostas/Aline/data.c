#include <stdio.h>
#include "data.h"

void InicializaDataParam( int dia, int mes, int ano, tData *data){
    (*data).dia = dia;
    (*data).mes = mes;
    (*data).ano = ano;
    if((*data).mes > 12){
        (*data).mes = 12;
    }
    if((*data).mes < 1){
        (*data).mes = 1;
    }
    if((*data).dia < 1){
        (*data).dia = 1;
    }
    if((*data).dia > InformaQtdDiasNoMes(data)){
        (*data).dia = InformaQtdDiasNoMes(data);
    }
}

void LeData( tData *data ){
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    InicializaDataParam(dia, mes, ano, data);
}

void ImprimeData( tData *data ){
    printf("'%02d/%02d/%02d'", data->dia, data->mes, data->ano);
}

int EhBissexto( tData *data ){
    if((data->ano%4==0 && data->ano%100!=0) || data->ano%400==0){
        return 1;
    }
    return 0;
}

int InformaQtdDiasNoMes( tData *data ){
    if((*data).mes == 1 || (*data).mes == 3 || (*data).mes == 5 || (*data).mes == 7 || (*data).mes == 8 || (*data).mes == 10 || (*data).mes == 12){
        return 31;
    }else if((*data).mes == 4 || (*data).mes == 6 || (*data).mes == 9 || (*data).mes == 11 ){
        return 30;
    }
    else if(EhBissexto(data)){
        if((*data).mes==2){
            return 29;
        }
    }
    else{
        return 28;
    }
}

void AvancaParaDiaSeguinte( tData *data ){
    if((*data).dia<InformaQtdDiasNoMes(data)){
        (*data).dia++;
    }
    else if((*data).dia == InformaQtdDiasNoMes(data)){
        (*data).dia = 1;
        if((*data).mes < 12){
            (*data).mes++;
        }
        else if((*data).mes == 12){
            (*data).mes = 1;
            (*data).ano++;
        }
    }
}

int EhIgual( tData *data1, tData *data2 ){
    if((*data1).dia == (*data2).dia){
        if((*data1).mes == (*data2).mes){
            if((*data1).ano == (*data2).ano){
                return 1;
            }
        }
    }
    return 0;
}