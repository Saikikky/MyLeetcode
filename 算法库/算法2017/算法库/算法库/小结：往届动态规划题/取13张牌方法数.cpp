/*2015年省赛题
13种面值的扑克牌，每种牌有4种花色，共52张牌，从中拿出13张，一共有多少种可能（不考虑花色）？

 用f(n,k)表示从n种牌中取出k张，有多少方法。则求f(13,13)即可。
             0                k>4n或k<0   
    f(n,k)={ 1                k=4n或k=0 
	         f(n-1,k)+
			 f(n-1,k-1)+
			 f(n-1,k-2)+      0<k<4n   
			 f(n-1,k-3)+
			 f(n-1,k-4)
*/
#include<iostream>
using namespace std;
int F[100][100];//F[i][j]与上面递推式中
                //f(i,j)对应

int f(int n,int k)
{
	if(F[n][k])          return F[n][k];
	if(k>4*n || k<0)     return 0;
	else if(k==4*n||k==0)return F[n][k]=1;
	else return F[n][k]=f(n-1,k)+
		                f(n-1,k-1)+
						f(n-1,k-2)+
						f(n-1,k-3)+
						f(n-1,k-4);
}

int main()
{	
	int k=13;
	cout<<endl<<k<<":"<<f(13,13)<<endl;//从13种牌中拿13张有多少种方法
    //测试其它值
	for(k=0;k<=52;k++)
		cout<<endl<<k<<":"<<f(13,k);//从13种牌中拿k张有多少种方法
	return 0;
}