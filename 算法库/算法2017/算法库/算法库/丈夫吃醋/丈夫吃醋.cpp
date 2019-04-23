/*丈夫吃醋问题  夫妻过河问题：有3对夫妻过河，船最多能载2人，条件是任一女子不能在其丈夫不在的情况下与其他男子在一起，
                如何安排三对夫妻过河？  
*/
#include<iostream>
#include<iomanip>
#include<conio.h>
using namespace std;
#define MAX 101
typedef struct ren
{
	int r1;
	int r2;	
} Ren;

int n; // 控制n<=10,人的编号1~2n，且i与n+i是夫妻
Ren X[MAX]; //过河时船上人的编号 
int S[MAX][21];//船最多来回10000次， 船第k次过河后，2n个人的状态存放在S[k][0~2n-1] 
//0,1分别表示左岸、右岸				 
int bestS[MAX][21],Min=100;//最优过河过程,Min层以内的解

int xianjie(int k,int r1,int r2)//r1,r2两人上船，r1为0表示只有r2一个人 
{
	int i,j,c[2]={0}; //c[0~1]分别存左、右侧男人数
		
	if(r1 == 0) //只有r2一人过河	
	{ 
		if(S[k-1][r2]==k%2)  return 0;//r2与船不在同一侧
	}
	else//如果r1,r2两人过河
	{
		if(S[k-1][r1]!=S[k-1][r2]//人r1,r2不在同一侧
		   ||(k%2 == S[k-1][r1])) return 0; //或者与船不在同一侧
		if(r2-r1>=n && r2-r1!=n)  return 0; //两人异性但不是夫妻
	}	
	
	for(i=1;i<=2*n;i++)//状态k-1  ==>  状态k
		S[k][i]=S[k-1][i];
	S[k][r1]= !S[k-1][r1]; //r1的状态变反 
	S[k][r2]= !S[k-1][r2]; //r2的状态变反	
	for(i=1;i<=n;i++) c[S[k][i]]++;//左、右侧男人数统计，S[k][i]=0表示男人i在左侧
	for(i=n+1;i<=2*n;i++)//检查所有女人，看是否出现老公不在身边却有其它男人在同一侧情况
		if(S[k][i]!=S[k][i-n] && c[S[k][i]]) return 0;//S[k][i]=1表示女人i在右侧
	for(i=0;i<k;i++)
	{
		for(j=1;j<=2*n;j++)
			if(S[k][j]!=S[i][j]) break;
			if(j>2*n) return 0;//状态k与前面某状态重复了
	}
	return 1; 	
}				 

int isok(int k)
{
	int i;
	for(i=1;i<=2*n;i++) 
		if(!S[k][i])  return 0; //人i还在左侧
		return 1; 
}

void output(int s[][21],int k)
{
	int i,j,c=0;  static int count=0;
	cout<<"\n\n解"<<++count<<"  次数："<<k;
	for(i=0;i<=k;i++)
	{
		cout<<endl;
		for(j=1;j<=2*n;j++)//输出左岸人编号
			if(!s[i][j]) cout<<j<<",";
		cout<<"<==>";
		for(j=1;j<=2*n;j++)//输出右岸人编号
			if(s[i][j]) cout<<j<<",";
	}
	getch();//输出一个解后暂停
}

void save(int k)
{
	int i,j;
	Min=k;
	for(i=0;i<=k;i++)
		for(j=1;j<=2*n;j++) bestS[i][j]=S[i][j];
}

void f(int k)//船第k次过河 
{
	int i,j;
	if(k-1>Min) return ;//只求100步以内的解
	if(isok(k-1))//如果所有人都在右岸，则输出结果
	{
		if(k-1<Min)  save(k-1);//保存找到的更好解
		if(k-1==Min) output(S,k-1);//Min在动态变化，最后一轮输出即所有最好解
	} 
	else	 
	{	
		for(i=0;i<=2*n;i++)//穷举两人（i,j）过河的所有情况
			for(j=i+1;j<=2*n;j++)//i为0时表示只有j一人过河 
				if(xianjie(k,i,j))
				{
					X[k].r1=i;
					X[k].r2=j;
					f(k+1);	
				}	
	}
} 

int main()
{
	cin>>n; //n对夫妻
	f(1);
	output(bestS,Min);//输出最后存储的一个最优解	
	return 0;
}