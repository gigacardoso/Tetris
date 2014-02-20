#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define COLUMNS 10

/**************************************/
/*				Funções		          */
/**************************************/

/*search - verifica se em alguma das posiçoes de um vector existe o inteiro test
		   e devolve 1 se sim ou 0 se nao*/

int search(int *v,int size,int test){
	int i,r=0;
	for(i=0;i<size;++i){
		if(v[i]==test)
			r=1;
		}
	return r;
}

/*sum - devolve a soma de todos os elementos de um vector com size posiçoes*/

int sum(int *v,int size){
	int i,sum=0;
	for(i=0;i<size;++i)
		sum+=v[i];
	return sum;
}

/*test - recebe um link e verifica qual o char presente, guarda em *v o numero
		 de vezes que encontrou, numa posiçao especifica.
		 
		 char	posição
		 B		0
		 G		1
		 O		2
		 R		3
		 V		4
		 Y		5			
		 
		 SÓ FUNCIONA COM OS CHARS DO PROJECTO*/

void test(link l,int *v){
  switch(decoderM(l->value)){
    case('B'):{
      ++v[0];
      break;
    }
    case('G'):{
      ++v[1];
      break;
    }
    case('O'):{
      ++v[2];
      break;
    }
    case('R'):{
      ++v[3];
      break;
    }
    case('V'):{
      ++v[4];
      break;
    }
    case('Y'):{
      ++v[5];
      break;
    }
  }
}

/*scanLine - verifica se as linhas limit e a linha acima(caso F diferente de 1) estão completas, se 
			 estiverem apaga-as, incrementa os pontos e chama a função para guardar a(s)
			 linha(s)
			 
linha b = linha onde esta o canto superior esquerdo da peça (nao e usado se a peça for tipo 1)
linha a = linha inferior onde esta colocada a peça

			chama a função updateGame, com os valores de a e b:
			
			2 se linha monocolor
			1 se linha multicolor
			0 se linha nao esta completa*/

void scanLine(link limit,int F,masterline master,int *points){
	link auxa, auxb;
	int i,a=0,b=0,vauxa[6],vauxb[6];
	for(i=0;i<6;i++){
		vauxa[i]=0;
		vauxb[i]=0;
	}
	auxa=limit;
	if(F!=1){
	auxb=limit->prev;
	for(;auxb!=NULL;auxb=auxb->side)
		test(auxb, vauxb);
	}
	for(;auxa!=NULL;auxa=auxa->side)
			test(auxa,vauxa);
	if(sum(vauxa,6)==10){
		if(search(vauxa,6,10))
			a=2;
		else
			a=1;
	}
	if(sum(vauxb,6)==10){
		if(search(vauxb,6,10))
			b=2;
		else
			b=1;
	}
	if(a!=0 || b!=0){
		updateGame(limit,a,b,F,master,points);
	}
}

/*updateGame - faz a eliminaçao das linhas e o incremento dos pontos, consoante o esquema de linhas	completas que existem.
			   recebe a linha A da funçao anterior, e consoante o valor de a e b faz o necessário*/

void updateGame(link limit,int a,int b,int F,masterline master,int *points){
	switch(a){
		case(0):if(b==1){
					(*points)+=1;
					saveLines(limit->prev,1);
					delLine(limit->prev,master,1);
				}
				else{ 
					if(b==2){
						(*points)+=3;
						if(limit->prev==NULL){
							saveLines(limit->prev,2);
							delLine(limit->prev,master,2);
						}
						else{
							saveLines(limit->prev->prev,3);
							delLine(limit->prev->prev,master,3);
						}
					}
				}
				break;
		case(1):if(b==1){
					(*points)+=2;
					saveLines(limit->prev,2);
					delLine(limit->prev,master,2);
				}           
				else{
					if(b==2){
						(*points)+=4;
						if(limit->prev->prev==NULL){
							saveLines(limit->prev,2);
							delLine(limit->prev,master,2);
						}
						else{
							saveLines(limit->prev->prev,3);
							delLine(limit->prev->prev,master,3);
						}
					}
					else{
						(*points)+=1;
						saveLines(limit,1);
						delLine(limit,master,1);
					}
				}
				break;
		case(2):if(b==1){
					(*points)+=4;
					if(limit->next==NULL){
						saveLines(limit->prev,2);
						delLine(limit->prev,master,2);
					}
					else{
						saveLines(limit->prev,3);
						delLine(limit->prev,master,3);
					 }
				}
				else{
					if(b==2){
						(*points)+=6;
						if(limit->next==NULL && limit->prev->prev!=NULL){
							saveLines(limit->prev->prev,3);
							delLine(limit->prev->prev,master,3);
						}
						else{
							if(limit->next==NULL && limit->prev->prev==NULL){
								saveLines(limit->prev,2);
								delLine(limit->prev,master,2);
							}
							else{
								if(limit->next!=NULL && limit->prev->prev==NULL){
									saveLines(limit->prev,3);
									delLine(limit->prev,master,3);
								}
								else{
									saveLines(limit->prev->prev,4);
									delLine(limit->prev->prev,master,4);
								}
							}
						}
					}
					else{
						(*points)+=3;
						if(limit->next==NULL && limit->prev!=NULL){
							saveLines(limit->prev,2);
							delLine(limit->prev,master,2);
						}
						else{
							if(limit->next==NULL && limit->prev==NULL){
								saveLines(limit, 1);
								delLine(limit, master, 1);
							}
							else{
								if(limit->next!=NULL && limit->prev==NULL){
									saveLines(limit,2);
									delLine(limit,master,2);
								}
								else{
									saveLines(limit->prev,3);
									delLine(limit->prev,master,3);
								}
							}
						}
					}
				}
				break;
		default:break;
	}
}
