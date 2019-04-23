#include <stdio.h>

int main()

{
	int a,n;
	double sum=0.0;
	scanf("%d",&n);
	 for(a=1;a<=n;a++)
	  {
	  	sum+=1.0/a;
	  }
	  printf("sum=%g",sum);
	return 0;
}
