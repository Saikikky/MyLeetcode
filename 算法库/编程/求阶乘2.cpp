#include <stdio.h>

int main ()

{
	int a=1,n,sum=1;
	scanf("%d",&n);
      	do
	       {
	      	  sum*=a;
	      	  a++; 
	       }
    	while(a<=n);
	printf("sum=%d",sum);  
	return 0;
} 
