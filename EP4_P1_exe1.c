/**
  * Aluno: Mauricio Tavares Ozaki
  * NUSP: 7577427
  * ACH2023 - AEDI
  * Prof.: Morandini
  **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 50

typedef struct lista Lista;

struct lista {
	int valor;
	Lista *prox;
};
//Insere lista, criei para testar a função inverso
Lista *insereLista (Lista *n, int v) {
	Lista *novo = (Lista *)malloc(sizeof(Lista));
	novo->valor = v;

	if (n == NULL)
		novo->prox=NULL;
	else
		novo->prox=n;

	return novo;
}
//Função que cria uma nova lista com os ponteiros invertidos
Lista *inverso (Lista *l) {
	Lista *nova = NULL;
	Lista *aux = l;

	while (aux != NULL) {
		nova = insereLista (nova, aux->valor);
		aux = aux->prox;
	}

	return nova;
}
//Imprimir a lista inteira
void imprimir (Lista *l) {
	Lista *aux = l;

	while (aux != NULL) {
		printf("%d ", aux->valor);
		aux=aux->prox;
	}
}

int main (void) {
	Lista *pilha = NULL;
	Lista *fila = NULL;
	int v = 1;

	printf("Digite os valores que serão inseridos: ");
	scanf("%d", &v);

	while (v != 0) {
		pilha = insereLista(pilha, v);
		scanf("%d", &v);
	}

	imprimir(pilha);

	fila = inverso(pilha);

	printf("\nInverso:\n");

	imprimir(fila);

    return 0;
}
