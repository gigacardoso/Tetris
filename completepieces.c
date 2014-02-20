#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define COLUMNS 10

/**************************************/
/*				Funções		          */
/**************************************/

/*piece2id a piece5id - verificam se são encontradas peças inteiras de cada tipo
excepto a do tipo 1(pois essa ta sempre completa)*/

int piece2id(link currentNode,int id){
	if( currentNode->side->id==id &&
			currentNode->next->id==id &&
			currentNode->side->next->id==id)
		return 1;
	else
		return 0;
}

int piece3id(link currentNode,int id){
	if( currentNode->side->id==id &&
			currentNode->side->next->id==id &&
			currentNode->side->next->side->id==id)
		return 1;
	else
		return 0;
}

int piece4id(link currentNode,int id){
	if( currentNode->side->id==id &&
			currentNode->side->side->id==id &&
			currentNode->side->next->id==id)
		return 1;
	else
		return 0;
}

int piece5id(link currentNode,int id){
	if( currentNode->side->id==id &&
			currentNode->side->side->id==id &&
			currentNode->next->id==id)
		return 1;
	else
		return 0;
}

/* completePieces - devolve o número de peças completas e insere a sua descrição
numa tabela de hashing*/

int completePieces(masterline master){
	int id,n=0,i;
	link currentLine,currentNode;		
	for(currentLine=master[0];currentLine!=NULL;currentLine=currentLine->next){
		for(currentNode=currentLine,i=0;i<(COLUMNS-1);++i,currentNode=currentNode->side){
			switch(decoderF(currentNode->value)){
				case(1):
					insertInt(currentNode->value);
					currentNode->side->value=decoderM(currentNode->side->value);
					currentNode->side->side->value=decoderM(currentNode->side->side->value);
					currentNode->side->side->side->value=decoderM(currentNode->side->side->side->value);
					++n;
					break;
				case(2):
					id=currentNode->id;
					if(currentNode->next==NULL)
						break;
					if(piece2id(currentNode,id)){
						insertInt(currentNode->value);
						currentNode->side->value=decoderM(currentNode->side->value);
						currentNode->next->value=decoderM(currentNode->next->value);
						currentNode->next->side->value=decoderM(currentNode->next->side->value);
						++n;
					}
					break;
				case(3):
					id=currentNode->id;
					if(currentNode->next==NULL || currentNode->side->side==NULL)
						break;
					if(piece3id(currentNode,id)){
						insertInt(currentNode->value);
						currentNode->side->value=decoderM(currentNode->side->value);
						currentNode->next->side->value=decoderM(currentNode->next->side->value);
						currentNode->next->side->side->value=decoderM(currentNode->next->side->side->value);
						++n;
						}
					break;
				case(4):
					id=currentNode->id;
					if(currentNode->next==NULL || currentNode->side->side==NULL)
						break;
					if(piece4id(currentNode,id)){
						insertInt(currentNode->value);
						currentNode->side->value=decoderM(currentNode->side->value);
						currentNode->side->side->value=decoderM(currentNode->side->side->value);
						currentNode->next->side->value=decoderM(currentNode->next->side->value);
						++n;
					}
					break;
				case(5):
					id=currentNode->id;
					if(currentNode->next==NULL ||	currentNode->side->side==NULL)
						break;
					if(piece5id(currentNode,id)){
						insertInt(currentNode->value);
						currentNode->side->value=decoderM(currentNode->side->value);
						currentNode->side->side->value=decoderM(currentNode->side->side->value);
						currentNode->next->value=decoderM(currentNode->next->value);
						++n;
					}
					break;
				default:
					break;
			}
		}
	}
	return n;
}

/*insertInt - insere a descrição da peça na tabela de hashing, caso esta já
exista incrementa o contador*/

void insertInt(int key){
	Item item;
    item=searchHash(key);
	if(item==NULL){
   		item=malloc(sizeof(struct tabh));
  		item->code=key;
   		item->count=0;
   		insertItem(item);
   	}
   	(item->count)++;
}
