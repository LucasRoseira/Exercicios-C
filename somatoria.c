#include<stdio.h>
#include<stdlib.h>

int somatoria (int num[], int cont){
	int somaTotal = 0;

	if(cont < 0){
		printf("\nTESTE\n");
		return somaTotal;
	}
	else {
		return somaTotal += num[cont] + somatoria(num, cont-1);
	}
}

int main(){
	int x[10] = {5,6,7,4,3,2,7,8,4,3};
	int z = 10;

	printf("%d", somatoria (x, z));
	return 0;
}

