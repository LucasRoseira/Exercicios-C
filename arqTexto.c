#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 80
FILE *arq;

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

void mostraFuncionario()
{
  int matricula;    
  char *nome, *salario;
  char sfuncionario[MAX];
  
  arq = fopen("func1.txt","r");
  if (arq == NULL)
  {
    printf("Erro ao abrir arquivo\n");
    return; 
  }
  printf("\n");
  printf("MATRICULA |         NOME         |  SALARIO  \n");
  printf("----------+----------------------+---------\n");
  
  // lê a primeira linha do arquivo
  // buf recebe a string, max é o tamanho máximo de 
  //leitura e arq é o ponteiro para FILE)  
  fgets(sfuncionario,MAX,arq);  
  
  while (!feof(arq))
  { 
  // strtok: permite "quebrar" a string em várias (substring).
    matricula  = atoi(strtok(sfuncionario,";"));    
    nome  = (char *) strtok(NULL,";");    
    salario = (char *) strtok(NULL,";");
  // -15s: alinha à esquerda considerando 15 posições 
    printf("%9d | %-18s | %s \n", matricula,nome,salario);
    fgets(sfuncionario,MAX,arq);
  }
  
  printf("----------+----------------------+---------\n");

  fclose(arq);
}


void insertionSort(struct funcionario *Tab)  
{  
  int i, j, key; 
  for (i = 0; i < 10; i++) 
  {  
    key = *Tab[i].nrmatricula;  
    //printf("Tab.nrmatricula[j] = %d \n", *Tab[i].nrmatricula);
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

  struct funcionario vetorfuncionario[7];
  int matricula, indice;
  int i;
  mostraFuncionario();
  char sfuncionario[MAX];
  
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

