#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>

#define TAMEDIA 10 
#define TAMVETOR 10

void Exercicio1(void);
float MediaAritmeticaRecursiva(int Vet[TAMEDIA], float Tam, int Ind);

void Exercicio2(void);
int inverte(int inverter);

void Exercicio3(void);
int somaVetor (int num[], int cont, int total);

void Exercicio4(void);
float inverteVetor (float vetor[TAMVETOR], int a, int b);

void Exercicio5(void);
int Mdc(int n1, int n2);

void Exercicio6(void);
int Somatoria(int n);

void Exercicio7(void);

void Exercicio8(void);
int Multip_Rec(int n1,int n2);

void Exercicio9(void);
int ImprimeNaturais(int n, int naturais);

void Exercicio10(void);


int main(){

	int Exercicio;
	int i;

	do
	{
		//Sleep(2000);
		//system("clear");
		printf("Selecione um exercicio de 1 a 10: ");		
		printf("\n11 para Sair\n");
		scanf("%i", &Exercicio);

		switch(Exercicio){
			case 1:
			Exercicio1();
			break;
			case 2:
			Exercicio2();
			break;
			case 3:
			Exercicio3();
			break;
			case 4:
			Exercicio4();
			break;
			case 5:
			Exercicio5();
			break;
			case 6:
			Exercicio6();
			break;
			case 7:
			Exercicio7();
			break;
			case 8:
			Exercicio8();
			break;
			case 9:
			Exercicio9();
			break;
			case 10:
			Exercicio10();
			break;
			default:
			printf("\n\nOpcao Invalida");
		}
	} while ( Exercicio != 11);
	return 0;
}
//OK
void Exercicio1(void){
	int Vetor[TAMEDIA] = {0}, i;

	printf("Digite os valores na matriz\n");

	for(i=0; i<TAMEDIA; i++)
	{
		scanf("%i", &Vetor[i]);
	}
	printf("Media = %f\n", MediaAritmeticaRecursiva(Vetor, TAMEDIA, 0));
}

float MediaAritmeticaRecursiva(int Vet[TAMEDIA], float Tam, int Ind)
{
	if (Ind < Tam)
	{
       // printf("\nVet[%i] = %i\n",Ind, Vet[Ind]);
		return (Vet[Ind]/Tam) + MediaAritmeticaRecursiva(Vet, TAMEDIA, Ind+1) ;
	}
	else
	{
		return main();
	}
}
//NOT OK
void Exercicio2(void){
	int numero = 0;
	printf("Digite um numero para inverter: ");
	scanf("%i", &numero);
	printf("Invertido = %15d\n", inverte(numero));
}

int inverte(int inverter){
	int numero = 0;
	if (inverter == 0) {
		return inverter;
	}
	else{
		printf("inverter: %17d\n", inverter);
		if(inverter/10 > 0){
			numero = (inverter%10)*1000;
			numero /= 1000;
		}
		else if(inverter/100 > 0){
			numero = (inverter%100)*10;
		}
		else if (inverter/1000 > 0 )
		{
			numero = (inverter%1000);
		}
		else {
			numero = inverter;
		}
		printf("numero: %17d\n", numero);

		return inverter = numero + inverte(inverter/10);
	}
}
//OK
void Exercicio3(void){
	int x[10] = {10,10,10,10,10,10,10,10,10,15};
	int z = 10;
	int total = 0;

	printf("%d \n", somaVetor(x, z, total));
}

int somaVetor (int num[], int cont, int total){
	if(cont > 0){
		return total += num[cont] + somaVetor(num, cont-1, total);
	}
	else {
		return total;
	}
}
//OK
void Exercicio4(void){
	float vetor[TAMVETOR] = {0};
	int i, j;
	i = j = 0;

	for (;i < TAMVETOR; i++)
	{
		printf("Digite os valor do vetor [%d]:", i);
		scanf("%f", &vetor[i]);
	}
	inverteVetor(vetor, j, i -1);

	for (i = 0; i < TAMVETOR; i++) {
		printf("Vetor: %0.1f \n", vetor[i]);
	}
}

float inverteVetor (float vetor[TAMVETOR], int a, int b){
	if (vetor != NULL){	
		if ((b-a)>0) {
			//printf("\n ANTES: vetor [%i] = %.2f e vetor [%i] = %.2f",a, vetor[a], b,vetor[b]); // ==>> para teste
			float aux = vetor[a];
			vetor[a] = vetor[b];
			vetor[b] = aux;
			inverteVetor(&vetor[TAMVETOR], a+1, b-1);
		} else {
			return * vetor;	
		}	
	}
}
//OK
void Exercicio5(void){
	int n1, n2;
	printf("Digite dois numeros \n");
	scanf("%d%d", &n1, &n2);
	printf("Maximo Divisor Comum: %15d \n\n", Mdc(n1,n2));
}

int Mdc(int n1, int n2){
	if (n1%n2 == 0){
		return n2;
	}else{
		return Mdc(n2,n1%n2);
	}
}
//OK
void Exercicio6(void){
	int numero = 0;
	printf("Digite um numero: \n");
	scanf("%d", &numero);
	printf("Soma: %d \n", Somatoria(numero));
}

int Somatoria(int n){
	int x;
	if(n < 1) return x;
	else{
		printf("Somatoria: %20d \n", n);
		x = n + Somatoria(n - 1);
		return x;
	}
}

//NOT OK
void Exercicio7(void){

}

//OK
void Exercicio8(void){
	int n1, n2;

	printf("Digite dois numeros\n");
	scanf("%d%d", &n1, &n2);

	printf("SOMA: %4d\n\n", Multip_Rec(n1, n2));
}

int Multip_Rec(int n1,int n2){
	int somaTotal = 0;
	if(n1 != 0) {
		//printf("soma total = %d", somaTotal);
		return somaTotal += n2 + Multip_Rec(n1-1, n2);
	}
	else {
		return somaTotal;
	}
}

//OK
void Exercicio9(void){
	int numero, naturais = 1;
	printf("Digite um numero: \n");
	scanf("%d", &numero);
	ImprimeNaturais(numero, naturais);
}

int ImprimeNaturais(int n, int naturais){
	int x;
	if(n < 1) return x;
	else{
		printf("Naturais: %20d \n", naturais);
		naturais+=1;
		ImprimeNaturais(n - 1, naturais);
		return x;
	}
}
//NOT OK
void Exercicio10(void){

}