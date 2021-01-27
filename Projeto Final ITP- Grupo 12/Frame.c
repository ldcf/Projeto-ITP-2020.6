#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Frame.h"

// Função que ao ser chamada, imprime os valores no terminal
void printTerminal(Frame P_f[], int passos, double h){

	for(int i=0; i<=passos;i++){
		double tempoframe = i * h;
    	printf("%lf %lf %lf %lf %lf\n", P_f[i-1].S, P_f[i-1].I, P_f[i-1].R,P_f[i-1].mortes,tempoframe);
	}

}

// Função que ao ser chamada, cria um csv e imprime os valores em colunas separadas do mesmo.
void printCSV(Frame P_f[], int passos, double h, char *path){

	FILE *file = fopen(path, "w");
    if (file == NULL){
      exit(1);
    }

	for(int i=0; i<=passos;i++){
		double tempoframe = i * h;
		fprintf (file, "%lf,%lf,%lf,%lf,%lf\n", P_f[i-1].S, P_f[i-1].I, P_f[i-1].R, P_f[i-1].mortes,tempoframe);
	}
	fclose(file);
}