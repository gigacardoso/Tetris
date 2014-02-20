/* FUNÇÕES SOBRE ESTRUTURAS */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define COLUMNS 10

/**************************************/
/*				Funções		          */
/**************************************/

/*insertNode - insere um node no início de uma lista */

link insertNode(link head,char v){
  link newhead=malloc(sizeof(node));
  newhead->value=v;
  newhead->id=0;
  newhead->prev=NULL;
  newhead->next=head;
  newhead->side=NULL;
  return newhead;
}

/*createLine - cria uma linha, criando 10 nodes em 10 colunas*/

void createLine(masterline master){
  int i;
  for(i=(COLUMNS-1);i>=0;--i){
    master[i]=insertNode(master[i],' ');
    if(i+1==COLUMNS)
    	master[i]->side=NULL;
    else
    	master[i]->side=master[i+1];
    if(master[i]->next!=NULL)
    	master[i]->next->prev=master[i];
  }
}

/*delLine - apaga a linha link e as n-1 linhas abaixo*/

void delLine(link line,masterline master,int n){
	int first,middle,last,only, i;
	link previous,next;
	first=middle=last=only=i=0;
	previous=line->prev;
	for(next=line;n>0;--n)
		next=next->next;
	if(previous==NULL && next==NULL)
		only=1;
	else{
		if(previous==NULL && next!=NULL)
			first=1;
		else{
			if(previous!=NULL && next==NULL)
				last=1;
			else
				middle=1;
		}
	}
	if(middle){
		for(;previous!=NULL;previous=previous->side,next=next->side){
			previous->next=next;
			next->prev=previous;
			clear(line, n);
		}
	}
	if(first){
		for(;i<COLUMNS;++i,next=next->side){
			master[i]=next;
			next->prev=NULL;
			clear(line, n);
		}
	}
	if(last){
		for(;i<COLUMNS;++i,previous=previous->side){
			previous->next=NULL;
			clear(line, n);
		}
	}
	if(only){
		for(;i<COLUMNS;++i){
			master[i]=NULL;
			clear(line, n);
		}
	}
}

/*clear - liberta a memória das n linhas a contar da linha line(para baixo) que recebe*/

void clear(link line,int n){
	link auxa, auxb;
	for(;n>0;--n){
		auxa=line;
		if(n>1)
			line=line->next;
		while(auxa!=NULL){
			auxb=auxa;
			auxa=auxa->side;
			free(auxb);
		}
	}
}
