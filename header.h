/*------------------------------------------*/
/*				Estruturas usadas			*/
/*------------------------------------------*/

/*Lista tabela de jogo*/

/*	Cada Nodulo contem:	

	value	- codigo com F e M
	id		- inteiro unico para cada peca
	next	- link para a posiçao que esta na mesma coluna mas na linha de baixo na tabela de jogo
	prev	- link para a posiçao que esta na mesma coluna mas na linha de acima na tabela de jogo
	side	- link para a posiçao que esta na mesma linha mas na coluna da direita na tabela de jogo*/

typedef struct node* link;

typedef struct node{
  int value;
  int	id;
  link next;
  link prev;
  link side;
} node;

typedef link* masterline;

/*Lista de linhas completas*/

typedef struct numblines* deletedlines;
typedef struct nodeline* line;

typedef struct numblines{
	long int num;
	line next;
} numblines;

typedef struct nodeline{
	char line[11];
	long int count;
	line next;
} nodeline;

/* Tabela de Hashing */

typedef struct tabh* Item;

typedef struct tabh{
	int code;
	long int count;
} tabh;

typedef struct hashnode {
    Item item;
    struct hashnode* next;
} *hashlink;

typedef int Key;


/********************************************/
/*											*/
/*			Headers de Funções				*/
/*											*/
/********************************************/

/*structs.c*/
link insertNode(link head,char v);
void createLine(masterline master);
void delLine(link linha,masterline master,int n);
void clear(link line,int n);
/*savelines.c*/
void initLine();
line newLine(char string[10]);
void formatString(char destino[10],link apagada);
void saveLines(link apagada,int numlinhas);
void saveLine(link apagada);
int compareLines(char a[10],line b);
void printLines();
void deleteLines();
/*output.c*/
int lMax(masterline master);
void print(int lmax,masterline master);
void output(masterline master,int *points);
/*completepieces.c*/
int piece2id(link currentNode,int id);
int piece3id(link currentNode,int id);
int piece4id(link currentNode,int id);
int piece5id(link currentNode,int id);
int completePieces(masterline master);
void insertInt(int buffer);
/*ST.c*/
void createHash();
hashlink createItem (Item item);
void insertItem(Item item);
Item searchHash(Key k);
void scanHash(void(*visit)(Item));
void clearHash();
void printHash(Item item);
int hash(int k);
/*tetraminoe.c*/
link scanSpace(int F,int C,masterline master);
void writePiece(int F,int C,char M,masterline master,int *points,int N);
int checkSpace5(link l);
int checkSpace2(link l);
int checkSpace3(link l);
int checkSpace4(link l);
int checkSpace5(link l);
int charToInt(char A);
int coder(int F,char M);
int decoderF(int code);
int decoderM(int code);
/*scanlines.c*/
int search(int *v,int size,int test);
int sum(int *v,int size);
void test(link l,int *v);
void scanLine(link limit,int F,masterline master,int *points);
void updateGame(link limit,int a,int b,int F,masterline master,int *points);
