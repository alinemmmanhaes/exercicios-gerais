#include "data.h"
#include <stdio.h>

tData CriaData(int dia, int mes, int ano){
	tData data;
	data.dia = dia;
	data.mes = mes;
	data.ano = ano;
	return data;
}

int VerificaBissexto(tData data){
    if((data.ano%4==0 && data.ano%100!=0) || data.ano%400==0){
        return 1;
    }
    return 0;
}

int VerificaDataValida(tData data){
    if(data.mes>12 || data.mes<1){
        return 0;
    }
    if(data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12){
        if(data.dia>31 || data.dia <1){
            return 0;
        }
    }else if(data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11 ){
        if(data.dia>30 || data.dia <1){
            return 0;
        }
    }
    else if(VerificaBissexto(data)){
        if(data.mes==2){
            if(data.dia>29 || data.dia<1){
                return 0;
            }
        }
    }
    else{
        if(data.dia>28 || data.dia<1){
            return 0;
        }
    }
    return 1;
}

void ImprimeMesExtenso(tData data){
    if(data.mes==1){
        printf("Janeiro");
    }
    if(data.mes==2){
        printf("Fevereiro");
    }
    if(data.mes==3){
        printf("Março");
    }
    if(data.mes==4){
        printf("Abril");
    }
    if(data.mes==5){
        printf("Maio");
    }
    if(data.mes==6){
        printf("Junho");
    }
    if(data.mes==7){
        printf("Julho");
    }
    if(data.mes==8){
        printf("Agosto");
    }
    if(data.mes==9){
        printf("Setembro");
    }
    if(data.mes==10){
        printf("Outubro");
    }
    if(data.mes==11){
        printf("Novembro");
    }
    if(data.mes==12){
        printf("Dezembro");
    }
}

void ImprimeDataExtenso(tData data){
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %04d\n", data.ano);
}

int NumeroDiasMes(tData data){
    if(data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12){
        return 31;
    }else if(data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11 ){
        return 30;
    }
    else if(VerificaBissexto(data)){
        if(data.mes==2){
            return 29;
        }
    }
    else{
        return 28;
    }
}

int ComparaData(tData data1, tData data2){
    if(data1.ano > data2.ano){
        return 1;
    }
    else if(data1.ano < data2.ano){
    	return -1;
    }
    else{
    	if(data1.mes > data2.mes){
    	    return 1;
    	}
    	else if(data1.mes < data2.mes){
    	    return -1;
    	}
    	else{
    	    if(data1.dia > data2.dia){
    	    	return 1;
    	    }
    	    else if(data1.dia < data2.dia){
    	    	return -1;
    	    }
    	    else{
    	    	return 0;
    	    }
    	}
    }
}

int CalculaDiasAteMes(tData data){
    int dias=0, i;
    for(i=1; i<data.mes; i++){
        dias += NumeroDiasMes(data);
    }
    return dias;
}

int CalculaDiferencaDias(tData data1, tData data2){
    int resp, difano, difmes, difdia, dias=0, i, j;
    tData conta;
    resp = ComparaData(data1, data2);
    if(resp == 0){
    	return 0;
    }
    if(resp == 1){
    	difano = data1.ano-data2.ano;
    	if(difano == 0){
    	    difmes = data1.mes-data2.mes;
    	    if(difmes == 0){
    	    	difdia = data1.dia - data2.dia;
    	    	dias = difdia;
    	    }
    	    else{
    	    	dias = data1.dia;
    	    	difdia = NumeroDiasMes(data2) - data2.dia;
    	    	dias += difdia;
    	    	for(i=data2.mes+1; i<data1.mes; i++){
    	    	    conta = CriaData(20, i, data2.ano);
    	    	    dias += NumeroDiasMes(conta);
    	    	}
    	    }
    	}
    	else{
    	    for(j=data2.ano; j<data1.ano; j++){
    	    	for(i=1; i<=12; i++){
    	    	    conta = CriaData(20, i, j);
    	    	    dias += NumeroDiasMes(conta);
    	    	}
    	    }
    	    difdia = CalculaDiasAteMes(data1);
    	    dias += difdia;
    	    dias += data1.dia;
    	    difdia = CalculaDiasAteMes(data2);
    	    dias -= difdia;
    	    dias -= data2.dia;
    	}
    }
    else if(resp == -1){
    	difano = data2.ano-data1.ano;
    	if(difano == 0){
    	    difmes = data2.mes-data1.mes;
    	    if(difmes == 0){
    	    	difdia = data2.dia - data1.dia;
    	    	dias = difdia;
    	    }
    	    else{
    	    	dias = data2.dia;
    	    	difdia = NumeroDiasMes(data1) - data1.dia;
    	    	dias += difdia;
    	    	for(i=data1.mes+1; i<data2.mes; i++){
    	    	    conta = CriaData(20, i, data1.ano);
    	    	    dias += NumeroDiasMes(conta);
    	    	}
    	    }
    	}
    	else{
    	    for(j=data1.ano; j<data2.ano; j++){
    	    	for(i=1; i<=12; i++){
    	    	    conta = CriaData(20, i, j);
    	    	    dias += NumeroDiasMes(conta);
    	    	}
    	    }
    	    difdia = CalculaDiasAteMes(data2);
    	    dias += difdia;
    	    dias += data2.dia;
    	    difdia = CalculaDiasAteMes(data1);
    	    dias -= difdia;
    	    dias -= data1.dia;
    	}
    }
    return dias;
}
