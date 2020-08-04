#include <stdio.h>
#include <stdlib.h>

int Digitos(int N);

int main(){
	int numero;
	scanf("%d", &numero);
	printf("%d", Digitos(numero));
	return 0;
}

int Digitos(int N){
	int contador = 1;
	if(N > 9){
		 contador += Digitos(N/10);
		return contador;
	}
	else
	{
		return 0;
	}
}