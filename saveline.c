/*FUNÇÕES SOBRE ESTRUTURA LINHA*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define COLUMNS 10

/**************************************/
/*			Variaveis Globais     	  */
/**************************************/

static deletedlines delLines=NULL;

/**************************************/
/*				Funções		          */
/**************************************/

/*initLine -- Inicia a estrutura de lista que vai conter as linhas eliminadas

/* Lista e composta por um Nodulo com o numero de linhas eliminadas( que depois serve para a media) ligado 
   a uma sequencia nodulos com as linhas eliminadas e com o count
   que diz o numero de vezes que foi eliminada um linha daquelas*/

void initLine(){
	delLines=malloc(sizeof(numblines));
	delLines->num=0;
	delLines->next=NULL;
}

/*newLine - cria um elemento da lista de linhas eliminadas e guarda la a linha string*/ 

line newLine(char string[11]){
	int i;
	line new=malloc(sizeof(struct nodeline));
	for(i=0;i<=COLUMNS;++i){
		new->line[i]=string[i];
	}
	new->count=1;
	new->next=NULL;
	return new;
}

/* formatString - formata a linha que recebe atraves da lista e coloca a na no vector destiny

formato = retira os espaços da string e termina  a string colocando o \0 no sim*/

void formatString(char destiny[11],link erased){
	int i;
	for(i=0;erased!=NULL;erased=erased->side){
		if(decoderF(erased->value) != 0){
			destiny[i]=decoderM(erased->value);
			++i;
		}
	}
	destiny[i]='\0';
}

/*saveLines - recebe um link para a linha mais acima que vai apagar, o numblines
 			  que e o numero de linhas que vai apagar. chama a funçao que guarda uma linha 
 			  o numero de vezes que for necessario, incrementa tambem o numero de linhas 
 			  eliminadas somando numblines ao existene */

void saveLines(link erased, int numblines){
	delLines->num+=numblines;	
	saveLine(erased); 
	for(;numblines>1;--numblines){
		erased=erased->next;
		saveLine(erased);
	}
}

/*saveLine - guarda a linha que recebe e insere-a na lista de linhas eliminadas 
			 ja por ordem*/

void saveLine(link erased){
	int n;
	line last,current,new;
	char string[11];
	formatString(string,erased);
	if(delLines->next==NULL){
		new=newLine(string);
		delLines->next=new;
		return;
	}
	 if(compareLines(string, delLines->next)<0){
	 	new = newLine(string);
	 	new->next=delLines->next;
	 	delLines->next= new;
	 	return;
	 }
	 else{
	 	if(compareLines(string, delLines->next)==0){
	 		(delLines->next->count)++;
	 		return;
	 	}
	 }
	 new = newLine(string);
	 for(last=delLines->next, current=delLines->next->next; last!=NULL; current=current->next, last=last->next){
		if(current==NULL){
			last->next=new;
			break;
		}
		n = compareLines(string, current);
		if(n<0){
			last->next=new;
			new->next=current;
			break;
		}
		else{
			if(n==0){
				(current->count)++;
				break;
			}
		}
	}
}

/*compareLines - verifica se a string a é menor, maior ou igual à b, usando o strcmp 
				 devolve o valor so strcmp*/

int compareLines(char *a,line b){
	int n;
	n = strcmp(a,b->line);
	return n;
}

/*printLines - recebe a lista das linhas eliminadas e imprime a linha mediana, 
			   caso nao existam linhas eliminadas imprime "no eliminations"*/

void printLines(){
	int n,counter,median;
	line topLine;
	n=delLines->num;
	if(n>0){
		topLine=delLines->next;
		if(n%2)
			median=n/2+1;
		else
			median=n/2;
		for(counter=0;median>=counter;){
			counter+=topLine->count;
			if(median>counter)
				topLine=topLine->next;
		}
		printf("%s",topLine->line);
		printf("\n");
	}
	else{
		printf("No eliminations\n");
	}
}

/* deleteLines - faz free da memoria que foi alocada para a lista de linhas eliminadas*/

void deleteLines(){
	line previous, topLine;
	if(delLines->next !=NULL){
		topLine=delLines->next;
		while(topLine!=NULL){
			previous=topLine;
			topLine=topLine->next;
			free(previous);
		}
	}
	free(delLines);
}
