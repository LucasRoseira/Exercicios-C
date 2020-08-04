#include <stdio.h>
#include <stdlib.h>

#define max 100000

int main(){
	float item[max];
	int i;
	float total;



	printf("100 - Cachorro quente R$ 1,70 	\n");
	printf("101 - Bauro Simples R$ 2,30 	\n");
	printf("102 - Bauro com ovo R$ 2,60 	\n");
	printf("103 - Hamburger R$ 2,40 		\n");
	printf("104 - Cheese Burger R$ 2,50 	\n");
	printf("105 - Refrigereante R$ 1,00		\n");
	printf("Cardapio de lanches: \n");


	printf("Digite 0 para parar \n");

	
	for (i = 1; i < max; ++i)
	{
		printf("Escolha um item do cardaptio: ");
		scanf("%f", &item[i]);

		if(item[i] == 0){
			break;
		} else {
			//100 - Cachorro quente R$ 1,70
			if(item[i] == 100){
				total += 1.70;
			}
			//101 - Bauro Simples R$ 2,30
			else if(item[i] == 101){
				total += 2.30;
			}
			//102 - Bauro com ovo R$ 2,60
			else if(item[i] == 102){
				total += 2.60;
			}
			//103 - Hamburger R$ 2,40
			else if(item[i] == 103){
				total += 2.40;
			}
			//104 - Cheese Burger R$ 2,50
			else if(item[i] == 104){
				total += 2.50;
			}
			//105 - Refrigereante R$ 1,00
			else if(item[i] == 105){
				total += 1;
			}
		}
	}

	printf("Quantidade: %d \nTotal dos pedidos %.2f", i-1, total);


	return 0;
}