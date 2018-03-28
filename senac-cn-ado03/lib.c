#include "lib.h"
#define MAX 100000000000000000000.0

void euler(){
    long double counter=10.0;
    long double primeiroDaOrdem = counter;
    long int incremento = 1000;
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
        printf("Index %Lf  Float: %f Double: %lf Long Double: %Lf \n",counter,temp1,temp2,temp3);
        if(counter == primeiroDaOrdem*10){
            primeiroDaOrdem *= 10000;
            incremento *= 10000;
        }
        counter += incremento;
    }
}