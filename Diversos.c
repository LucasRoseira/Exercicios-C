#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include<string.h>
#include<ctype.h>

#define MAX 10

void verificaPrimo(int num);		//1
int fatorial(int n);				//2
void verificaCaracter(char string[], char caracter[]); //6
void intercala_vetor();
int main()
{
	//Seta localização para usar acentuação
	setlocale(LC_ALL,"");
	int opcao = 0, num; 
	int n;
	char inicial[50] = {"Atividade Final da faculdade\n"};
	char digite[50] = {"Digite um número: "};
	char opt[50] = {"a opção: \n"};
	char str[50] = {"a string: \n"};
	char carac[50] = {"caracter: \n"};
	char caracter[1];

	char string[10];

	//Imprimi a frase inical
	printf("%s", inicial);

	do{
		printf("\n"); 
		//Laços para mostrar a frase: ""Digite uma opção: "
		for (int i = 0; i < 9; ++i)
			printf("%c", digite[i]);

		for (int i = 0; i < 10; ++i)
			printf("%c", opt[i]);
		scanf("%d", &opcao);
		label:
		switch (opcao)
		{
			case 1:
			{
				//For para mostarar a frase "digite um número: "
				for (int i = 0; i < 19; ++i)
				{
					printf("%c", digite[i]);
				}
				scanf("%d", &num);
				verificaPrimo(num);
				break;
			}

			case 2:
			{
				//For para mostarar a frase "digite um número: "
				for (int i = 0; i < 19; ++i)
				{
					printf("%c", digite[i]);
				}
				scanf("%d", &n);	//Recebe o número
				printf("Fatorial: %d\n", fatorial(n)); 	//Printa a função recursiva fatorial
				break;
			}
			case 3:
			{
				//For para mostarar a frase "digite uma string: "
				for (int i = 0; i < MAX; ++i)
				{
					printf("%c", str[i]);
				}
				scanf("%s", &string);	//Recebe a string
				//For para mostarar a frase "digite uma string: "
				for (int i = 0; i < MAX; ++i)
				{
					printf("%c", carac[i]);
				}
				scanf("%s", &caracter);	//Recebe o caracter
				verificaCaracter(string, caracter); 	//Printa a função recursiva fatorial
				break;
			}
			case 4:
			{
				intercala_vetor();
				break;
			}

			goto label;
		}
	} while (opcao!=3);
	return 0;
}
//1
void verificaPrimo(int num){
	int resultado;

	for (int i = 2; i <= num / 2; i++) {
		if (num % i == 0) {
			resultado++;
			break;
		}
	}

	if (resultado == 0){
		printf("O número %d é primo\n", num);
	}
	else{
		printf("O número: %d não é primo\n", num);
	}

}
//2
int fatorial(int n)
{
	long long int valorFatorial;

	if ( n <= 1 ){
		return 1;
	}
	else
	{
		valorFatorial = n * fatorial(n - 1);
		return (valorFatorial);
	}
}

void verificaCaracter(char string[], char caracter[]){
	int x;
	x = strlen(string);
	for (int i = 0; i < x; ++i)
	{
		if(string[i] == caracter[0]){
			printf("O caracter está presente na posição: [%d]\n", i);
		} 
		else if(string[i] != caracter[0] && i == x-1){
			printf("O caracter  não esta no vetor\n", i);
		}
	} 
}

void intercala_vetor(){
	int vet1[MAX], vet2[MAX];
	char vet3[20];
	int i, j, k;
	for (i = 0; i < 3; ++i)
	{
		scanf("%d", &vet1[i]);
	}
	for (int i = 0; i < 3; ++i)
	{
		printf("vetor1[%d] = %d \n",i, vet1[i]);	
	}
	for (j = 0; j < 3; ++j)
	{
		scanf("%d", &vet2[j]);
	}
	for (i = 0, j = 0; i < 5; k++, i++, j++)
	{
		vet3 = vet1[i];
		vet3 = vet2[j+1];	
	}
	printf("\n\n");
	for (k = 0; k < 7; ++k)
	{
		printf("vetor3[%d] = %s \n",k, vet3);	
	}
}