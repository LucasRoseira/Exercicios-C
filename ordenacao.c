#include <stdio.h>
#include <string.h>

struct funcionario {
   int nrmatricula;
   char nome[21];
   float salario;
};

typedef struct funcionario func;

func f[5];

void mostraMatriz()
{
   int i;
   for (i=0;i<5;i++)
   {
     printf("\nMatricula: %i  --> R$ %.2f",(f+i)->nrmatricula, (f+i)->salario);
	 
   }
}
/* Ordenação bolha (2a. versão) */
void bolha2 (int n, func *v)
{
  int i, j;
  func temp;
  int troca;
  for (i=n-1; i>0; i--) 
  {
    troca = 0;
    for (j=0; j<i; j++)
      if (v[j].nrmatricula > v[j+1].nrmatricula) 
      { /* troca */
        temp = v[j];		
        v[j]= v[j+1];
		v[j+1] = temp;
        troca = 1;
      }
      if (troca == 0) /* nao houve troca */
        return;
   }	
}

void insercao (int tam, func *vetor)
{
    int i,j, y;
	func aux;	
    j=1;
    while (j<=tam-1)
	{
         printf("\n-->%i",j);
		 aux = vetor[j];
         
		 i = j - 1;
         while (  i >= 0 &&  vetor[i].nrmatricula < aux.nrmatricula ) 
         {         
           printf("\ntrocou %i ",vetor[i].nrmatricula);		 		   
		   vetor[i+1] = vetor[i];           
	       i = i - 1;
		   printf("\n                   ");
		   for (y=0;y<tam;y++) printf("%i ",vetor[y].nrmatricula);		 
		 }    
        vetor[i+1] = aux;
        j = j + 1;
		//printf("\n                   ");
		
   }
}

void selecao (int tam, func *vetor)
{
     int minimo, i, j;
	 func aux;
     for (i=0; i<=tam-1;i++)
	 {
         minimo = i;
         // pega indice do menor
         for (j=i+1;j<=tam-1;j++)
		 {
             if ( vetor[j].nrmatricula < vetor[minimo].nrmatricula )
			 {
                 minimo = j;
             }
         }
		 printf("\nIndice do menor: %i",minimo);
         // efetua a troca
		 printf("\ntroca: %i  e %i",vetor[minimo].nrmatricula,vetor[i].nrmatricula);
		 aux = vetor[minimo];
         vetor[minimo] = vetor[i];
         vetor[i] = aux;
     }
 }
 
void carregadados()
{
  
  f[0].nrmatricula=5;
  f[0].salario=2000;
  strcpy(f[0].nome,"Cris");
  f[1].nrmatricula=9;
  f[1].salario=1002;
  strcpy(f[1].nome,"Tiago");
  f[2].nrmatricula=3;
  f[2].salario=2001;
  strcpy(f[2].nome,"Rafael");
  f[3].nrmatricula=7;
  f[3].salario=1004;
  strcpy(f[3].nome,"Bruno");
  f[4].nrmatricula=5;
  f[4].salario=1005;
  strcpy(f[4].nome,"Felipe");
}

int main()
{
    
  int i;
  carregadados();
  bolha2(5,f);  
  printf("\n\nBOLHA");
  mostraMatriz();
   
  carregadados();
  printf("\n\nORIGINAL");
  mostraMatriz();
  printf("\n\nINSERCAO");
  insercao(5,f);    
  mostraMatriz();
  
  carregadados();
  printf("\n\nSELECAO");
  selecao(5,f); 
  
  mostraMatriz();
   
}