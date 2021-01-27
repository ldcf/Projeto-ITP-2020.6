#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "StructEntrada.h"


// Funçao pra ler o arquivo e criar uma struct e armazenar os dados do arquivo na struct
StructEntrada leitura_atribuicao(){

	FILE *file;
    file = fopen("teste.txt","r");
    if (file == NULL){
        exit(1);
    }

    // Criaçao da struct
	StructEntrada entradas; 
    // Leitura e atribuiçao na struct
    fscanf(file, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &entradas.tempoT, &entradas.S_0, &entradas.I_0, &entradas.R_0, &entradas.N_b, &entradas.T_b, &entradas.S_b0, &entradas.I_b0, &entradas.m_k, &entradas.n_k, &entradas.T_k, &entradas.h,&entradas.nt_b,&entradas.nt_k,&entradas.tempoN);

    fclose(file);
    return entradas;
}