#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 80
FILE *arq;

struct funcionario
{
 int nrmatricula;
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
  if (Tab[Meio].nrmatricula < matricula){

   return(PesquisaBinariaRec(Tab,Meio + 1,Fim,matricula));
 }

 if(Tab[Meio].nrmatricula > matricula){
   return(PesquisaBinariaRec(Tab,Inicio,Meio-1,matricula));
 } 
  // Se não maior nem menor então só pode ser igual. Devolve…

 return Meio; 
} // Fim da função


  
void insertionSort(struct funcionario *Tab, int n)  
{  
  int i, j, key; 
  for (i = 0; i < n; i++) 
  {  
    key = Tab[i].nrmatricula;  
    //printf("Tab.nrmatricula[j] = %d \n", *Tab[i].nrmatricula);
    j = i - 1;  

        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
    while (j >= 0 && Tab[j].nrmatricula > key) 
    {  
      Tab[j+1].nrmatricula = Tab[j].nrmatricula;  
      j -= 1;  
    }  
    Tab[j+1].nrmatricula = key;  
  }  
}  

int main()
{

  struct funcionario vetorfuncionario[MAX];
  int indice;
  int i;
  char sfuncionario[MAX];

  int matricula;    
  char *nome, *salario;

  
  arq = fopen("func1.txt","r");
  if (arq == NULL)
  {
    printf("Erro ao abrir arquivo\n");
    return 0; 
  }
  printf("\n");
  printf("MATRICULA |         NOME         |  SALARIO  \n");
  printf("----------+----------------------+---------\n");
  
  // lê a primeira linha do arquivo
  // buf recebe a string, max é o tamanho máximo de 
  //leitura e arq é o ponteiro para FILE)  
  fgets(sfuncionario,MAX,arq);  
  int qt=0;
  while (!feof(arq))
  { 
  // strtok: permite "quebrar" a string em várias (substring).
    matricula  = atoi(strtok(sfuncionario,";"));    
    nome  = (char *) strtok(NULL,";");    
    salario = (char *) strtok(NULL,";");
    
	vetorfuncionario[qt].nrmatricula=matricula;
	strcpy(vetorfuncionario[qt].nome,nome);
	vetorfuncionario[qt].salario = atof(salario);

	qt++;
    fgets(sfuncionario,MAX,arq);
  }
  

  fclose(arq); 
  
  insertionSort(vetorfuncionario,qt);

  for (i=0;i<qt;i++){
	   printf("\n  %d\t|   %s\t|   %.2f\t",vetorfuncionario[i].nrmatricula, vetorfuncionario[i].nome, vetorfuncionario[i].salario);
   }
    printf("\nPesquisa  --> Informe o numero da matricula: ");
    scanf("%i", &matricula);


    indice = PesquisaBinariaRec(vetorfuncionario, 0, qt-1, matricula);
  //ordena(vetorfuncionario);
    printf("Indice: %d \n", indice);
    /* code */
    
    printf("Nr matric: %d\nSalario: %.2f\nNome: %s\n\n",matricula, vetorfuncionario[indice].salario, vetorfuncionario[indice].nome);
    printf("A professora Cristiane é brilhante!!! \n");

  return 0;
}

