#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

struct funcionario
{
 int nrmatricula[10];
 char nome[40];
 float salario;
};

int PesquisaBinariaRec(struct funcionario *Tab, int Inicio, int Fim, int matricula)
{

  int Meio;
  if(Inicio>Fim) // A tabela não tem elementos (Inicio>Fim)?
    return -1; // Nesse caso o valor não foi encontnrmatriculado (devolve -1)
  Meio = (Inicio + Fim) / 2; // Calcula o índice do elemento do meio
  // O valor é maior então procura na sub-tabela à direita
  if (*Tab[Meio].nrmatricula < matricula){

   return(PesquisaBinariaRec(Tab,Meio + 1,Fim,matricula));
 }

 if(*Tab[Meio].nrmatricula > matricula){
   return(PesquisaBinariaRec(Tab,Inicio,Meio-1,matricula));
 } 
  // Se não maior nem menor então só pode ser igual. Devolve…

 return Meio; 
} // Fim da função


void insertionSort(struct funcionario *Tab)  
{  
  int i, j, key; 
  for (i = 0; i < 3; i++) 
  {  
    key = *Tab[i].nrmatricula;  
    printf("Tab.nrmatricula[j] = %d \n", *Tab[i].nrmatricula);
    j = i - 1;  

        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
    while (j >= 0 && *Tab[j].nrmatricula > key) 
    {  
      *Tab[j+1].nrmatricula = *Tab[j].nrmatricula;  
      j -= 1;  
    }  
    *Tab[j+1].nrmatricula = key;  
  }  
}  

int main()
{

  struct funcionario vetorfuncionario[10];
  int matricula, indice;
  char *pnome;
  float *psalario;

  int *matric;
  int i;

  for (i=0;i<3;i++)
  {
    printf("Informe nome: ");
    scanf("%s",vetorfuncionario[i].nome);

    printf("Informe numero da matricula: ");
    scanf("%d",&vetorfuncionario[i].nrmatricula);

    printf("Informe salario: ");
    scanf("%f",&vetorfuncionario[i].salario);
    printf("________________________________________________________\n");
  }

  insertionSort(vetorfuncionario);

  while(matricula != 9) {
    printf("Pesquisa  --> Informe o numero da matricula: ");
    scanf("%i", &matricula);

    indice = PesquisaBinariaRec(vetorfuncionario, 0, 2, matricula);
  //ordena(vetorfuncionario);
    printf("Indice: %d \n", indice);
    /* code */
    for (int i = 0; i < 10; ++i)
    {
      if (i == indice)
      {
        printf("Nr matric: %d\nSalario: %.2f\nNome: %s\n\n",matricula, vetorfuncionario[i].salario, vetorfuncionario[i].nome);
      }

    }
  }
  return 0;
}

