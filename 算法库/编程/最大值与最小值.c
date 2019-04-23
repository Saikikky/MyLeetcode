#include <stdio.h>
int Max3(int x,int y,int z);
int Min3(int x,int y,int z);
int main()
{
	int a,b,c,p,q;
	printf("三个整数：");
	scanf("%d%d%d",&a,&b,&c);
	p = Max3(a,b,c);
	q = Min3(a,b,c);
	printf("最大值:%d\n",p);
	printf("最小值:%d\n",q);
	return 0;
}
int Max3(int x,int y,int z)
{
	 int d;
	 d=x>=y?x:y;
	 d=d>=z?d:z;
	 return d;
}
int Min3(int x,int y,int z)
{
	 int d;
	 d=x<=y?x:y;
	 d=d<=z?d:z;
	 return d;
}
