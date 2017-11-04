/****************************************/
/* Aluno: Mauricio Tavares Ozaki        */
/* NUSP: 7577427						*/
/* Aluno: Lucas Zan Arriaga		        */
/* NUSP: 8657539						*/
/* ACH2023 - AEDI						*/
/* Prof.: Morandini						*/
/****************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

/* Atualiza a posição de acordo com a entrada */
int contador = 0;

/* Struct da lista */
typedef struct lista No;

struct lista {
	char nome[MAX];
	int pos;
	No *prox;
};

/*Imprimir a lista */
void imprimir (No *p) {
	No *atual;
	
	printf("\n");
	for (atual = p; atual!=NULL; atual=atual->prox) {
		printf("Nome: %s\t\t\tPosicao: %d\n", atual->nome, atual->pos);
	}
}

/* Inserir elemento na lista sem NoCabeca */																										
void push (No **p, char n[]) {
	No *novo = malloc(sizeof(No)); 
	No *aux = *p;

	strcpy(novo->nome, n);
	novo->pos=++contador;
	novo->prox=NULL;
	
	if ((*p)==NULL)
		*p = novo;
	else {
		while (aux->prox!=NULL) {
			aux = aux->prox;			
		}
		aux->prox=novo;		
	}
}

int main (void) {
	No *l = NULL;
	char n[MAX];
	
	printf("Digite os valores da lista, negativo encerra a leitura: \n");	
	scanf("%s", n);
	
	//Le as strings dadas pelo usuário até ser digitado 'fim'
	while (strcmp(n, "fim") != 0) { 
		push(&l, n);
		scanf("%s", n);	
		i++;	
	}
	
	/* Imprime a lista com a posicao */	
	imprimir(l);

    return 0;
}
