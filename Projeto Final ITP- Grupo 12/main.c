#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Frame.h"
#include "StructEntrada.h"



// Função para calcular cada instante de S, R e I em função do tempo para os cenarios 0, 1 e 2;
void calcularFrames(StructEntrada entrada,int passos, Frame f[]){
	double k,b,nb,nk,novosremovidos = 0;
	double t = 0;

	f[0].S = entrada.S_0;
	f[0].R = entrada.R_0;
	f[0].I = entrada.I_0;
	f[0].mortes = 0;
	k = (entrada.m_k/(entrada.n_k*entrada.T_k));
	b = (entrada.N_b/(entrada.T_b*entrada.S_b0*entrada.I_b0));

	for(int i=1; i<=passos;i++){
		f[i].S = f[i-1].S - (entrada.h*b*f[i-1].S*f[i-1].I);
		f[i].I = f[i-1].I +(entrada.h*(b*f[i-1].S*f[i-1].I-(k*f[i-1].I)));
		f[i].R = f[i-1].R + (entrada.h*k*f[i-1].I);
		novosremovidos = f[i].R - f[i-1].R;
		f[i].mortes =  f[i-1].mortes + (0.02 * novosremovidos);
		t = t + entrada.h;
	}

	printCSV(f,passos,entrada.h,"cenario0.csv");
	printTerminal(f,passos,entrada.h);

	f[0].S = entrada.S_0;
	f[0].R = entrada.R_0;
	f[0].I = entrada.I_0;
	f[0].mortes = 0;

	k = (entrada.m_k/(entrada.n_k*entrada.T_k));
	b = (entrada.N_b/(entrada.T_b*entrada.S_b0*entrada.I_b0));
	nb = (entrada.N_b/(entrada.nt_b*entrada.S_b0*entrada.I_b0));
	
	for(int i=1; i<=passos;i++){
		t = t + entrada.h;
		
		if(t < entrada.tempoN){

			f[i].S = f[i-1].S - (entrada.h*b*f[i-1].S*f[i-1].I);
			f[i].I = f[i-1].I +(entrada.h*(b*f[i-1].S*f[i-1].I-(k*f[i-1].I)));
			f[i].R = f[i-1].R + (entrada.h*k*f[i-1].I); 
			novosremovidos = f[i].R - f[i-1].R;
			f[i].mortes =  f[i-1].mortes + (0.02 * novosremovidos);
		}

		if (t > entrada.tempoN){

			//inserir aqui um modificador de b, para aumentar T_b
			f[i].S = f[i-1].S - (entrada.h*nb*f[i-1].S*f[i-1].I);
			f[i].I = f[i-1].I +(entrada.h*(nb*f[i-1].S*f[i-1].I-(k*f[i-1].I)));
			f[i].R = f[i-1].R + (entrada.h*k*f[i-1].I);
			novosremovidos = f[i].R - f[i-1].R;
			f[i].mortes =  f[i-1].mortes + (0.02 * novosremovidos);
		}
	}

	printCSV(f,passos,entrada.h,"cenario1.csv");
	printTerminal(f,passos,t);

	f[0].S = entrada.S_0;
	f[0].R = entrada.R_0;
	f[0].I = entrada.I_0;
	f[0].mortes = 0;

	k = (entrada.m_k/(entrada.n_k*entrada.T_k));
	b = (entrada.N_b/(entrada.T_b*entrada.S_b0*entrada.I_b0));
	nk = (entrada.m_k/(entrada.n_k*entrada.nt_k));

	for(int i=1; i<=passos;i++){
		t = t + entrada.h;
		
		if(t < entrada.tempoN){

			f[i].S = f[i-1].S - (entrada.h*b*f[i-1].S*f[i-1].I);
			f[i].I = f[i-1].I +(entrada.h*(b*f[i-1].S*f[i-1].I-(k*f[i-1].I)));
			f[i].R = f[i-1].R + (entrada.h*k*f[i-1].I);
			novosremovidos = f[i].R - f[i-1].R;
			f[i].mortes =  f[i-1].mortes + (0.02 * novosremovidos);    	
		}

		if (t > entrada.tempoN){

			//inserir aqui um modificador de b, para diminuir T_k
			f[i].S = f[i-1].S - (entrada.h*b*f[i-1].S*f[i-1].I);
			f[i].I = f[i-1].I +(entrada.h*(b*f[i-1].S*f[i-1].I-(nk*f[i-1].I)));
			f[i].R = f[i-1].R + (entrada.h*nk*f[i-1].I);
			novosremovidos = f[i].R - f[i-1].R;
			f[i].mortes =  f[i-1].mortes + (0.02 * novosremovidos);
	
		}
	}
	printCSV(f,passos,entrada.h,"cenario2.csv");
	printTerminal(f,passos,entrada.h);
}


int main(void) {

	StructEntrada entrada_main = leitura_atribuicao();       	//criaçao da struct na main e a leitura e atribuiçao

	int passos = (entrada_main.tempoT*24)/entrada_main.h;       //calcular -->"passos" ( que são os numeros de instantes para calcular )

	Frame* frames = calloc(passos+1, sizeof(Frame));            //alocaçao dinamica da struct frame q contem todos os S I R

  calcularFrames(entrada_main, passos, frames);          		// função que recebe a struct com as entradas e calcula cada frame em função do tempo.
   
  return 0;
}


