#include <stdio.h>
#include <stdlib.h>

//9 - Descobrir senha
int main(){
	int senha, i;
	senha = i = 0;

	printf("Descobrir senha \nVoce tem 3 tentivas\n");

	
	for (i = 0; i < 3; ++i)
	{
		printf("Digite a senha: ");
		scanf("%d", &senha);

		if(senha == 926748){
			printf("Acertou !!! \n");
			break;
		}
		else if(senha != 926748 && i <=1)
		{
			printf("Voce errou! Tente novamente.\n");
		}
		else{
			printf("Voce errou! O cartao foi bloqueado\n");
		}
	}

	return 0;
}