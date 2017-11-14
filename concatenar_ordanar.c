/*  ACH2023 - Professor Marcelo Morandini
    Aula dia 14/11/2017
    EPzinho de Contenar
    Maurício Tavares Ozaki - Nº USP: 7577427
    Lucas Zan - Nº USP  8657539
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct lista Fila;

struct lista {
    int chave;
    int valor;
    Fila *prox;
};
//Inserir elementos na lista
void inserir (Fila **p, int ch, int v) {
    Fila *nova = (Fila *)malloc(sizeof(Fila));
    Fila *aux;


    nova->chave = ch;
    nova->valor = v;
    nova->prox = NULL;

    if ((*p) == NULL)
        (*p) = nova;
    else {
        aux = (*p);
        while (aux->prox != NULL) aux = aux->prox;
        aux->prox = nova;
    }
}
//Funcao concaternar que recebe duas listas ligadas e concatena
Fila *concatenar (Fila *p1, Fila *p2) {
    Fila *aux1 = p1;
    Fila *aux2 = p2;
    Fila *p3 = NULL;
    //Enquanto as filas não chegam em NULL, ambas são comparadas
    while (aux1 != NULL && aux2 != NULL) {
        if (aux1->chave < aux2->chave) {
            inserir(&p3, aux1->chave, aux1->valor);
            aux1 = aux1->prox;
        }
        else if (aux1->chave > aux2->chave) {
            inserir(&p3, aux2->chave, aux2->valor);
            aux2 = aux2->prox;
        }
        else {
            inserir(&p3, aux1->chave, (aux1->valor)+(aux2->valor));
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }
    }
    //Verifica se uma das listas ainda tem termos e os insere
    if (aux1 != NULL) {
        while (aux1 != NULL) {
            inserir(&p3, aux1->chave, aux1->valor);
            aux1 = aux1->prox;
        }
    }
    else if (aux2 != NULL) {
        while (aux2 != NULL) {
            inserir(&p3, aux2->chave, aux2->valor);
            aux2 = aux2->prox;
        }
    }

    return p3;
}
// Recebe uma fila e ordena por chave utilizando o Selection sort
Fila* ordenar (Fila *f) {
    Fila *aux1;
    Fila *aux2;
    int tempCH, tempV;

    //Só existe 1 elemento
    if (f->prox == NULL) return f;
    else {
        for (aux1 = f; aux1->prox != NULL; aux1 = aux1->prox) {
            for (aux2 = aux1->prox; aux2 != NULL;  aux2 = aux2->prox) {
                if (aux1->chave > aux2->chave) {
                    tempCH = aux1->chave;
                    tempV = aux1->valor;
                    aux1->chave = aux2->chave;
                    aux1->valor = aux2->valor;
                    aux2->chave = tempCH;
                    aux2->valor = tempV;
                }
            }
        }
    }

    return f;
}

//Imprimir a Fila
void imprimir (Fila *p) {
    Fila *aux = p;

    while (aux != NULL) {
        printf("Chave = %d e Valor = %d\n", aux->chave, aux->valor);
        aux = aux->prox;
    }
}

int main(){
    Fila *lista1 = NULL;
    Fila *lista2 = NULL;
    Fila *lista3 = NULL;
    int v;
    int ch = 0;

    printf("Digite os valores para inserir na fila 1 (negativo encerra a leitura): \n");
    scanf("%d %d", &ch, &v);
    while (ch >= 0) {
        inserir(&lista1, ch, v);
        scanf("%d %d", &ch, &v);
    }

    printf("\nLista 1 ordenada: \n");
    ordenar(lista1);
    imprimir(lista1);

    printf("Digite os valores para inserir na fila 2 (negativo encerra a leitura): \n");
    scanf("%d %d", &ch, &v);
    while (ch >= 0) {
        inserir(&lista2, ch, v);
        scanf("%d %d", &ch, &v);
    }

    printf("\nLista 2 ordenada: \n");
    ordenar(lista2);
    imprimir(lista2);

    lista3 = concatenar(lista1, lista2);

    printf("\nLista 3, concatenada: \n");
    imprimir(lista3);

    return 0;
}
