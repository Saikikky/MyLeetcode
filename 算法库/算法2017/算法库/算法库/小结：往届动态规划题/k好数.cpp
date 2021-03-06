/*问题描述[动态规划算法]
如果一个自然数N的K进制表示中任意的相邻的两位都不是相邻的数字，那么我们就说这个数是K好数。
求L位K进制数中K好数的数目。例如K = 4，L = 2的时候，所有K好数为11、13、20、22、30、31、33 共7个。
由于这个数目很大，请你输出它对1000000007取模后的值。
输入格式
输入包含两个正整数，K和L。
输出格式
输出一个整数，表示答案对1000000007取模后的值。
样例输入
4 2
样例输出
7
数据规模与约定
对于30%的数据，KL <= 106；
对于50%的数据，K <= 16， L <= 10；
对于100%的数据，1 <= K,L <= 100。

用f(i,L)表示以i开头的L位k进制好数个数则有
         0                    i<0||i>=k
f(i,L)={ 1                    L=1       
         (∑f(t,L-1))%M       L>1,其中t∈{0,1,2,...,k-1}且不等于i-1或i+1
*/

#include<iostream>
#define M 1000000007
using namespace std;

int k,L,a[100][100]={0};//a[i][L]与f(i,L)对应
int f(int i,int L1)
{
	int t,s=0;
	if(i<0 || i>=k) return 0;//由于调用时控制住了形参范围，不会碰到这种值，所以此语句可以去掉

	if(a[i][L1])    return a[i][L1];//已经计算过，直接返回
	if(L1==1)       return a[i][L1]=1;
	for(t=0;t<k;t++)
	  if(t!=i-1 && t!=i+1) s=(s+f(t,L1-1))%M;
	return a[i][L1]=s;
}

int main()
{
	int s=0,i;
	cin>>k>>L;
	for(i=1;i<k;i++)
		s=(s+f(i,L))%M;
	cout<<s<<endl;
	return 0;
}