#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int codigo;
	float peso;
	char sexo;
} hospede;

typedef struct
{
	hospede pessoa[10];
} hotel;

//1
void maisPesada(int *pfim, char *psexo, int *codigo, float *peso)
{
	if (*pfim==-1)
	{
		printf ("Nao ha pessoas cadastradas.\n\n");
	}
	else
	{
		printf ("Codigo: %d\nPeso: %.2f\nSexo: %c\n\n", *codigo, *peso, *psexo);
    }
}

//2
void menosPesada(int *pfim, char *psexo, int *codigo, float *peso)
{
	if (*pfim==-1)
	{
		printf ("Nao ha pessoas cadastradas.\n\n");
	}
	else
	{
		printf ("Codigo: %d\nPeso: %.2f\nSexo: %c\n\n", *codigo, *peso, *psexo);
	}
}

//3
void mostrarPessoa(hotel *pessoa, int *pfim, int *codigo)
{
	if (*pfim==-1)
	{
		printf ("Nao ha pessoas cadastradas.\n\n");
	}
	else
	{
		int i, indicePessoa=-1;

		for (i=0; i<=*pfim; i++)
		{
			if (pessoa->pessoa[i].codigo==*codigo)
			{
				indicePessoa=i;
				i=*pfim;
			}
		}

		if (indicePessoa==-1)
		{
			printf ("Nao ha pessoa com o codigo procurado.\n\n");
		}
		else
		{
			printf ("Codigo: %d\nPeso: %.2f\nSexo: %c\n\n", *codigo, pessoa->pessoa[indicePessoa].peso, pessoa->pessoa[indicePessoa].sexo);
		}
    }
}

//4
int inserirPessoa(hotel *pessoa, int *pfim)
{
	if (*pfim==9)
	{
		printf ("Nao ha espaco para uma nova pessoa.\n\n");
	}
	else
	{
		int novoCodigo, indicePessoa=0, i;
		float novoPeso;
		char novoSexo;

		printf ("Digite o codigo da nova pessoa: ");
		scanf ("%d", &novoCodigo);

		printf ("Digite o peso da nova pessoa: ");
		scanf ("%f", &novoPeso);

		printf ("Digite o sexo da nova pessoa(M/F): ");
		scanf ("%s", &novoSexo);

        *pfim=*pfim+1;

        for (i=0; i<=*pfim; i++)
        {
            if (pessoa->pessoa[i].peso <= novoPeso)
            {
                indicePessoa = i;
                i = *pfim;
                printf ("\nindice pessoa = %d\n",indicePessoa);
            }
        }

        for (i=*pfim; i>=indicePessoa; i--)
        {
            pessoa->pessoa[i+1].codigo = pessoa->pessoa[i].codigo;
            pessoa->pessoa[i+1].sexo = pessoa->pessoa[i].sexo;
            pessoa->pessoa[i+1].peso = pessoa->pessoa[i].peso;
        }


		pessoa->pessoa[indicePessoa].codigo = novoCodigo;
		pessoa->pessoa[indicePessoa].sexo = novoSexo;
		pessoa->pessoa[indicePessoa].peso = novoPeso;



		printf ("Pessoa cadastrada com sucesso.\n\n");

		return (*pfim);
	}
}

//5
int removerPessoa(hotel *pessoa, int *pfim, int *codigo)
{
	if (*pfim==-1)
	{
		printf ("Nao ha pessoas cadastradas.\n\n");
	}
	else
	{
		int i, indicePessoa=-1;

		for (i=0; i<=*pfim; i++)
		{
			if (*codigo==pessoa->pessoa[i].codigo)
			{
				indicePessoa=i;
				i=*pfim;
			}
		}

		if (indicePessoa==-1)
		{
			printf ("Nao ha pessoa com o código procurado.\n\n");
		}
		else
		{
			pessoa->pessoa[indicePessoa].codigo=-1;

			printf ("Pessoa removida com sucesso.\n\n");

			while (indicePessoa<10)
            {
                pessoa->pessoa[indicePessoa].codigo = pessoa->pessoa[indicePessoa+1].codigo;
                pessoa->pessoa[indicePessoa].peso = pessoa->pessoa[indicePessoa+1].peso;
                pessoa->pessoa[indicePessoa].sexo = pessoa->pessoa[indicePessoa+1].sexo;
                indicePessoa++;
            }

		}
    }
    *pfim=*pfim-1;
    return (*pfim);
}

//6
void numeroPessoas(int *pfim)
{
	if (*pfim==-1)
	{
		printf ("Nao ha pessoas cadastradas.\n\n");
	}
	else
	{
		printf ("Numero de pessoas = %d\n\n", *pfim+1);
	}
}

//7
void listarPessoas(hotel *pessoa, int *pfim)
{

	if (*pfim==-1)
	{
		printf ("Nao ha pessoas cadastradas.\n\n");
	}
	else
	{
		int i;
		for (i=0; i<=*pfim; i++)
		{
			printf ("Codigo: %d\nPeso: %.2f\nSexo: %c\n\n", pessoa->pessoa[i].codigo, pessoa->pessoa[i].peso, pessoa->pessoa[i].sexo);
		}
    }

}

int main()
{
	hotel pessoa;

	printf ("Digite a opcao desejada:\n");
    printf ("1- Mais pesado\n2- Menos pesado\n3- Consultar pessoa\n4- Inserir pessoa\n5- Remover pessoa\n6- Numero de pessoas\n7- Mostrar pessoas\n8- Fim\n");
	int opcao, fim=-1;

	do
    {
        scanf ("%d", &opcao);

        label:

        switch (opcao)
        {
            case 1:
            {
                int *codigo, *pfim;
                char *psexo;
                float *peso;
                psexo = &pessoa.pessoa[0].sexo;
                codigo = &pessoa.pessoa[0].codigo;
                peso = &pessoa.pessoa[0].peso;
                pfim = &fim;

                maisPesada(pfim, psexo, codigo, peso);
                break;
            }

            case 2:
            {
                int *codigo, *pfim;
                float *peso;
                char *psexo;

                psexo = &pessoa.pessoa[fim].sexo;
                codigo = &pessoa.pessoa[fim].codigo;
                peso = &pessoa.pessoa[fim].peso;
                pfim = &fim;

                menosPesada(pfim, psexo, codigo, peso);
                break;
            }

            case 3:
            {
                int cod;

                printf ("Digite o codigo da pessoa procurada: ");
                scanf ("%d", &cod);

                int *codigo, *pfim;
                float *peso;
                char *psexo;
                hotel *ppessoa;

                ppessoa = &pessoa;
                pfim = &fim;
                codigo = &cod;



                mostrarPessoa(ppessoa, pfim, codigo);
                break;
            }

            case 4:
            {
                int *pfim;
                hotel *ppessoa;
                ppessoa = &pessoa;
                pfim = &fim;

                fim = inserirPessoa(ppessoa, pfim);
                break;
            }

            case 5:
            {
                int cod, *pfim, *codigo;
                hotel *ppessoa;

                printf ("Digite o codigo da pessoa procurada: ");
                scanf ("%d", &cod);

                pfim = &fim;
                codigo = &cod;
                ppessoa = &pessoa;

                fim = removerPessoa(ppessoa, pfim, codigo);
                break;
            }

            case 6:
            {
                int *pfim;
                pfim = &fim;

                numeroPessoas(pfim);
                break;
            }

            case 7:
            {
                int *pfim;
                hotel *ppessoa;

                pfim = &fim;
                ppessoa = &pessoa;

                listarPessoas(ppessoa, pfim);
                break;
            }

            case 8:
            {
                printf ("Fim");
                opcao=8;
                break;
            }

            default :
                printf ("ERRO - Opcao invalida\nDigite outra opcao: ");
                scanf ("%d", &opcao);

                goto label;
            }

    } while (opcao!=8);

        return 0;
}
