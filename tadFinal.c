#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Priscila & Lucas Gomes
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

void numeroPessoas(int *pfim);                                      //Quantidade de Pessoas
int removerPessoa(hotel *pessoa, int *pfim, int *codigo);           //Remover Pessoa
int inserirPessoa(hotel *pessoa, int *pfim);                        //Inserir Pessoa
void mostrarPessoa(hotel *pessoa, int *pfim, int *codigo);          //Mostrar Pessoa
void menosPesada(int *pfim, char *psexo, int *codigo, float *peso); //Menos Pesada
void maisPesada(int *pfim, char *psexo, int *codigo, float *peso);  //Mais Pesada
void listarPessoas(hotel *pessoa, int *pfim);                       //Listar pessoas

int main()
{
    setlocale(LC_ALL,"");
    //Váriavel pessoa 
    hotel pessoa;

    label:

    printf ("Escolha uma opção:\n");
    printf ("1 - Mais pesada\n");
    printf ("2 - Menos pesada\n");
    printf ("3 - Consultar uma pessoa\n");
    printf ("4 - Inserir uma pessoa\n");
    printf ("5 - Remover pessoa\n");
    printf ("6 - Quantidade de pessoas\n");
    printf ("7 - Mostrar pessoas\n");
    printf ("8 - Fim\n");
    int opcao, fim=-1;

    do
    {
        scanf ("%d", &opcao);
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

                printf ("Digite o código da pessoa: ");
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

                printf ("Digite o código da pessoa: ");
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
            printf ("ERRO - Opção inválida\n");
            printf("Digite outra opção: ");
            scanf ("%d", &opcao);

            goto label;
        }

    } while (opcao!=8);
    return 0;
}


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
int removerPessoa(hotel *pessoa, int *pfim, int *codigo)
{
    if (*pfim==-1)
        printf ("Não existem pessoas cadastradas!\n\n");
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
            printf ("Não existe pessoa com o código procurado!\n\n");
        }
        else
        {
            pessoa->pessoa[indicePessoa].codigo=-1;

            printf ("Remoção efetivada com sucesso!\n\n");

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
int inserirPessoa(hotel *pessoa, int *pfim)
{
	if (*pfim==9)
		printf ("Não existe espaco para uma nova pessoa.\n\n");
	else
	{
		int novoCodigo, indicePessoa=0, i;
		float novoPeso;
		char novoSexo;

		printf ("Digite o código da nova pessoa: ");
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
                printf ("\níndice pessoa = %d\n",indicePessoa);
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

        printf ("Pessoa cadastrada com sucesso!\n\n");

        return (*pfim);
    }
}
void maisPesada(int *pfim, char *psexo, int *codigo, float *peso)           
{
    if (*pfim==-1)
        printf ("Não existem pessoas cadastradas.\n\n");
    else
    {
        printf("Código: %d\n", *codigo);
        printf("Peso: %.2f\n", *peso);
        printf("Sexo: %c\n\n", *psexo);
    }
}


void numeroPessoas(int *pfim)
{
	if (*pfim==-1)
		printf ("Não exitem pessoas cadastradas!\n\n");
	else
	{
		printf ("Quantidade de pessoas = %d\n\n", *pfim+1);
	}
}

void listarPessoas(hotel *pessoa, int *pfim)
{
	if (*pfim==-1)
		printf ("Não existem pessoas cadastradas.\n\n");
	else
	{
		int i;
		for (i=0; i<=*pfim; i++)
		{
			printf ("Código: %d\n",   pessoa->pessoa[i].codigo);
            printf ("Peso: %.2f\n",   pessoa->pessoa[i].peso);
            printf ("Sexo: %c\n\n",   pessoa->pessoa[i].sexo);
        }
    }
}

void menosPesada(int *pfim, char *psexo, int *codigo, float *peso)
{
    if (*pfim==-1)
        printf ("Não existem pessoas cadastradas.\n\n");
    else
    {
        printf("Código: %d\n", *codigo);
        printf("Peso: %.2f\n", *peso);
        printf("Sexo: %c\n\n",*psexo);
    }
}

