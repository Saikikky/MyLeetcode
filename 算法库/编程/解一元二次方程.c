#include <stdio.h>
#include <math.h>
#include "MyMath.h"
int QuadraticEquation(double *x1,double *x2,double a,double b,double c);
int main()
{
	int r;
	REAL a,b,c,x1,x2;
	puts("һԪ���η��� ax2+bx+c=0");
	printf("a,b,c=?");
	scanf(RSF RSF RSF,&a,&b,&c);
	r = QuadraticEquation(&x1,&x2,a,b,c);
	if(0==r)
	{
		puts("�޽�"); 
	}
	else if(-1==r)
	{
		printf("Ψһ�⣺x="RPF"\n",x1);
	}
	else if(-2==r)
	{
		puts("������");
	}
	else if(1==r)
	{
		printf("������ȵ�ʵ����x1=x2="RPF"\n",x1); 
	}
	else if(2==r)
	{
		printf("�������ȵ�ʵ����x1="RPF",x2="RPF"\n",x1,x2);
	}
	else if(3==r)
	{
		printf("��������������x1="RPF"+"RPF"i,x2="RPF"-"RPF"i\n",x1,x2,x1,x2);
	}
	else 
	{
		puts("�쳣"); 
	}
	return 0;
}
int QuadraticEquation(double *x1,double *x2,double a,double b,double c)
{
	int y;
	double delta,p,q;
	p=-b/(2*a);
	delta=b*b-4*a*c;
	if(fabs(a)<=epsilon)
	{
		if(fabs(b)<=epsilon&&fabs(c)>epsilon)
	    {
        	y=0;
        }
	    else if(fabs(b)<=epsilon&&fabs(c)<=epsilon)
	    {
	       	y=-2;
        }
      	else 
	    {
	    	y=-1;
		   *x1=-c/b;
        }
	} 
	else
	{
		if(fabs(delta)<=epsilon)
		{
		  y==1;
		  *x1=p;
		  *x2=*x1;	
		}
		else if(fabs(delta)>=epsilon)
		{
			q=sqrt(delta)/(2*a);
			y=2;
			*x1=p+q;
			*x2=p-q;
		}
		else
		{
			q=fabs(sqrt(-delta))/(2*a);
			y=3;
			*x1=p;
			*x2=q; 
		}
    } 
		return y; 
}
