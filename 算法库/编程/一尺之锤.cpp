#include <stdio.h>
#include <math.h>
int main()

{
	int a,n;
	double s=0.0;
	scanf("%d",&n);
	 for(a=1;a<=n;a++)
	  {
	 	s=1/pow(2,a)+s;
	  }
	printf("%.10g",s);
	return 0;
}
