/* **************************************************************** */
/*   3º PROJECTO de Introdução a Algoritmos e Estruturas de Dados   */
/*                                                                  */
/* Grupo 95:   Daniel Cardoso     -  66964                          */
/*             Francisco Raposo   -  66986                          */
/*             Mario Cotrim       -  67035                          */
/*                                                                  */
/* Curso:      LEIC-A, Campus Alameda                               */
/* **************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define COLUMNS 10

int main(){
	link master[COLUMNS];	/*master -	vector com 10 posiçoes em que cada uma corresponde ao elemento*/
	int i,N,F,C;			/*			que se encontra no top de uma coluna, master[0] = 1ª coluna,  */ 
	char M;					/*			master[1] = 2ªcolunas e assim sucessivamente.				  */
	int points[1]= {0};
  
	for(i=0;i<COLUMNS;i++){
		master[i]=NULL;
	}
	initLine();
	scanf("%d\n",&N);
	while(N>0){
		scanf("%d %d %c\n",&F,&C,&M);
		writePiece(F,C,M,master,points,N);
		--N;
	}
	output(master,points);
	return 0;
}
