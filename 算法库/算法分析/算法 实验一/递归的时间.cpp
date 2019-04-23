/*斐波那契数列
         1              i==1||i==2
  f(i)={ f(i-1)+f(i-2)  i>2
*/
#include<iostream>
#include<time.h>
using namespace std;

void f( int  n)
{   int i; 
	if(n<0)  return;
	else  for(i=1;i<5;i++) 
	{ 
		f(n-1);     
	}
}

int main(void)
{ 
	int n;
	clock_t  t1,t2;
	for(n=1;n<=18;n++) 	
	{
		t1=clock();
		f(n);
		t2=clock();
		cout<<"\n n="<<n<<"   用时"<<t2-t1<<"毫秒";
	}
	
	return 0;
}
