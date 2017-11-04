#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista Letras;
typedef struct sublista Nomes;

//Lista de 'inicial' de A até Z, é a lista principal e de cada 'inicial' sai uma 'sublista', chamada apelidos
//que contém os nomes das 'pessoas'.
struct lista {
	char inicial;
	Letras *prox;
	Nomes *apelidos;
};

//'Sublista' vinculada com cada 'inicial' da lista acima
struct sublista {
	char pessoa[15];
	Nomes *prox;
};

//Verifica se entre os valores já cadastrados (lista), existe a inicial do novo nome que será inserido
int busca (Letras *l, char inicial) {
	Letras *aux;
	
	for (aux = l; aux!=NULL; aux=aux->prox)
		if (aux->inicial==inicial) return 1;
		
	return 0;	
}

//Verifica se o nome existe na sublista 1 caso encontre e 0 caso contrário.
int buscaPessoa (Nomes *n, char nome[]) {
	Nomes *aux;
	
	for (aux=n; aux!=NULL; aux=aux->prox) {
		if (strcmp(aux->pessoa, nome) == 0) return 1;
	}
	
	return 0;
}

//Inserir um nome na sublista
Nomes *inserirApelidos (Nomes *n, char apelido[]) {
	Nomes *novo = malloc(sizeof(Nomes));
	
	strcpy(novo->pessoa, apelido);
	if (n==NULL)
		novo->prox=NULL;
	else
		novo->prox=n;
		
	return novo;	
}

//Inserir a inicial do nome caso ela não esteja na LISTA
Letras *inserir (Letras *l, char nome[], char p) {
	Letras *novo = malloc(sizeof(Letras));
	
	novo->apelidos=NULL;
	novo->inicial=p;
	if (l==NULL)
		novo->prox=NULL;
	else
		novo->prox=l;
	//Se não possui a inicial, não precisa verificar se já existe um nome, obrigatoriamente, será o primeiro.
	novo->apelidos=inserirApelidos(novo->apelidos, nome);
	
	return novo;				
}

//Inserir o apelido na Sublista caso inicial do nome caso esteja na LISTA
Letras *inserir2 (Letras *l, char nome[], char p) {
	Letras *aux = l;
	
	while (aux->inicial!=p)
		aux=aux->prox;
	//Verifica se o nome jah existe, para evitar repeticoes
	if (buscaPessoa(aux->apelidos, nome)==0)
		aux->apelidos=inserirApelidos(aux->apelidos, nome);
	
	return l;				
}

//Conforme insere, a lista vai aumentando e imprimindo por letra
void imprimir (Letras *l) {
	Letras *aux;
	Nomes *aux2;
		
	for (aux=l; aux!=NULL; aux=aux->prox){
		printf("%c ", aux->inicial);
		for (aux2=aux->apelidos; aux2!=NULL; aux2=aux2->prox) {
			printf("%s ", aux2->pessoa);
		}
		printf("\n");
	}
}

int main (void) {
	Letras *lista=NULL;
	char nome[30];
	
	printf("Digite o apelido ou o primeiro nome.\n");
	printf("Digite 'fim' e encerre a leitura!\n");
	
	
/*	while (fscanf(f, "   %s   ", &etc) != EOF) { 
	
	}
*/

	scanf("%s", nome);
	
	while (strcmp(nome, "fim") != 0) { 
		//Verifica se jah existe a letra
		if (busca(lista, nome[0])==0) {
			lista=inserir(lista, nome, nome[0]);
			printf("\nLista: \n");
			imprimir(lista);
		}
		else {
			lista=inserir2(lista, nome, nome[0]);
			printf("\nLista: \n");
			imprimir(lista);			
		}
				
		scanf("%s", nome);		
	}
	
    return 0;
}

