#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMIMPAR 200
#define TAMPAR 200

//Código bugado que estou cons
void insercao (int tam, int *vetor);

int main()
{
	int aux, tam, num;
	int pares[100], impares[j];
	printf("Digite a quantidade de linhas: \n");
	scanf("%d", &tam);
	aux = tam;
	while(--tam > -1){
		printf("Digite a os numeros: \n");
		scanf("%d", &num);
		if(num%2 == 0){
			pares[TAMPAR] = num;
			TAMPAR++;
		}else{
			impares[TAMIMPAR] = num;
			TAMIMPAR++;
		}
	}
	insercao(aux, pares);
	insercao(aux, impares);

}
void mostraMatriz(int tam, int *vetor)
{
	int i;
	for (i=0;i<tam;i++)
	{
		printf("\nOrdenado: %d", vetor[i]);

	}
}
void insercao (int tam, int *vetor)
{
	int i,j, y, aux;	
	j=1;
	while (j<=tam-1)
	{
		printf("\n-->%d",j);
		aux = vetor[j];

		i = j - 1;
		while (  i >= 0 &&  vetor[i] < aux ) 
		{         
			printf("\ntrocou %i ",vetor[i]);		 		   
			vetor[i+1] = vetor[i];           
			i = i - 1;
			printf("\n                   ");
			for (y=0;y<tam;y++) printf("%i ",vetor[y]);		 
		}    
	vetor[i+1] = aux;
	j = j + 1;
		//printf("\n                   ");

}