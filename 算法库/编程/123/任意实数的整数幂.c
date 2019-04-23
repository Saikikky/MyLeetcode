#include<stdio.h>
#include"MyMath.h" 
#include<math.h>

double Power(double x,INTEGER n);

 

int main()

{

     double x,y;

     INTEGER  n;

     printf("底数:");

     scanf(RSF,&x);

     printf("指数:");

     scanf(ISF,&n);
     y=Power(x,n);

     printf("结果:"RSF"\n",y);

     return 0;

}

double Power(double x,INTEGER n)
{
	double y;
if(EQ(x,0))
{
 	 if(GT(n,0))
	{
		y=0;
		
	}
	else
	{
		y=-1;
	}
}
else
{
	if(GE(n,0))
	{
		y=Power(x,n-1)*x;
	}
	else 
	{
		y=1.0/Power(x,n-1)*x;
	}
}

