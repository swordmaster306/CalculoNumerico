#define _POSIX_C_SOURCE 2
#include "lib.h"
#define MAX 100000000000000000000.0

void euler(){

    FILE * data = fopen("output.data","w");
    FILE * gnuplot = fopen("gnuplot -persistent","w");
    long double counter=10.0;
    long double primeiroDaOrdem = counter;
    long int incremento = 100;
    //float
    float temp1;
    //double
    double temp2;
    //long double
    long double temp3;
    //Lista_Float *lista = malloc(sizeof(Lista_Float));
    while(counter <= MAX){
        temp1 = pow(1+(1/counter),counter);
        temp2 = pow(1+(1/counter),counter);
        temp3 = pow(1+(1/counter),counter);
        fprintf(data,"Index %Lf  Float: %f Double: %lf Long Double: %Lf \n",counter,temp1,temp2,temp3);
        if(counter == primeiroDaOrdem*10){
            primeiroDaOrdem *= 100;
            incremento *= 100;
        }
        counter += incremento;
    }

    fclose(data);
}