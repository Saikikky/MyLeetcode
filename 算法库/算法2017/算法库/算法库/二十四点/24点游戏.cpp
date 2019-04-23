#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int shu[4];
int biaoji[4];//避免了相同数字
int t[8];//
int tt[100][8];
int geshu;
int ff = 1;
double count;
void f(int i);
void Output();
int jianzhi(int k, int i);
void qjisuan(int i);

int main()
{
	srand(time(NULL));
	shu[0] = rand() %13 + 1;
	shu[1] = rand() %13 + 1;
	shu[2] = rand() %13 + 1;
	shu[3] = rand() %13 + 1;
	f(1);
	if (ff)
	{
		printf("%d %d %d %d这4个数不能凑成\n", shu[0], shu[1], shu[2], shu[3]);
	}
	return 0;
}

void f(int i)
{
	double temp;
	if (i > 4 && fabs(count - 24) < 0.000001)
	{
		Output();
	}
	else if (i <= 4)
	{
		for (int k = 1; k <= 4; ++k)//为了不重复 *除+-
		{
			for (int j = 1; j <= 4; j++)
			{
				if (jianzhi(k,i))
				{
					temp = count;
					biaoji[k-1] = 1;
					t[2*i-1] = shu[k-1];
					t[2*i - 2] = j;					
					qjisuan(i);
					f(i+1);  ////////////				
				//	hjisuan(i);
					count = temp;
					biaoji[k-1] = 0;
				}
			}
		}
	}
}


void Output()
{
	int n, m, flag;
	for (n = 0; n < geshu; ++n)
	{
		flag = 1;
		for (m = 1; m < 8 && flag; ++m)
		{
			if (tt[n][m] != t[m])
			{
				flag = 0;
			}
		}
		if (flag && m==8)
		{
			return;
		}
	}
	for (m = 1; m < 8; ++m)
	{
		tt[geshu][m] = t[m];
	}
	geshu++;
	ff = 0;
	printf("(((%d", t[1]);
	for (int k = 2; k < 8; ++k)
	{
		if (k%2)
		{
			printf("%d)", t[k]);
		}
		else
		{
			switch(t[k])
			{
			case 1:
				printf(" * ");
				break;
				case 2:
				printf(" / ");
				break;
				case 3:
				printf(" + ");
				break;
				case 4:
				printf(" - ");
				break;
			}
		}
	}
	printf("\n");
}

int jianzhi(int k, int i)//可以不作为一个函数
{
	return biaoji[k-1] == 0;
}

void qjisuan(int i)
{
	if (i == 1)
	{
		count = t[1];
	}
	else
	{
		switch(t[2*i-2])
		{
		case 1:
			count *= t[2*i-1];
			break;
			case 2:
			count /= t[2*i-1];
			break;
			case 3:
			count += t[2*i-1];
			break;
			case 4:
			count -= t[2*i-1];
			break;
		}
	}
}
