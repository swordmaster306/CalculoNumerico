#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


int main(int argc, char *argv[]){

    unsigned long long int numero;
    bool *resposta;
    int base_entrada;
    int base_saida;
    bool negativo = false;

    if(argc < 4){
        //printf("Voce nao forneceu argumentos suficientes!\n");
        return 1;
    }else if(argc > 4){
        //printf("Voce forneceu argumentos a mais!\n");
        return 1;
    }else{
        resposta = validarEntrada(argv[1],argv[2],argv[3]);
        if(resposta[0] == true){
            //printf("Bases validas\n");
            base_entrada = atoi(argv[2]);
            base_saida = atoi(argv[3]);
            if(argv[1][0] == 45){
                negativo = true;
            }
            numero = converterParaBase10(argv[1], base_entrada);
            if(numero  > 4294967295){
                return 1;
            }
            converterParaBaseM(numero, base_saida,negativo);
        }else{
            //printf("Voce forneceu argumentos invalido(s)!\n");
            return 1;
        }
    }
    return 0;
}