#include <stdio.h>
double Cash(double value);
int main()
{
	double value,money;
	printf("购物金额:");
	scanf("%lg",&value);
	money = Cash(value);
	printf("付款金额:%.2f",money);
	return 0;
}
double Cash(double value)
{
	if(value < 100)
	{
		return value;
	}
	else if(value >= 100&&value < 200)
	{
		return 0.95*value;
	}
	else if(value >= 200&&value < 500)
	{
		return 0.9*value;
	}
	else if(value >= 500&&value <1000)
	{
		return 0.85*value;
	}
	else
	{
		return 0.8*value;
	}
}
