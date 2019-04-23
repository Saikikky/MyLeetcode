#include <stdio.h>

int main()
{
	int n = 0;
	double a,b,c,d,e,f,g,h,i,j;
	printf("大学语文：");
	scanf("%lg",&a); 
	printf("高等数学：");
	scanf("%lg",&b); 
	printf("大学英语：");
	scanf("%lg",&c); 
	printf("大学计算机基础：");
	scanf("%lg",&d); 
	printf("经济学原理：");
	scanf("%lg",&e); 
	printf("统计学：");
	scanf("%lg",&f); 
	printf("金融工程学：");
	scanf("%lg",&g); 
	printf("管理学原理：");
	scanf("%lg",&h); 
	printf("证券投资学：");
	scanf("%lg",&i); 
	printf("社交礼仪：");
	scanf("%lg",&j); 
	if(a >= 60)
	{
		n = n + 4;
	} 
    if(b >= 60)
    {
    	n = n + 8;
    }
    if(c >= 60)
    {
    	n = n + 4;
    }
    if(d >= 60)
    {
    	n = n + 2;
    }
    if(e >= 60)
    {
    	n = n + 4;
    }
    if(f >= 60)
    {
    	n = n + 3;
    }
    if(g >= 60)
    {
    	n = n + 3;
    }
    if(h >= 60)
    {
    	n = n + 2;
    }
    if(i >= 60)
    {
    	n = n + 3;
    }
    if(j >= 60)
    {
    	n = n + 1;
    }
    printf("学分=%d\n",n);
    if(n>=28)
    {
    	printf("毕业"); 
    }
    else
    {
    	printf("肄业"); 
    }
	return 0;
} 
