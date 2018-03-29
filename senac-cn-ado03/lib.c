#define _POSIX_C_SOURCE 2
#include "lib.h"
#define MAX 100000000000000000000.0

void euler(){

    FILE * data = fopen("output.dat","w");
    FILE * gnuplot = popen("gnuplot -persistent","w");
    long double counter=1.0;
    long double controleDeEscala=counter*10.0;
    long double incremento = 1.0;
    //float
    float temp1;
    //double
    double temp2;
    //long double
    long double temp3;
    //Lista_Float *lista = malloc(sizeof(Lista_Float));
     fprintf(data,"Index\tFloat\tDouble\tLong Double:\t\n");
    while(counter <= MAX){
        temp1 = pow(1.0+(1.0/counter),counter);
        temp2 = pow(1.0+(1.0/counter),counter);
        temp3 = pow(1.0+(1.0/counter),counter);
        fprintf(data,"%Lf\t%f\t%lf\t%Lf\n",counter,temp1,temp2,temp3);
        printf("%Lf\t%f\t%lf\t%Lf\n",counter,temp1,temp2,temp3);
        if(counter == controleDeEscala){
            incremento *= 10;
            controleDeEscala *=10;
        }
        counter += incremento;
    }

    fclose(data);

    fprintf(gnuplot,"set terminal png\n");
    fprintf(gnuplot,"set logscale xy\n");
    fprintf(gnuplot,"set title 'Alex Shun Yamazaki - Numero de Euler gerado com uso de float'\n");
    fprintf(gnuplot,"set output 'euler_flt.png'\n");
    fprintf(gnuplot,"plot 'output.dat' using 1:2\n");

    fprintf(gnuplot,"set terminal png\n");
    fprintf(gnuplot,"set logscale xy\n");
    fprintf(gnuplot,"set title 'Alex Shun Yamazaki - Numero de Euler gerado com uso de double'\n");
    fprintf(gnuplot,"set output 'euler_dbl.png'\n");
    fprintf(gnuplot,"plot 'output.dat' using 1:3\n");

    fprintf(gnuplot,"set terminal png\n");
    fprintf(gnuplot,"set logscale xy\n");
    fprintf(gnuplot,"set title 'Alex Shun Yamazaki - Numero de Euler gerado com uso de long double'\n");
    fprintf(gnuplot,"set output 'euler_ldbl.png'\n");
    fprintf(gnuplot,"plot 'output.dat' using 1:4\n");

    
    fflush(gnuplot);
    fprintf(gnuplot,"exit\n");
    pclose(gnuplot);
    remove("output.dat");
}