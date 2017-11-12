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
#define MAX 20

//Modelo padrão para listas
typedef struct lista Lista;

struct lista {
	int valor;
	Lista *prox;
};
//Função inserir, recebe a lista e o vetor e adiciona respeitando os índices de v[]
Lista *insereLista (Lista *n, int v[]) {
	Lista *novo;
	Lista *aux;
	Lista *new_n = NULL;
	int i = 0;

	while (i < MAX) {
        novo = (Lista *)malloc(sizeof(Lista));
        novo->valor = v[i];
        novo->prox = NULL;

        if (n == NULL) {
            n = novo;
        }
        else {
            aux = n;
            while (aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;
        }
        i++;
	}

	return n;
}

void imprimir (Lista *l) {
	Lista *aux = l;

	while (aux != NULL) {
		printf("%d ", aux->valor);
		aux=aux->prox;
	}
}

int main (void) {
	Lista *new_vetor = NULL;
	int vetor[20];
	int i;
	//Para testar o programa, eu fiz os dois for para criar um vetor aleatório.
	for (i = 0; i < 20; i++)
		vetor[i] = rand()%100;

	for (i = 0; i < 20; i++)
		printf("%d ", vetor[i]);

	new_vetor = insereLista(new_vetor, vetor);

	printf("\n");
	imprimir(new_vetor);

    return 0;
}
