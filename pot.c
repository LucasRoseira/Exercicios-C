#include <stdio.h>
int soma(int v[], int n){
	if(n == 0)
		return 1;
	else
		return (v[n-1] + soma(v, n-1));
}
int main(){
	int v[150], n, i, resultado;
	for (n = 0; n < 15; ++n)
	{
		scanf("%d", &v[n]);
	}

	resultado = soma(v, n);
	printf("%d soma a %d = %d", v, n, resultado);
	return 0;
}
