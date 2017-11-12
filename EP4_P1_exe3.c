/**
  * Aluno: Mauricio Tavares Ozaki
  * NUSP: 7577427
  * ACH2023 - AEDI
  * Prof.: Morandini
  * Obs: Professor, eu criei tudo do zero pois nunca tinha feito deque
  * e não saberia se funcionaria minhas ideias.
  **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 50

//Modelo padrão para listas
typedef struct lista Lista;

typedef struct deque Deque;

struct lista {
	int valor;
	Lista *esq;
	Lista *dir;
};

struct deque {
    Lista *inicio1;
    Lista *inicio2;
};

void inicializarDeque (Deque **d) {
    (*d)->inicio1 = NULL;
    (*d)->inicio2 = NULL;
}

Deque *inserir (Deque *d, int v) {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->valor = v;
    novo->esq = NULL;

    if (d->inicio1 == NULL) {
        novo->dir = NULL;
        d->inicio1 = novo;
        d->inicio2 = novo;
    }
    else {
        novo->dir = d->inicio1;
        d->inicio1->esq = novo;
        d->inicio1 = novo;
    }

    return d;
}
//Imprimir da esq para dir
void imprimir (Lista *l) {
	Lista *aux = l;

	while (aux != NULL) {
		printf("%d ", aux->valor);
		aux=aux->dir;
	}

	printf("\n");
}
//Imprimir da dir para esq
void imprimir2 (Lista *l) {
	Lista *aux = l;

	while (aux != NULL) {
		printf("%d ", aux->valor);
		aux=aux->esq;
	}

	printf("\n");
}
//Função que realmente importa, como foi dito em aula que era só necessário
//mudar a chave, então nem mexi nos ponteiros!
void ordenar (Deque **d) {
    Lista *aux1 = (*d)->inicio1;
    Lista *aux2;
    int menor;

    while (aux1->dir != NULL) {
        menor = aux1->valor;
        aux2 = aux1->dir;
        while (aux2 != NULL) {
            if (aux2->valor < aux1->valor) {
                menor = aux2->valor;
                aux2->valor = aux1->valor;
                aux1->valor = menor;
            }
            aux2 = aux2->dir;
        }
        aux1 = aux1->dir;
    }
}

int main (void) {
    Deque *d = (Deque *)malloc(sizeof(Deque));
    int v;

    inicializarDeque(&d);

    printf("Digite os valores para inserir deque. Zero encerra a leitura: ");
    scanf("%d", &v);

    while (v != 0) {
        d = inserir(d, v);
        scanf("%d", &v);
    }

    imprimir(d->inicio1);
    imprimir2(d->inicio2);

    ordenar(&d);

    imprimir(d->inicio1);

    return 0;
}
