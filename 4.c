#include <stdio.h>
#include <stdlib.h>

#define max 202

//4 - Numeros impares comecando de 101
int main(){
	int numero[max], i, j;
	i = j = 0;

	printf("Numeros impares comecando de 101 \n");
	
	for (i = 101, j = 1; i < 200; i+=2, j++)
	{
		printf("O numero impar [%d] eh: %d \n", j, i);
	}


	return 0;
}