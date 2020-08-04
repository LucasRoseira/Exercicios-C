#include<stdio.h>
#include<stdlib.h>


int somasSucessivas (int num1, int num2){
	int i;
	int somaTotal = 0;

	if(num1 != 0) {
		//printf("soma total = %d", somaTotal);
		return somaTotal += num2 + somasSucessivas(num1-1, num2);
	}
	else {
		return somaTotal;
	}
}

int main(){

	int n1, n2;

	printf("Digite dois numeros\n");
	scanf("%d%d", &n1, &n2);

	printf("%d", somasSucessivas(n1, n2));
	return 0;
}


