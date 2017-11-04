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

/* Strcut da lista */
typedef struct lista No;

struct lista {
	int num;
	No *prox;
};

/* Inserir elemento na lista sem NoCabeca */																										
No* insere (int x, No *p) {
	No *novo = malloc(sizeof(No)); 
	novo->num=x;
	
	if (p==NULL)
			novo->prox=NULL;
	else
		novo->prox=p;
			
	p=novo;
	
	return p;
}

/*Imprimir a lista */
void imprimir (No* l) {
	No *atual;
	
	printf("\n");
	for (atual = l; atual!=NULL; atual=atual->prox) {
		printf("%d ", atual->num);
	}
}

/* Separa pares e Impares. Conforme o Sr. informou, o elemento	*/
/* negativo eh o sinal para parar de ler o vetor! 				*/
void ParesImpares (No **v, No **par, No **impar) {
	No *aux = *v;	
	
	while (aux!=NULL) {
		if ((aux->num)%2==0)			
			*par=insere(aux->num, *par);
		else
			*impar=insere(aux->num, *impar);
		aux = aux->prox;
	}		
}


No *remover (No **l, int ch) {
	No *aux = *l;
	No *ant = NULL;
	
	if (aux->num == ch) return aux->prox;
	else {
		ant = aux;
		aux = aux->prox;
		while (aux != NULL) {
			if (aux->num == ch) {
				ant->prox=aux->prox;
			}
			ant = aux;
			aux = aux->prox;
		} 
	}
	
	return *l;
}

int main (void) {
	No *par = NULL;
	No *impar = NULL;
	
	No *l = NULL;
	int num=1;
	/* Le uma sequencia de caracters dada pelo usuario e insere na lista */
	/* Em caso de negativo, encerra a leitura */
	printf("Digite os valores da lista, negativo encerra a leitura: \n");
	while (num > 0) {
		scanf("%d", &num);
		l=insere(num, l);		
	}
	
	/* Imprime o vetor digitado */	
	imprimir(l);

	/* Item 3: separa o vetor */
	ParesImpares(&l, &par, &impar);
	
	/* Item 2: Imprimi os valores pares e ímpares */
	printf("\nVetor dos pares");
	imprimir(par);
	printf("\n");	
	printf("\nVetor de ímpares");
	imprimir(impar);
	printf("\n");
	
	/* Item 1: Remover da lista */
	/* Pergunta ao usuário o número que será deletado */
	printf("Digite o elemento que sera deletado: \n");
	scanf("%d", &num);

	/*Lista antes */
	imprimir(l);
	l=remover(&l, num);
	
	/* Lista depois da remoção */
	imprimir(l);

	

    return 0;
}

