#include <stdio.h>
#include<string.h> 
#include<ctype.h>
int alg1 (int n)
{
   if (n == 0) return 2;
   else 
    printf("pilha: %15d \n", 2 * alg1 (n - 1));
    return 2 * alg1 (n - 1);
}

int main()
{
    int n = 4;
    printf("TOTAL: %15d ", alg1(n));
    return 0;
}