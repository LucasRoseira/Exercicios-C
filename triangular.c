#include <stdio.h>
#include <stdlib.h>

int triangular(int n1, int i){
	if (i*(i+1)*(i+2) == n1){

		printf ("%d", i =  i*(i+1)*(i+2) + triangular(n1,i));
	}
	else {
		printf("numero triangular %d \n", i);
	}
}

int main(){

	int n1, i = 1;

	printf("Digite um numero: \n");
	scanf("%d", &n1);

	printf("Triangular: %4d\n\n", triangular(n1, i));
}