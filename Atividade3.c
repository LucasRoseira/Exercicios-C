#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

struct regLista
{
	int valor;
	struct regLista *prox;
};

struct regLista *adicionar(struct regLista *inicio)
{
	setlocale(LC_ALL,"");
	struct regLista *ant;
	int numero, t = 1;

	while(1)
	{
		if( t == 1){
			printf("Digite um valor negativo para parar de adicionar!!!\n");
			t++;
		}
		printf ("Informe um número: ");
		scanf ("%d", &numero);

		if (numero<0) {
			break;
		}

		struct regLista *aux=(struct regLista*) malloc(sizeof(struct regLista));

		aux->valor=numero;
		aux->prox=NULL;

		if(inicio==NULL){
			inicio=aux;
		}
		else{
			ant->prox=aux;
		}

		ant=aux;
	}
	return inicio;
}

void imprimir(struct regLista *inicio)
{
	printf("Conteúdo da lista:\n");
	struct regLista *aux=inicio;

	while (aux!=NULL)
	{
		printf("%10d\n", aux->valor);
		aux=aux->prox;
	}
}

struct regLista *remover(struct regLista *inicio)
{
	struct regLista *aux=inicio->prox;
	free(inicio);
	inicio=aux;
	return inicio;
}

int main()
{
	int opcao;
	struct regLista *inicio;
	inicio=NULL;

	do
	{
		printf ("\nSelecione uma opção:");
		label1:
		printf ("\n1- Inserir um nó de informação\n2- Remover um nó de informação\n3- Imprimir todos os nós\n4- Fim do programa\n");
		scanf ("%i", &opcao);

		switch (opcao)
		{
			case 1:
			{
				setbuf (stdin, NULL);
				inicio=adicionar(inicio);
				break;
			}

			case 2:
			{
				setbuf (stdin, NULL);
				if (inicio!=NULL)
				{
					struct regLista *aux=inicio;
					printf ("Nó %d removido com sucesso!\n", aux->valor);
					inicio=remover(inicio);
				}
				else
				{
					printf ("Não existe nó!\n");
				}
				break;
			}

			case 3:
			{
				setbuf (stdin, NULL);
				if (inicio!=NULL)
				{
					imprimir(inicio);
				}
				else
				{
					printf ("Não existe nó!\n");
				}
				break;
			}

			case 4:
			{
				setbuf (stdin, NULL);
				printf ("Finalizado\n");
				break;
			}

			default:
			{
				setbuf (stdin, NULL);
				printf ("\nOpção invalida, digite outra opção:");
				goto label1;
				break;
			}

		}
	} while (opcao!=4);

	return 0;
}
