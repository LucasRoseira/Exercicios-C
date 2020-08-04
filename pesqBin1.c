#include <stdio.h>

int PesquisaBinariaRec(int *Tab, int Inicio, int Fim, int Valor)
{
  int Meio;
  printf("\nInicio: %i e Fim: %i",Inicio, Fim);
  if(Inicio>Fim) 
    return -1; // Nesse caso o valor n�o foi encontrado (devolve -1)
  Meio = (Inicio + Fim) / 2; // Calcula o �ndice do elemento do meio
  printf(" Meio: %i->%i",Meio,Tab[Meio]);
  // O valor � maior ent�o procura na sub-tabela � direita  
	//if (strcmp(Tab[Meio].nome, Valor) > 0)
  if(Valor>Tab[Meio]) 
     return(PesquisaBinariaRec(Tab,Meio + 1,Fim,Valor));
  // O valor � menor ent�o procura na sub-tabela � esquerda
					
	if(Valor<Tab[Meio]) 				  
    return(PesquisaBinariaRec(Tab,Inicio,Meio-1,Valor));
	
  // Se n�o maior nem menor ent�o s� pode ser igual. Devolve�
  return Meio; 
} // Fim da fun��o


int main()
{
   int achou;
 
   int vet[16]={1,2,3,5,12,14,15,21,24,45,46,47,53,86,90,98};
   
   achou=PesquisaBinariaRec(vet, 0, 15, 10);
   if (achou!=-1)
     printf("\nAchou");
   else
     printf("\nNao achou");
   return 0; 	 
}