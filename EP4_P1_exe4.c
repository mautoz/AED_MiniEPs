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
#define N 50
//Define o limite no topo, n�o sei se poderia desta forma
//E criei um contador para verificar quantos termos existem
int contador = 0;

//Modelo padr�o para listas
typedef struct lista Lista;

//Como pilhas e filas diferem apenas pela forma em qe s�o inseridos, ent�o mantive
//a mesma estrutura de dados para ambos.
struct lista {
	int valor;
	Lista *prox;
};

//Enfileira os dados
Lista *inserir (Lista *l, int v) {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    Lista *aux;
    novo->valor = v;
    novo->prox = NULL;

    if (l==NULL)
        return novo;
    else {
        aux = l;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }

    return l;
}
//A fun��o remover funciona para ambos, pois a fun��o 'push' e 'inserir' j�
//adicionam de maneira correta os dados de pilha e fila.
Lista *remover (Lista *l) {
    Lista *aux = l;

    if (l == NULL) {
        printf("Fila vazia");
        return NULL;
    }

    l = l->prox;
    free(aux);

    return l;
}

//Empilha os dados
Lista *push (Lista *l, int v) {
    Lista *novo = (Lista *)malloc(sizeof(Lista));
    novo->valor = v;

    if (l == NULL)
        novo->prox = NULL;
    else
        novo->prox = l;
    l = novo;

    return l;
}

//Imprimir um lista n�o vazia
void imprimir (Lista *l) {
	Lista *aux = l;

	while (aux != NULL) {
		printf("%d ", aux->valor);
		aux=aux->prox;
	}
    printf("\n");
}
//Como era necess�rio uma fun��o que receberia uma fila e uma pilha e iria adicionar
//Fiz uma fun��o que chama push e inserir ao mesmo tempo.
void criarPilhaFila (Lista **p, Lista **f, int v, int limite) {
    if (contador <= limite) {
        *p = push((*p), v);
        *f = inserir((*f), v);
        contador++;
    }
}
//Assim como a anterior, fiz uma fun��o que chama push e inserir ao mesmo tempo.
void DesemPilhaFila (Lista **p, Lista **f) {
    *p = remover(*p);
    *f = remover(*f);
}

int main (void) {
    Lista *fila = NULL;
    Lista *pilha = NULL;
    int v;

    printf ("Qual o valor ser� inserido?\n");
    scanf("%d", &v);

    while (v != 0) {
        criarPilhaFila (&pilha, &fila, v, N);
        scanf("%d", &v);
    }
    imprimir(pilha);
    imprimir(fila);

    while (fila!=NULL) {
        printf("\nDesempilha: %d\n", pilha->valor);
        printf("\nDesenfileira: %d\n", fila->valor);
        DesemPilhaFila (&pilha, &fila);
        imprimir(pilha);
        imprimir(fila);
    }

    printf("\nLimite = %d \nContador = %d\n", N, contador);
    return 0;
}
