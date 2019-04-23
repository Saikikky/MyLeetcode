#include <stdio.h>

int main()

{
	int a=1,n,sum=1;
	scanf("%d",&n);
	while (a<=n)
	  {
	  	sum*=a;
	  	a++;
	  }
   printf("sum=%d",sum);
	return 0;
}
