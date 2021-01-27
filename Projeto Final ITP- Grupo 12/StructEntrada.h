#ifndef STRUCT_ENTRADA__H
#define STRUCT_ENTRADA__H

// Criação da estrutura responsavel por receber os dados do texto
typedef struct variaveis_da_entrada{
	double tempoT;  // <- tempo da simulaçao em dias
	double S_0; 	// <- numero de pessoas ainda não contaminadas no tempo zero
	double I_0; 	// <- numero de pessoas infectadas no tempo zero
	double R_0; 	// <- numero de pessoas removidas (recuperadas, imunes ou faleceram) no tempo zero
	double N_b; 	// <- pessoas que podem se infectar no tempo T_b
	double T_b;	
	double S_b0;	// <- pessoas no inicio da observação
	double I_b0;	// <- pessoas infectadas no inicio da observação
	double m_k; 	// <- pessoas recuperadas no tempo T_k
	double n_k; 	// <- total de pessoas estudadas no tempo t_k
	double T_k;
	double h; 		// <- intervalo de tempo da simulaçao em horas
	double nt_b;	// <- novo valor de b
	double nt_k;	// <- novo valor de k
	double tempoN; 	// <- tempo que encontra a infecção
}StructEntrada;

// Funçao pra ler o arquivo e criar uma struct e armazenar os dados do arquivo na struct
StructEntrada leitura_atribuicao();

#endif