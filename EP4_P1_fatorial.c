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

//Funcao fatorial recursiva
int fatorial (int n) {
	if (n == 0)
		return 0;
	else if (n==1)
		return 1;
	else
		return n*fatorial(n-1);
}

int main (void) {
	int n;

	printf("Vamos calcular o valor de n!\n");
	printf("Digite o valor de n: \n");
	scanf("%d", &n);
	//Verifica se o valor de n > 0
	if (n < 0)
		printf("Valor impróprio!");
	else
		printf("O valor de %d! = %d", n, fatorial(n));

    return 0;
}
