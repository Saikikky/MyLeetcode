//测试递归函数的深度问题
#include<iostream>
using namespace std;

void f(int n)
{
	int a[50]; //int *a=new int[50];
	if(n>0) f(n-1);
	//delete a;
}
int main( )
{  
	int i;
	for(i=1;i<100000;i++)
	{
		cout<<i<<endl;
		f(i);
	}
}
