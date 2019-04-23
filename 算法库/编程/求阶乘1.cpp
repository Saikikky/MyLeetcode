#include <stdio.h>

int main()

{
	int a,n,sum=1;
	scanf("%d",&n);
	for(a=1;a<=n;a++)
	  {
	  	sum*=a;
	  } 
	printf("sum=%d",sum);  
	return 0;
} 
