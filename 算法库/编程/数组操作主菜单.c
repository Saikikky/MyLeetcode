#include <stdio.h>
#include "MyMath.h"
#include "MyRArray.h"


INTEGER FindRArray(const REAL array[],INTEGER size, REAL x);//����
void MainMenuRArray(REAL array[],INTEGER size);
//��ʾ���鹦�ܲ˵������û�ѡ���ܶ����ݽ���һϵ�в�����ֱ��ѡ��Qʱ������ 
void ReverseRArray(REAL array[],INTEGER size);//���� 
void InputRArray(REAL array[],INTEGER size);
//����ȫ������Ԫ��
void OutputRArray(REAL array[],INTEGER size);
//���ȫ������Ԫ��
void SortRArray(REAL array[],INTEGER size);//��������
int NE(REAL x, REAL y);
void CopyRArray(REAL dstArray[],const REAL srcArray[],INTEGER size);

int main()
{
	REAL a[maxRArraySize];
	INTEGER n;

	printf("����: ");
	scanf(ISF, &n);
	if (n < 1 || n > maxRArraySize)
	{
		puts("����ȷ������!");
		exit(1);
	}

	MainMenuRArray(a, n);
	return 0;
} 

void InputRArray(REAL array[],INTEGER size)//���� 
{
	int k;
	for(k = 0;k < size;k++)
	{
		scanf("%lg",&array[k]);
	}
}

void OutputRArray(REAL array[],INTEGER size)//��� 
{
	int k;
	for(k = 0;k < size;k++)
	{
		printf(" %g",array[k]);
	}
}

void ReverseRArray(REAL array[],INTEGER size)//���� 
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

void SortRArray(REAL array[],INTEGER size)//������������
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

INTEGER FindRArray(const REAL array[],INTEGER size, REAL x)//����
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
		printf("I-���� O-��� R-���� S-���� F-���� Q-�˳�> _");
		scanf("%c",&c);
		fflush(stdin);
		
		if('I' == c||'i' == c)
		{
			printf("���飺");
			InputRArray(array, size);
		}
		
		else if('O' == c||'o' == c)
		{
			printf("���飺");
			OutputRArray(array, size);
		} 
		else if('R' == c||'r' == c)
		{
			printf("����");
			ReverseRArray(b, size); 
		}
		else if('s' == c||'S' == c)
		{
			printf("����");
			SortRArray(b, size);
		}
		else if('F' == c||'f' == c)
		{
	      	printf("���ң�");
	      	scanf(RSF, &x);
			r = FindRArray(array, size, x);
			if (r)
			{
				puts("���ҳɹ�!");
				printf("���: " IPF "\n", r);
			}
			else
			{
				puts("����ʧ��!");
			}
		}
		else if('Q' == c||'q' == c)
		{
			exit(1);
		}
		else
		{
			printf("����ȷ��ѡ�");
		}
		putchar('\n');
	} 
	while(c);
} 

void CopyRArray(REAL dstArray[],const REAL srcArray[],INTEGER size)//��ֵ�����ƣ� 
{
	int k;
	for(k = 0;k < size;k++)
	{
		dstArray[k] = srcArray[k];
	} 
}
