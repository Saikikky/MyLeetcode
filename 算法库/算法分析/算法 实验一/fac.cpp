/*斐波那契数列
         1              i==1||i==2
  f(i)={ f(i-1)+f(i-2)  i>2
*/
#include<iostream>
using namespace std;
#define MAX 100000

int F[MAX]; //F[i]存储f(i)的值，初始值0
int a[MAX]; //a[i]存储f(i)被重复计算次数

int f(int i)//纯递归写法
{
	if(i<1) return -1;
	a[i]++;
	if(i==1 || i==2) return 1;
	else return f(i-1)+f(i-2);
}

int dp1(int i)//递归型的动态规划写法
{
	if(F[i]) return F[i];//如果F[i]已经计算过（标志即非0），则函数直接返回
	a[i]++;  //上面if()不成立时，a[i]++才会执行。
	if(i==1 || i==2) return F[i]=1;
	else             return F[i]=dp1(i-1)+dp1(i-2);
}

int main(void)
{ 
	int i,n;
	cout<<"Enter n(<100):";
	cin>>n;
	
	cout<<"f(n)="<<f(n)<<endl;
	for(i=n ;i>0 ;i--) 
		cout<<"a["<<i<<"]="<<a[i] <<endl;
	//还可以测试 for(i=1;i<=n;i++) cout<<"f(n)="<<f(n)<<endl; 
	//可以发现，当n达到43以上，程序需要时间会明显感觉越来越长，说明纯递归写法效率低，原因就是f(i)被多次重复计算
	
	for(i=n ;i>0 ;i--) 	a[i]=0;//清零，准备执行dp1函数，
	cout<<"\nf(n)="<<dp1(n)<<endl;
	for(i=n ;i>0 ;i--) //再次查看f(i)被计算次数
		cout<<"a["<<i<<"]="<<a[i] <<endl;

	return 0;
}
