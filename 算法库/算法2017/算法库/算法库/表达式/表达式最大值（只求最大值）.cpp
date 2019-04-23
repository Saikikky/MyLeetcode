/*问题描述（南阳理工网站题目  表达式最大值） 
　　题目很简单，给出n个数字，不改变它们的相对位置，在中间加入k个乘号和n-n-1个加号，
   （括号随便加）使最终结果尽量大。因为乘号和加号一共就是n-1个了，所以恰好每两个相邻
   数字之间都有一个符号。例如：
　　n=5，k=2，5个数字分别为1、2、3、4、5，可以加成：
　　1*2*(3+4+5)=24
　　1*(2+3)*(4+5)=45
　　(1*2+3)*(4+5)=45
　　……

解：分析如下， 
所有加括号的表达式，其形式肯定为如下 
(a[i]x[i]...  a[m]) x[m] (a[m+1]x[m+1]...a[j])
//a[]是操作数,x[]是运算符
// i<= m <j

x[m]有2种情况：+ 或  *
(1)x[m]是+时，那么穷举"在左半部分用s个*，右半部分用t-s个*"的所有情况 
(2)x[m]是*时，那么穷举"在左半部分用s个*，右半部分用t-1-s个*"的所有情况
穷举所有情况中的最大值即可。

f(i,j,k)表示a[i]...a[j]这些操作数中间加入k个乘法 j-i-k个加法，
能构成的表达式最大值，调用f(1,n,k)即可【或操作数存于a[0~n-1]时，调用f(0,n-1,k)】。
其递推关系式为：
            负无穷大                     j-i<k   //运算符个数<t，属于参数异常的情况 
            a[i]*...*a[j]                j-i==k  //全部是乘法
f(i,j,k)={  a[i]+...+a[j]                k==0    //全部是加法 
                                         
										 m∈[i,j-1],且满足 
            max{f(i,m,s)+f(m+1,j,k-s)，  s<=m-i && k-s<=j-(m+1)
                f(i,m,s)*f(m+1,j,k-1-s)} s<=m-i && k-1-s<=j-(m+1)
按此式写dp程序如下： 
*/ 

#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>

long long int max(long long int x, long long int y)
{
	return x > y ? x : y;
}

long long int tag[15][15][15];

long long int a[20];

long long int f(int i, int j, int k)//递归型dp 
{
	if (k < 0) return 1LL << 63;
	if (tag[i][j][k] != -1)  return tag[i][j][k];//已经计算过 
	if (k == 0)//全是加 
	{
		long long int sum = 0; 
		for (int count = i; count <= j; count++)
		{
			sum += a[count];
		}
		return tag[i][j][k] = sum;
	}
	else if (k == j - i)//全是乘 
	{
		long long int sum = 1;
		for (int count = i; count <= j; count++)
		{
			sum *= a[count];
		}
		return tag[i][j][k] = sum;
	}
	else//加、乘  混合 
	{
		long long int Max = 1LL << 63;//long long类型常量 1LL 
		for (int m = i; m < j; m++)
		{
			for (int s = k - j + m; s <= m - i && s <= k; s++)
			{
				if (s < 0 || k-s-1 < 0) continue;//s为左侧*个数，k-s-1为右侧最少*个数 
				
				Max = max(f(i,m,s) + f(m+1,j,k-s), Max);//相加，右侧乘号不减1 
				Max = max(Max,f(i,m, s) * f(m+1,j,k-s-1));//相乘，右侧乘号个数减1				
			}
		}
		return tag[i][j][k] = Max;
	}
}

int main()
{
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		memset(tag, -1, sizeof(tag));//tag[][][]初始化为“未计算”标志，-1也可以改用0x80 
		for (int i = 0; i < n; i++)
		{
			scanf("%d", a + i);
		}
		cout << f(0, n - 1, k) << endl;
	}

	return 0;
}
