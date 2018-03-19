#ifndef LIB_H_
#define LIB_H_


typedef struct elementoDePilha{
    char digito;
    struct elementoDePilha *prox;
}Celula;

typedef enum { true, false } bool;

int potencia(int n, int potencia);


bool pilhaVazia(Celula * pilha);

void inserirNaPilha(Celula **pilha, char c);

void printPilha(Celula *pilha,bool negativo);


bool *  validarEntrada(char numero[],char base_entrada[], char base_saida[]);

int converterParaBase10(char numero[],int base_entrada);

void converterParaBaseM(int numero, int base_saida);


#endif // LIB_H_