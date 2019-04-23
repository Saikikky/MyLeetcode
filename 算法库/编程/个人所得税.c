#include <stdio.h>
double Tax(double income,double threshold);
int main()
{
	double income,threshold,taxability;
	printf("月收入:");
	scanf("%lg",&income);
	printf("起征点:");
	scanf("%lg",&threshold);
	taxability=Tax(income,threshold);
	printf("应缴税:%.2f",taxability); 
	return 0;
}
double Tax(double income,double threshold)
{
	double taxability;
	if(income<=threshold)
	{
		return 0;
	}
	else if(income<=threshold+1500)
	{
		taxability=(income-1500)*0.03;
	}
	else if(income<=threshold+4500)
	{
		taxability=1500*0.03+(income-threshold-1500)*0.1;
	}
	else if(income<=threshold+9000)
	{
		taxability=1500*0.03+3000*0.1+(income-threshold-4500)*0.2;
	}
	else if(income<=35000+threshold)
	{
		taxability=1500*0.03+3000*0.1+4500*0.2+(income-threshold-9000)*0.25;
	}
	else if(income<=threshold+55000)
	{
		taxability=1500*0.03+3000*0.1+4500*0.2+26000*0.25+(income-threshold-35000)*0.3;
	}
	else if(income<=threshold+80000)
	{
		taxability=1500*0.03+3000*0.1+4500*0.2+20000*0.3+(income-threshold-55000)+0.35;
	}
	else 
	{
		taxability=1500*0.03+3000*0.1+4500*0.2+20000*0.3+25000*0.35+(income-threshold-80000)*0.45;
	}
	return taxability;
}
