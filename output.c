#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define COLUMNS

/**************************************/
/*				Funções		          */
/**************************************/

/*lMax - devolve o número de linhas existentes no espaço de jogo*/

int lMax(masterline master){
	int lmax=0;
	link actual=master[0];
	while(actual!=NULL){
		++lmax;
		actual=actual->next;
	}
	return lmax;
}

/*print - imprime toda a tabela com o número da linha do lado direito*/

void print(int lmax,masterline master){
	int i;
	link currentNode;
	for(i=0;i<lmax;++i){
		printf("|");
		currentNode=master[0];
		for(;currentNode!=NULL;currentNode=currentNode->side)
			printf("%c",decoderM(currentNode->value));
		printf("| %d\n",lmax-i);
		delLine(master[0],master,1);
	}			
	printf(" ----------\n");
}

/*output - devolve o output desejado chamando as funçoes necessarias
		   (número de linhas, pontos, tabela, peças completas e linha mediana eliminada)*/

void output(masterline master,int *points){
	int lmax, n;
	lmax=lMax(master);
	createHash();
	n=completePieces(master);
	printf("%d\n%d\n\n",lmax,*points);
	print(lmax,master);
	printf("\n%d\n",n);
	scanHash(printHash);
  clearHash();
	printf("\n");
	printLines();
	deleteLines();
}
