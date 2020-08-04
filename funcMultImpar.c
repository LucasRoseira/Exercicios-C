#include<stdio.h>
#include<stdlib.h>
int cont = 0;

int funcMultImpar(int x){
	if (cont == 4 )
	{
		return x;
	} else {
		cont++;
		return x+= funcMultImpar(x + 2);
	}
}
int main(){
	int x = 1;
	while(x !=0) {
		if(cont >0)
			cont = 0;
		printf("Digite um numero: \n");
		scanf("%d", &x);
		if(x == 0){
			return 0;
		}
		if(x % 2 == 0)
			x++;

		printf("Total: %d\n", funcMultImpar(x));
	}
	return 0;
}