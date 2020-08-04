#include <stdio.h>
#include <stdlib.h>

#define max 100

//3 - Saber a diferenca entre o maior e o menor numero
int main(){
	int numero[max], i, maior, menor, diferenca;
	maior = 0;
	menor = 500000000;

	printf("Saber a diferenca entre o maior e o menor numero \n");
	
	for (i = 1; i < max; ++i)
	{
		printf("Digite o numero [%d] ", i);
		scanf("%d", &numero[i]);

		if(numero[i] > maior){
			maior = numero[i];
		}
		if(menor > numero[i]){
			menor = numero[i];
		}
	}

	diferenca = maior - menor;
	printf("A diferenca eh: %d\n", diferenca);

	return 0;
}