#include <stdio.h>
#include <stdlib.h>

#define M_PI 3.14159265358979323846

double grausParaRadiano(int graus){
    return (graus*M_PI)/180;
}

double cosseno(double angulo){
    double cosseno = 1;
    double temp = 1;
    int contador;
    int incremento = 2;
    int precisao = 40;

    for(contador = 1 ; contador <= precisao*incremento ; contador+=incremento){
        temp *= (-1)*angulo*angulo/(contador*(contador+1));
        cosseno += temp;
    } 

    return cosseno;
}

double seno(double angulo){
    double seno = angulo;
    double temp = 1;
    int contador;
    int incremento = 2;
    int precisao = 40;


    for(contador = 2 ; contador <= precisao*incremento ; contador+=incremento){
        if(contador ==2){
            temp *= (-1)*angulo*angulo*angulo/(contador*(contador+1));
        }else{
            temp *= (-1)*angulo*angulo/(contador*(contador+1));    
        }
        seno += temp;
    } 

    return seno;
}