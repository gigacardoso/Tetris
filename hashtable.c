#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define COLUMNS 10
#define M 30

#define key(a) ((a)->code)
#define eq(a,b) ((a)==(b))

/**************************************/
/*			Variaveis Globais     	  */
/**************************************/
  
static hashlink* heads;

/**************************************/
/*				Funções		          */
/**************************************/

/*createHash - Cria a Tabela de Hashing*/

void createHash(){
	hashlink *px;
	heads=(hashlink*) malloc(M*sizeof(hashlink));
	for(px=heads;px<heads+M;px++)
  	*px = NULL;
}

/*createItem - Cria um Novo Item*/

hashlink createItem(Item item){
	hashlink x=(hashlink) malloc(sizeof(struct hashnode));
	x->item=item;
 	x->next=NULL;
	return x;
}

/*insertItem - Insere o Item na tabela de acordo com a função hash*/

void insertItem(Item item){
	int position=hash(key(item));
	hashlink x=createItem(item);
	x->next=heads[position]; 
	heads[position]=x;
}

/*searchHash - Procura se existe na tabela Item, se sim devolve-o, se nao 
devolve NULL */

Item searchHash(Key k){
	hashlink x;
	int position=hash(k);
	for(x=heads[position];x!=NULL && !eq(key(x->item),k);
		x=x->next);
	if(x!=NULL)
  	return x->item;
	else
  	return NULL;
}

/*scanHash - Percorre a Tabela de hashing aplicando a funçao visit a todos os 
Items*/

void scanHash(void(*visit)(Item)){
	unsigned int i;
	hashlink x;
	for(i=0;i<M;i++)
  	for(x=heads[i];x!=NULL;x=x->next)
    	(*visit)(x->item);
}

/*clearHash - Limpa a tabela de Hashing*/

void clearHash(){
	unsigned int i;
	hashlink x;
	for(i=0;i<M;i++)
  	while((x=heads[i])!=NULL) {
    	heads[i]=x->next;
      free(x);
  	}
	free(heads);
	heads=NULL;
}

/*printHash - Imprime o Item que recebe o numero de vezes que estiver em count*/

void printHash(Item item){
	for(;item->count>0;(item->count)--){
  	printf("%d %c\n", decoderF(item->code), decoderM(item->code));
	}
}

/*hash - Recebe uma Key e devolve a sua posiçao na hash table, vai colocar a 
key na tabela por ordem*/

int hash(int k){
    int n;
    switch(k){
    	case(166):	n=0;
    				break;
    	case(171):	n=1;
    				break;
    	case(179):	n=2;
    				break;
    	case(182):	n=3;
    				break;
    	case(186):	n=4;
    				break;
    	case(189):	n=5;
    				break;
    	case(266):	n=6;
    				break;
    	case(271):	n=7;
    				break;
    	case(279):	n=8;
    				break;
    	case(282):	n=9;
    				break;
    	case(286):	n=10;
    				break;
    	case(289):	n=11;
    				break;
    	case(366):	n=12;
    				break;
    	case(371):	n=13;
    				break;
    	case(379):	n=14;
    				break;
    	case(382):	n=15;
    				break;
    	case(386):	n=16;
    				break;
    	case(389):	n=17;
    				break;
    	case(466):	n=18;
    				break;
    	case(471):	n=19;
    				break;
    	case(479):	n=20;
    				break;
    	case(482):	n=21;
    				break;
    	case(486):	n=22;
    				break;
    	case(489):	n=23;
    				break;
    	case(566):	n=24;
    				break;
    	case(571):	n=25;
    				break;
    	case(579):	n=26;
    				break;
    	case(582):	n=27;
    				break;
    	case(586):	n=28;
    				break;
    	case(589):	n=29;
    				break;
    }
    return n;
}
