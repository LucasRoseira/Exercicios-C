#include <stdio.h>
#include <stdlib.h>

//Definindo um valor maximo para usar no FOR
#define max 100000

//1 - Saber a quantidade de numeros totais e os negativos
int main(){
	int numero[max], i, negativos;
	negativos = i = 0;

	printf("Saber a quantidade de numeros totais e os negativos \n");
	printf("Digite 12345678 para parar \n");

	
	for (i = 1; i < max; ++i)
	{
		printf("Digite o numero [%d]:", i);
		scanf("%d", &numero[i]);

		if(numero[i] == 12345678){
			break;
		}
		else {
			if(numero[i] < 0){
				negativos++;
			} 
		} 
	}

	printf("Foram fornecidos: %d numeros \n", i-1);
	printf("Quantidade de numeros negativos: %d", negativos);
	return 0;
}