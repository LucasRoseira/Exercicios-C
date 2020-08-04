#include <stdio.h>
#include <stdlib.h>

#define max 10

//8 - Saber a diferenca entre oa media
int main(){
	int numero[max], media1, media2, diferenca, i;
	media1 = media2 = diferenca = i = 0;

	printf("Saber a diferenca entre a media\n");
	
	for (i = 0; i < max; ++i)
	{
		printf("Digite o numero [%d]: ", i);
		scanf("%d", &numero[i]);

		if(i < 5){
			media1 += numero[i];
		}
		else if(i >= 5){
			media2 += numero[i];
		}
	}
	media1 /= 5;
	media2 /= 5;
	diferenca = media1 - media2;
	printf("A diferenca eh: %d \n", diferenca);
	printf("media1: %d\n", media1);
	printf("media2: %d", media2);

	return 0;
}