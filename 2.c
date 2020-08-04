#include <stdio.h>
#include <stdlib.h>

#define max 100000

//2 - Saber a quantidade de numeros totais e o maior numero
int main(){
	int numero[max], i, maior;
	maior = i = 0;

	printf("Saber a quantidade de numeros totais e o maior numero \n");
	printf("Digite 12345678 para parar \n");

	
	for (i = 1; i < max; ++i)
	{
		printf("Digite o numero [%d]:", i);
		scanf("%d", &numero[i]);

		if(numero[i] == 12345678){
			break;
		}
		else{

			if(maior < numero[i]){
				maior = numero[i];
			}
		}
	}

	printf("Foram fornecidos: %d \n", i-1);
	printf("O maior eh: %d", maior);
	return 0;
}