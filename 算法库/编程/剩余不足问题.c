#include <stdio.h>
int SurplusShortage(int *x,int *y,int a,int b,int c,int d);
int main()
{
	int a,b,c,d,x,y;
	printf("a,b=?");
	scanf("%d%d",&a,&b);
	printf("c,d=?");
	scanf("%d%d",&c,&d);
	if(SurplusShortage(&x,&y,a,b,c,d))
	{
		printf("x=%d\n",x);
		printf("y=%d\n",y);
	}
	else
	{
		puts("нч╫Б\n");
	}
	return 0;
}
int SurplusShortage(int *x,int *y,int a,int b,int c,int d)
{
	double q,p; 
	q=(double)(b+d)/(double)(c-a);
	p=a*q+(double)b;
	if(q==(int)q&&p==(int)p&&q>=0&&p>=0)
	{
		*x=q;
		*y=p; 
		return 1;
	} 
	else
	{
		return 0;
	}
}
