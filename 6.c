#include <stdio.h>
#include <stdlib.h>

#define max 100000

//6 - Saber quais numeros estao em quais intervalos
/*
	0-25
	26-50
	51-75
	76-100
*/
int main(){
	int numero[max], i;
	int intervalo1, intervalo2, intervalo3, intervalo4;

	i = intervalo1 = intervalo2 = intervalo3 = intervalo4 = 0;

	printf("Saber quais numeros estao em quais intervalos \n");
	printf("Digite 12345678 para parar \n");

	
	for (i = 1; i < max; ++i)
	{
		printf("Digite o numero [%d]: ", i);
		scanf("%d", &numero[i]);

		if(numero[i] == 12345678){
			break;
		} else {
			//intervalo1
			if(numero[i] >= 0 && numero[i] <= 25){
				intervalo1++;
			}
			//intervalo2
			else if(numero[i] >= 26 && numero[i] <= 50){

				intervalo2++;
			}
			//intervalo3
			else if(numero[i] >= 51 && numero[i] <= 75){

				intervalo3++;
			}
			//intervalo4
			else if(numero[i] >= 76 && numero[i] <= 100){
				intervalo4++;
			}
		}
	}

	printf("Quantidade no intervalo entre 0-25: %d\n", intervalo1);
	printf("Quantidade no intervalo entre 26-50: %d\n", intervalo2);
	printf("Quantidade no intervalo entre 51-75: %d\n", intervalo3);
	printf("Quantidade no intervalo entre 76-100: %d\n", intervalo4);

	return 0;
}