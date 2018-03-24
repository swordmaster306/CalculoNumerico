#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


        unsigned long long  potencia(int n, int potencia){

            unsigned long long resultado = 1;

            for(int i = 0 ; i < potencia ; i++){
                resultado *=n;
            }

            return resultado;
        }


        bool pilhaVazia(Celula * pilha){
            if(pilha == NULL){
                return true;
            }else{
                return false;
            }
        }

        void inserirNaPilha(Celula **pilha, char c){
            Celula *novo;
            if(pilhaVazia(*pilha) == true){
                novo = malloc(sizeof(Celula));
                *pilha = novo;
                novo->digito = c;
                novo->prox = NULL;
            }else{
                novo = malloc(sizeof(Celula));
        novo->digito = c;
        novo->prox = *pilha;
        *pilha = novo;
    }
}

void printPilha(Celula *pilha,bool negativo){
    bool diferente_zero = false;
    if(negativo == true){
        printf("-");
    }
    while(pilha != NULL){
        if(pilha->digito == '0' && diferente_zero ==false){
            pilha = pilha->prox;
            continue;
        }else{
            diferente_zero = true;
        }
        printf("%c",pilha->digito);
        pilha = pilha->prox;
    }
    printf("\n");
}



bool *  validarEntrada(char numero[],char base_entrada[], char base_saida[]){

    bool *resposta = malloc(sizeof(bool)*2);
    resposta[0] = false;
    resposta[1] = false;
    bool numero_tem_letra = false;
    int num_maior_maiusculo = 0;
    int num_maior_minusculo = 0;
    int index_alfabeto;

    int len_numero = strlen(numero);
    for(int i = 0 ; i < len_numero; i++){
        int temp = (int) numero[i];

        if(i == 0){
            if (!(temp == 45 || (temp>=48 && temp<=57) || (temp>=65 && temp<=90) || (temp>=97 && temp<=122))){
                //printf("Numero invalido!\n");
                return resposta;
            }
        }else{
            if (!((temp>=48 && temp<=57) || (temp>=65 && temp<=90) || (temp>=97 && temp<=122))){
                //printf("Numero invalido!\n");
                return resposta;
            }
        }

        if((temp>=65 && temp<=90) || (temp>=97 && temp<=122)){
            numero_tem_letra = true;
            resposta[1] = true;
        }
        if(temp>=65 && temp<=90){
            if(temp > num_maior_maiusculo)
                num_maior_maiusculo = temp;
        }
        else if(temp>=97 && temp<=122){
            if(temp > num_maior_minusculo)
                num_maior_minusculo = temp;
        }
    }

    if(numero_tem_letra == true) {
        num_maior_minusculo -= 32;
        if (num_maior_minusculo > num_maior_maiusculo) {
            num_maior_maiusculo = num_maior_minusculo;
        }
        index_alfabeto = num_maior_maiusculo - 64;
    }

    int len_bEntrada = strlen(base_entrada);
    for(int i = 0 ; i < len_bEntrada; i++){
        int temp = (int) base_entrada[i];
        if (!((temp>=48 && temp<=57) )){
            //printf("Base entrada invalida!\n");
            return resposta;
        }
    }
    int base_entrada_convertida = atoi(base_entrada);
    if(base_entrada_convertida<2 || base_entrada_convertida>36){
        //printf("Base de entrada fora do intervalo 0<BASE<37\n");
        return resposta;
    }


    int len_bSaida = strlen(base_saida);
    for(int i = 0 ; i < len_bSaida ; i++){
        int temp = (int) base_saida[i];
        if (!((temp>=48 && temp<=57))){
            //printf("Base saida invalida!\n");
            return resposta;
        }
    }
    int base_saida_convertida = atoi(base_saida);
    if(base_saida_convertida<2 || base_saida_convertida>36){
        //printf("Base de saida fora do intervalo 0<BASE<37\n");
        return resposta;
    }

    if(numero_tem_letra == true){
        if(!(index_alfabeto <= (atoi(base_entrada)-10))){
            //printf("(Acima de 10) Numero e base de entrada incompativeis!\n");
            return resposta;
        }
    }else{
        int tamanho_numero = strlen(numero);
        int temp;
        int base = atoi(base_entrada);
        for(int i = 0 ; i < tamanho_numero ; i++){
            temp = numero[i] -48;
            if(temp >= base){
                //printf("(Abaixo ou igual a 10) Numero e base de entrada incompativeis!\n");
                return resposta;
            }
        }
    }
    resposta[0] = true;
    return resposta;
}


int verificarNumero(char c){
    if(c >= '0' && c <= '9'){
        return (int)c - '0';
    }else{
        if(c >=97 && c <= 122) {
            c -= 32; //deixa maiusculo, caso seja minusculo;
        }
        return (int)c - 'A' +10;
    }
}


unsigned long long converterParaBase10(char numero[],int base_entrada){
    unsigned long long numero_convertido = 0;
    int expoente;
    int tamanho_string = strlen(numero);

    if(numero[0] == 45){
        expoente = tamanho_string - 2 ;
        for(int i = 1 ; i < tamanho_string ; i++){
            numero_convertido += verificarNumero(numero[i]) * potencia(base_entrada,expoente);
            expoente--;
        }
    }else{
        expoente = tamanho_string -1 ;
        for(int i = 0 ; i < tamanho_string ; i++){
            numero_convertido += verificarNumero(numero[i]) * potencia(base_entrada,expoente);
            expoente--;
        }
    }

    return numero_convertido;
}

char verificarNumero2(int n){
    if(n >= 0 && n <=9){
        return (char)n + '0';
    }else{
        return (char)(n - 10 + 'A');
    }
}


void converterParaBaseM(unsigned long long numero, int base_saida,bool negativo){
    Celula *pilha = NULL;
    int quociente, resto;
    do{
        quociente = numero/base_saida;
        resto = numero % base_saida;

        inserirNaPilha(&pilha,verificarNumero2(resto));

        numero = quociente;
        if(numero <(unsigned long)base_saida)
            inserirNaPilha(&pilha,verificarNumero2(numero));
    }
    while(base_saida <= quociente);

    printPilha(pilha,negativo);
}
