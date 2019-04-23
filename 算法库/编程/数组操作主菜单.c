#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"


INTEGER FindRArray(const REAL array[],INTEGER size, REAL x);//查找
void MainMenuRArray(REAL array[],INTEGER size);
//显示数组功能菜单，供用户选择功能对数据进行一系列操作，直到选择Q时结束。 
void ReverseRArray(REAL array[],INTEGER size);//逆置 
void InputRArray(REAL array[],INTEGER size);
//输入全部数组元素
void OutputRArray(REAL array[],INTEGER size);
//输出全部数组元素
void SortRArray(REAL array[],INTEGER size);//排序（升序）
int NE(REAL x, REAL y);
void CopyRArray(REAL dstArray[],const REAL srcArray[],INTEGER size);

int main()
{
	REAL a[maxRArraySize];
	INTEGER n;

	printf("项数: ");
	scanf(ISF, &n);
	if (n < 1 || n > maxRArraySize)
	{
		puts("不正确的项数!");
		exit(1);
	}

	MainMenuRArray(a, n);
	return 0;
} 

void InputRArray(REAL array[],INTEGER size)//输入 
{
	int k;
	for(k = 0;k < size;k++)
	{
		scanf("%lg",&array[k]);
	}
}

void OutputRArray(REAL array[],INTEGER size)//输出 
{
	int k;
	for(k = 0;k < size;k++)
	{
		printf(" %g",array[k]);
	}
}

void ReverseRArray(REAL array[],INTEGER size)//逆置 
{
	REAL c[maxRArraySize];
	int k,i = size - 1;
	CopyRArray(c, array, size);
	for(k = 0;k < size;k++)
	{
		array[i] = c[k];
		i--;
	}
}

void SortRArray(REAL array[],INTEGER size)//插入排序（升序）
{
	REAL x;
	int i,j;
	for(i = 1;i < size;i++)
	{
		if(array[i] < array[i - 1])
		{
			x = array[i];
			for(j = i - 1;j >= 0 && array[j] > x;j--)
			{
				array[j + 1] = array[j];
			}
			array[j + 1] = x;
		}
	}
}

INTEGER FindRArray(const REAL array[],INTEGER size, REAL x)//查找
 {
 	INTEGER k = 0,q;
 	while(NE(array[k],x) && k <= size)
 	{
 		k++;
 		q = k + 1;
 	}
 	if(k = size)
 	{
 		q = 0;
 	}
 	return q;
 } 
 
 int NE(REAL x,REAL y)
{
	return fabs(x-y)>epsilon;
}

void MainMenuRArray(REAL array[],INTEGER size)
{
	char c;
	REAL b[maxRArraySize];
	INTEGER x,r;
	do
	{
		printf("I-输入 O-输出 R-逆置 S-排序 F-查找 Q-退出> _");
		scanf("%c",&c);
		fflush(stdin);
		
		if('I' == c||'i' == c)
		{
			printf("数组：");
			InputRArray(array, size);
		}
		
		else if('O' == c||'o' == c)
		{
			printf("数组：");
			OutputRArray(array, size);
		} 
		else if('R' == c||'r' == c)
		{
			printf("逆置");
			ReverseRArray(b, size); 
		}
		else if('s' == c||'S' == c)
		{
			printf("排序");
			SortRArray(b, size);
		}
		else if('F' == c||'f' == c)
		{
	      	printf("查找：");
	      	scanf(RSF, &x);
			r = FindRArray(array, size, x);
			if (r)
			{
				puts("查找成功!");
				printf("序号: " IPF "\n", r);
			}
			else
			{
				puts("查找失败!");
			}
		}
		else if('Q' == c||'q' == c)
		{
			exit(1);
		}
		else
		{
			printf("不正确的选项！");
		}
		putchar('\n');
	} 
	while(c);
} 

void CopyRArray(REAL dstArray[],const REAL srcArray[],INTEGER size)//赋值（复制） 
{
	int k;
	for(k = 0;k < size;k++)
	{
		dstArray[k] = srcArray[k];
	} 
}
