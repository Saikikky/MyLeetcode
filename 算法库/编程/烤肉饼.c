#include <stdio.h>

int main ()
{
	int a;
	printf("肉饼的数量=");
	scanf("%d",&a);
	if(a==1)
	{
		printf("需要两分钟\n");
	}
	else
	{
		printf("需要时间=%d",a); 
	} 
	return 0;
}
