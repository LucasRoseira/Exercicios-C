#include <stdio.h>
int soma(int v[], int n){
	if(n == 0)
		return 0;
	else
		return (base * potencia(v, n-1));
}
int main(){
	int base, expoente, resultado;
	scanf("%d", &base);
	scanf("%d", &expoente);
	resultado = potencia(base,expoente);
	printf("%d elevado a %d = %d", base, expoente,resultado);
	return 0;
}
