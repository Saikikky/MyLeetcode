#include<stdio.h>

int main()

{
	float a,b,c,d,e;
	scanf("%f",&e);
	d=(e*360/(2*3.1415926535));
	a=(int)d;
	b=int((d-a)*60);
	c=(d-a-b/60)*3600; 
	printf("角的度数%f 角的分数%f 角的秒数%f",a,b,c);
	return 0;
}

