#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include <math.h>


int main(){
    double anguloConvertido;
    double senAlex,cosAlex;
    double sen,coss;

    int grauInicial = 0;
    int grauFinal = 720;
    FILE * senoData = fopen("seno.dat","w");
    FILE * cosData = fopen("cosseno.dat","w");
    FILE * gnuPlot = popen("gnuplot -persistent","w");

    if (senoData == NULL || cosData == NULL){
        return 1;
    }

    fprintf(senoData,"Arco\tSeno(Arco)\tErro absoluto\tErro relativo\n");
    fprintf(cosData,"Arco\tCosseno(Arco)\tErro absoluto\tErro relativo\n");

    for(int i = grauInicial ; i <=grauFinal ; i++){
        anguloConvertido = grausParaRadiano(i);
        senAlex = seno(anguloConvertido);
        sen = sin(anguloConvertido);
        cosAlex = cosseno(anguloConvertido);
        coss = cos(anguloConvertido);
        fprintf(senoData,"%lf\t%lf\t%lf\t%lf\n",anguloConvertido,senAlex,sen-senAlex,(sen-senAlex)/senAlex);
        fprintf(cosData,"%lf\t%lf\t%lf\t%lf\n",anguloConvertido,cosAlex,coss-cosAlex,(coss-cosAlex)/cosAlex);
    }


    fclose(senoData);
    fclose(cosData);

    fprintf(gnuPlot,"set terminal png\n");
    fprintf(gnuPlot,"set title 'Alex Shun Yamazaki - Plot da minha versao do Seno entre 0 e 4pi'\n");
    fprintf(gnuPlot,"set output 'seno.png'\n");
    fprintf(gnuPlot,"plot 'seno.dat' using 1:2\n");

    fprintf(gnuPlot,"set terminal png\n");
    fprintf(gnuPlot,"set title 'Alex Shun Yamazaki - Plot da minha versao do Cosseno entre 0 e 4pi'\n");
    fprintf(gnuPlot,"set output 'cosseno.png'\n");
    fprintf(gnuPlot,"plot 'cosseno.dat' using 1:2\n");

    fflush(gnuPlot);
    fprintf(gnuPlot,"exit\n");
    pclose(gnuPlot);
}