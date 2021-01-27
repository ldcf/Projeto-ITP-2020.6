#ifndef FRAME__H
#define FRAME__H

// Criação da estrutura que vai guardar os valores de cada frame calculado.
typedef struct Struct_Frame{
	double S; 		// <- pessoas suscetiveis
	double I; 		// <- numero de infectados
	double R;		// <- numero de removidos
	double mortes; 	// <- numero de mortes
}Frame;

void printTerminal(Frame P_f[], int passos, double h);
void printCSV(Frame P_f[], int passos, double h, char *path);
#endif