#include<stdio.h>

int main()

{
	float a,b,c,d,e;
	scanf("%f",&e);
	d=(e*360/(2*3.1415926535));
	a=(int)d;
	b=int((d-a)*60);
	c=(d-a-b/60)*3600; 
	printf("�ǵĶ���%f �ǵķ���%f �ǵ�����%f",a,b,c);
	return 0;
}

