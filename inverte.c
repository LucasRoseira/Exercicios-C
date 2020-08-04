#include<stdio.h>

int m, n;

int FUN(int n){
	int x;
	if(n < 1) return 1;
	else{
		x = n* FUN(n - 1);
		m = n - 1;
		return m + x;
	}

	int main(){
		scanf("%d %d, &m, &n");
		printf("%d %d %d \n", m,n, FUN(n));
		return 0;
	}
}