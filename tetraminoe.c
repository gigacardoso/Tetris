#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define COLUMNS 10

/**************************************/
/*				Funções		          */
/**************************************/

/*checkSpace1 a checkSpace5 - verificam se as posições para as peças 1-5 que
							  começam em link estão livres e devolvem 1 se 
							  sim e 0 se não*/

int checkSpace1(link l){
	if( l->value==' ' && 
			l->side->value==' ' && 
			l->side->side->value==' ' && 
			l->side->side->side->value==' ')
		return 1;
	else
		return 0;
}

int checkSpace2(link l){
	if(l->value==' ' && l->side->value==' '){
			if(l->next != NULL){
				if(l->next->value==' ' && l->side->next->value==' ')
					return 1;
			}
	}
	return 0;
}

int checkSpace3(link l){
	if(l->next!=NULL){
		if(l->side->value!=' ' || l->side->side->value!=' ')
					return 0;
	}
	if(l->value==' ' && l->side->value==' '){
		if(l->next != NULL){
			if(l->side->next->value==' ' && l->side->next->side->value==' ')
				return 1;
		}
	}
	return 0;
}

int checkSpace4(link l){
	if(l->next!=NULL){
		if(l->side->value!=' ')
					return 0;
	}
	if(l->value==' ' && l->side->value==' ' && l->side->side->value==' '){
			if(l->next != NULL){
				if(l->side->next->value==' ')
					return 1;
			}
	}
	return 0;
}

int checkSpace5(link l){
	if(l->next!=NULL){
		if(l->value!=' ')
			return 0;
	}
	if(l->value==' ' && l->side->value==' ' && l->side->side->value==' '){
			if(l->next != NULL){
				if(l->next->value==' ')
					return 1;
			}
	}
	return 0;
}

/*scanSpace - verifica onde é que a peça nova a ser inserida vai ficar no jogo.
			  Devolve um link para o primeiro elemento da linha onde o canto superior esquerdo
			  da peça vai ficar*/

link scanSpace(int F,int C,masterline master){
	link firstNode=master[C-1],line;
	switch(F){
		case(1):{
			if(firstNode==NULL){
				createLine(master);
				line=master[0];
				break;
			}
			else{
				if(checkSpace1(firstNode)){	
					for(line=master[0];firstNode!=NULL && checkSpace1(firstNode);
							firstNode=firstNode->next){
						if(firstNode->next!=NULL && checkSpace1(firstNode->next))
							line=line->next;
					}
					break;
				}
				else{
					createLine(master);
					line=master[0];
					break;
				}
			}
		}
		case(2):{
			if(firstNode==NULL){
				createLine(master);
				createLine(master);
				line=master[0];
				break;
			}
			else{
				if(firstNode->next==NULL){
					createLine(master);
					firstNode=master[C-1];
					if(checkSpace2(firstNode)){
						line=master[0];
						break;
					}
					else{
						createLine(master);
						line=master[0];
						break;
					}
				}
				else{
					if(checkSpace2(firstNode)){
						for(line=master[0];firstNode!=NULL && checkSpace2(firstNode);
								firstNode=firstNode->next,line=line->next);
						line=line->prev;
						break;
					}
					else{
						createLine(master);
						firstNode=master[C-1];
						if(checkSpace2(firstNode)){
							line=master[0];
							break;
						}
						else{
							createLine(master);
							line=master[0];
							break;
						}
					}
				}
			}
		}
		case(3):{
			if(firstNode==NULL){
				createLine(master);
				createLine(master);
				line=master[0];
				break;
			}
			else{
				if(firstNode->next==NULL){
					createLine(master);
					firstNode=master[C-1];
					if(checkSpace3(firstNode)){
						line=master[0];
						break;
					}
					else{
						createLine(master);
						line=master[0];
						break;
					}
				}
				else{
					if(checkSpace3(firstNode)){
						for(line=master[0];firstNode!=NULL && checkSpace3(firstNode);
								firstNode=firstNode->next,line=line->next);
						line=line->prev;
						break;
					}
					else{
						createLine(master);
						firstNode=master[C-1];
						if(checkSpace3(firstNode)){
							line=master[0];
							break;
						}
						else{
							createLine(master);
							line=master[0];
							break;
						}
					}
				}
			}
		}
		case(4):{
			if(firstNode==NULL){
				createLine(master);
				createLine(master);
				line=master[0];
				break;
			}
			else{
				if(firstNode->next==NULL){
					createLine(master);
					firstNode=master[C-1];
					if(checkSpace4(firstNode)){
						line=master[0];
						break;
					}
					else{
						createLine(master);
						line=master[0];
						break;
					}
				}
				else{
					if(checkSpace4(firstNode)){
						for(line=master[0];firstNode!=NULL && checkSpace4(firstNode);
								firstNode=firstNode->next,line=line->next);
						line=line->prev;
						break;
					}
					else{
						createLine(master);
						firstNode=master[C-1];
						if(checkSpace4(firstNode)){
							line=master[0];
							break;
						}
						else{
							createLine(master);
							line=master[0];
							break;
						}
					}
				}
			}
		}
		case(5):{
			if(firstNode==NULL){
				createLine(master);
				createLine(master);
				line=master[0];
				break;
			}
			else{
				if(firstNode->next==NULL){
					createLine(master);
					firstNode=master[C-1];
					if(checkSpace5(firstNode)){
						line=master[0];
						break;
					}
					else{
						createLine(master);
						line=master[0];
						break;
					}
				}
				else{
					if(checkSpace5(firstNode)){
						for(line=master[0];firstNode!=NULL && checkSpace5(firstNode);
								firstNode=firstNode->next,line=line->next);
						line=line->prev;
						break;
					}
					else{
						createLine(master);
						firstNode=master[C-1];
						if(checkSpace5(firstNode)){
							line=master[0];
							break;
						}
						else{
							createLine(master);
							line=master[0];
							break;
						}
					}
				}
			}
		}
		default:break;
	}
	return line;
}

/*charToInt - recebe um char e devolve o inteiro correspondente em ASCII*/

int charToInt(char A){
	int N=65;
	while(A!=N)
		++N;	
	return N;
}

/*encoder - codifica o tipo de peça e a sua cor num só inteiro, algarismo das centenas tem o F
			e o das dezenas e unidades tema codificaçao em ASCII de M*/

int encoder(int F,char M){
	int aux,code;
	aux=charToInt(M);
	code=F*100+aux;
	return code;
}

/*decoderF - descodifica o código de forma a devolver o tipo da peça*/

int decoderF(int code){
	return code/100;
}

/*decoderM - descodifica o código de forma a devolver a cor da peça*/

int decoderM(int code){
	return code%100;
}

/*writePiece - escreve uma peça no jogo e chama o scanLine nas linhas em que a 
			   peça foi colocada.*/

void writePiece(int F,int C,char M,masterline master,int *points,int N){
	int code;
	link positionNode, line=scanSpace(F,C,master);
	code=encoder(F,M);
	for(positionNode=line;C!=1;positionNode=positionNode->side)
		--C;
	switch(F){
		case(1):{
			positionNode->value=code;
			positionNode->side->value=code;
			positionNode->side->side->value=code;
			positionNode->side->side->side->value=code;
			positionNode->id=N;
			positionNode->side->id=N;
			positionNode->side->side->id=N;
			positionNode->side->side->side->id=N;		
			break;
		}
		case(2):{
			positionNode->value=code;
			positionNode->side->value=code;
			positionNode->next->value=code;
			positionNode->side->next->value=code;
			positionNode->id=N;
			positionNode->side->id=N;
			positionNode->next->id=N;
			positionNode->next->side->id=N;
			break;
		}
		case(3):{
			positionNode->value=code;
			positionNode->side->value=code;
			positionNode->side->next->value=code;
			positionNode->side->next->side->value=code;
			positionNode->id=N;
			positionNode->side->id=N;
			positionNode->next->side->id=N;
			positionNode->next->side->side->id=N;  		
			break;
		}
		case(4):{
			positionNode->value=code;
			positionNode->side->value=code;
			positionNode->side->side->value=code;
			positionNode->side->next->value=code;
			positionNode->id=N;	
			positionNode->side->id=N;
			positionNode->side->side->id=N;
			positionNode->side->next->id=N; 		
			break;
		}
		case(5):{
			positionNode->value=code;
			positionNode->side->value=code;
			positionNode->side->side->value=code;
			positionNode->next->value=code;
			positionNode->id=N;	
			positionNode->side->id=N;
			positionNode->side->side->id=N;
			positionNode->next->id=N; 		
			break;
		}
		default:break;
	}
	if(F!=1)
		line=line->next;
	scanLine(line,F,master,points);
}

