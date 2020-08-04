#include <stdio.h>
#include <stdlib.h>

//10 - Tabuada
int main(){
	int multiplicando, multiplicador;
	multiplicador = multiplicando = 0;

	printf("Digite o multiplicando: ");
	scanf("%d", &multiplicando);

	
	while(multiplicador != 11)
	{
		printf("%d X %d = %d\n", multiplicando, multiplicador, multiplicador*multiplicando);
		multiplicador++;
	}

	return 0;
}