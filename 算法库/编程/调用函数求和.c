#include <stdio.h>
#include <math.h>
int Sqr(int n);
int Sum(int n);
int SumSqr(int n);
int SumCube(int n);

int main()
{
	int n;
	printf("n = ? ");
	scanf("%d", &n);
	printf("������ = %d\n",Sum(n));
	printf("ƽ���� = %d\n",SumSqr(n));
    printf("������ = %d\n",SumCube(n));
	return 0;
}

int Sqr(int n)
{
	return n*n   ;
}

int Sum(int n)
{
	return  (1+n)*n/2    ;
}

int SumSqr(int n)
{
	return (n*(n+1)*(2*n+1))/6;     
}

int SumCube(int n)
{
	return  n*n*(n+1)*(n+1)/4    ;
}

