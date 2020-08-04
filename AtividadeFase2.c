#include <stdio.h>
#include <stdlib.h>
#include <math.h>
	/* TAD Hotel*/
/*Priscila Lopes de Oliveira & Lucas gomes roseira*/
void maisPesada(int *ponteiroFIM, char *psexo, int *codigo, float *peso);
void menosPesada(int *ponteiroFIM, char *psexo, int *codigo, float *peso);
void numeroPessoas(int *ponteiroFIM);
void listarPessoas(int *codigo, char *psexo, float *peso, int *ponteiroFIM);
void mostrarPessoa(float *peso, char *psexo, int *ponteiroFIM, int *codigo);

typedef struct
{
	hospede pessoa[10];
} hotel;

hotel pessoa;

int main(){

	typedef struct
	{
		int codigo;
		float peso;
		char sexo;
	} hospede;



	printf ("Digite uma opcao:\n");
	printf ("1 - Mais pesado");
	printf ("2 - Menos pesado\n");
	printf ("6 - Numero de pessoas\n");
	printf ("7 - Mostrar pessoas\n");
	printf ("8 - Fim\n");
	int caso, fim=-1;

	do
	{
		scanf ("%d", &caso);

		switch (caso)
		{
			case 1:
			{
				int *codigo, *ponteiroFIM;
				char *psexo;
				float *peso;
				psexo = &pessoa.pessoa[0].sexo;
				codigo = &pessoa.pessoa[0].codigo;
				peso = &pessoa.pessoa[0].peso;
				ponteiroFIM = &fim;

				maisPesada(ponteiroFIM, psexo, codigo, peso);
				break;
			}

			case 2:
			{
				int *codigo, *ponteiroFIM;
				float *peso;
				char *psexo;

				psexo = &pessoa.pessoa[fim].sexo;
				codigo = &pessoa.pessoa[fim].codigo;
				peso = &pessoa.pessoa[fim].peso;
				ponteiroFIM = &fim;

				menosPesada(ponteiroFIM, psexo, codigo, peso);
				break;
			}
			case 6:
			{
				int *ponteiroFIM;
				ponteiroFIM = &fim;

				numeroPessoas(ponteiroFIM);
				break;
			}

			case 7:
			{
				int *ponteiroFIM, *codigo;
				float *peso;
				char *psexo;

				ponteiroFIM = &fim;

				listarPessoas(codigo, psexo, peso, ponteiroFIM);
				break;
			}

			case 8:
			{
				printf ("Fim");
				caso=8;
				break;
			}

			default :
			printf ("ERRO - caso invalida\nDigite outro caso: ");
			scanf ("%d", &caso);
		}

	} while (caso!=8);

	return 0;
}

void maisPesada(int *ponteiroFIM, char *psexo, int *codigo, float *peso)
{
	if (*ponteiroFIM==-1)
	{
		printf ("Nao ha pessoas cadastradas.\n\n");
	}
	else
	{
		printf ("Codigo: %10d\nPeso: %10.2f\nSexo: %10c\n\n", *codigo, *peso, *psexo);
	}
}

void menosPesada(int *ponteiroFIM, char *psexo, int *codigo, float *peso)
{
	if (*ponteiroFIM==-1)
	{
		printf ("Nao ha pessoas cadastradas.\n\n");
	}
	else
	{
		printf ("Codigo: %10d\nPeso: %10.2f\nSexo: %10c\n\n", *codigo, *peso, *psexo);
	}
}


void mostrarPessoa(float *peso, char *psexo, int *ponteiroFIM, int *codigo)
{
	if (*ponteiroFIM==-1)
	{
		printf ("Nao ha pessoas cadastradas.\n\n");
	}
	else
	{
		int i, indicePessoa=-1;

		for (i=0; i<=*ponteiroFIM; i++)
		{
			if (codigo[i]==*codigo)
			{
				indicePessoa=i;
				i=*ponteiroFIM;
			}
		}

		if (indicePessoa==-1)
		{
			printf ("Codigo invalido\n\n");
		}
		else
		{
			printf ("Codigo: %10d\nPeso: %.2f \nSexo: %10c\n\n", *codigo, *peso, *psexo);
		}
	}
}

void numeroPessoas(int *ponteiroFIM)
{
	if (*ponteiroFIM==-1)
	{
		printf ("Nao existem cadastros\n\n");
	}
	else
	{
		printf ("Quantidade de pessoas = %d\n\n", *ponteiroFIM+1);
	}
}


void listarPessoas(int *codigo, char *psexo, float *peso, int *ponteiroFIM)
{
	if (*ponteiroFIM==-1)
	{
		printf ("Nao existem cadastros\n\n");
	}
	else
	{
		for (int i=0; i<=*ponteiroFIM; i++)
		{
			printf ("Codigo: %10d\nPeso: %10.2f\nSexo: %10c\n\n", *codigo, *peso++, *psexo);
		}
	}
}
