#ifndef LIB_H_
#define LIB_H_
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct listaFloat{
    float elemento;
    struct listaFloat * prox;
}Lista_Float;

typedef struct listaDouble{
    float elemento;
    struct listaDouble * prox;
}Lista_Double;

typedef struct listaLongDouble{
    float elemento;
    struct listaLongDouble * prox;
}Lista_LongDouble;


void euler();

void inserirFloatPilha(Lista_Float** lista, float num);

void inserirDoublePilha(Lista_Double**, double num);

void inserirLongDoublePilha(Lista_LongDouble**,long double num);




#endif