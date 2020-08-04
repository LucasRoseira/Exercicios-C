#include <stdio.h>
#include <stdlib.h>

#define max 10000000

// 
int main(){
	int numero1, numero2, i;
	numero1 = numero2 = i = 0;

	printf("Digite dois pares para saber qual numero eh maior \n");
	printf("Digite um par de zeros para parar \n");

	
	for (i = 1; i < max; ++i)
	{
		printf("Digite o primeiro numero: ");
		scanf("%d", &numero1);
		printf("Digite o segundo numero: ");
		scanf("%d", &numero2);

		if(numero1 == 0 && numero2 == 0){
			break;
		}
		else {

			if(numero1 > numero2){
				printf("O primeiro nuemero eh maior: %d\n", numero1);
			}
			else if(numero1 < numero2){
				printf("O segundo numero eh maior: %d\n", numero2);
			}
			else 
			{
				printf("Os dois sao iguais!!!");
			}
		}
	}

	return 0;
}