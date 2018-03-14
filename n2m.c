#include <stdio.h>
#include <stdlib.h>
#include "lib.c" 

int main(int argc, char *argv[]){
    
    int numero_entrada;
    int base_entrada;
    int base_saida;

    if(argc < 3){
        printf("Voce inseriu menos do que tres argumentos");
        return 1;
    }else if(argc >4){
        printf("Voce inseriu mais do que tres argumentos");
        return 0;
    }else{
        //Atoi retorna 0 se encontra string/char, porém e se for o 0 de fato
        numero_entrada = atoi(argv[1]);
        base_entrada = atoi(argv[2]);
        base_saida = atoi(argv[3]);

        if(base_entrada > 0){
            if(base_saida > 0){
                //realiza conversao
            }
        }

        printf("%d %d %d \n",numero_entrada,base_entrada,base_saida);
    }
}