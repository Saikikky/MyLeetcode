#include <stdio.h>
#include <stdlib.h>
#include "MyRArray.h"

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


void MainMenuRArray(REAL array[], INTEGER size)
{
	char c;
	REAL x;
	INTEGER r;
	fflush(stdin);
    printf("I-输入 O-输出 D-填数 R-逆置 S-排序 F-查找 T-统计 Q-退出>");
    c = getchar();
	while (c != 'q' && c != 'Q')
	{
		if(c != 'i' && c != 'I' && c != 'o' && c != 'O' && c != 'R' && c != 'r' && c != 'f' && c != 'F' && c != 's' && c != 'S' && c != 'd' && c != 'D' && c != 't' && c != 'T')
		{
			printf("不正确的选项！");
			putchar('\n');
		}
		if(c == 'i' || c == 'I')
		{
			printf("数组：");
			InputRArray(array, size);
		}
		if(c == 'o' || c == 'O')
		{
			printf("数组：");
			OutputRArray(array, size);
			putchar('\n');
		}
		if(c == 'd' || c == 'D')
		{
			FillMenuRArray(array, size);
		}
		if(c == 'r' || c == 'R')
		{
			ReverseRArray(array, size);
			printf("逆置");
			putchar('\n');
		}
		if(c == 's' || c == 'S')
		{
			SortRArray(array, size);
			printf("排序");
			putchar('\n');
		}
		if(c == 'f' || c == 'F')
		{
			printf("查找: ");
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
			putchar('\n');
		}
		if(c == 't' || c == 'T')
		{
			StatisticsMenuRArray(array, size);
		}
		fflush(stdin);
		putchar('\n');
		printf("I-输入 O-输出 D-填数 R-逆置 S-排序 F-查找 T-统计 Q-退出>");
		c = getchar();
	}
	exit(1);
}

//填数子菜单
void FillMenuRArray(REAL array[], INTEGER size)
{
	char c;
	REAL x, f, r, d, lower, upper;
	fflush(stdin);
    printf("V-实数值 A-等差数列 G-等比数列 F-斐波那契数列 R-随机数列 B-返回>");
    c = getchar();
	while (c != 'B' && c != 'b')
	{
		if(c != 'v' && c != 'V' && c != 'a' && c != 'A' && c != 'g' && c != 'G' && c != 'f' && c != 'F' && c != 'r' && c != 'R')
		{
			printf("不正确的选项！");
			putchar('\n');
			fflush(stdin);
			putchar('\n');
			printf("V-实数值 A-等差数列 G-等比数列 F-斐波那契数列 R-随机数列 B-返回>");
			c = getchar();
		}
		else if(c == 'v' || c == 'V')
		{
			printf("填充: ");
			scanf(RSF, &x);
			FillValueRArray(array, size, x);
			putchar('\n');
			MainMenuRArray(array, size);
		}
		else if(c == 'a' || c == 'A')
		{
			printf("首项: ");
			scanf(RSF, &f);
			printf("增量: ");
			scanf(RSF, &d);
			FillArithmeticRArray(array, size, f, d);
			putchar('\n');
			MainMenuRArray(array, size);
		}
		else if(c == 'g' || c == 'G')
		{
			printf("首项: ");
			scanf(RSF, &f);
			printf("比例: ");
			scanf(RSF, &r);
			FillGeometricRArray(array, size, f, r);
			putchar('\n');
			MainMenuRArray(array, size);
		}
		else if(c == 'f' || c == 'F')
		{
			FillFibonacciRArray(array, size);
			printf("斐波那契数列\n");
			putchar('\n');
			MainMenuRArray(array, size);
		}
		else
		{
			printf("下限: ");
			scanf(RSF, &lower);
			printf("上限: ");
			scanf(RSF, &upper);
			FillRandomRArray(array, size, lower, upper);
			putchar('\n');
			MainMenuRArray(array, size);
		}
	}
	if(c == 'b' || c == 'B')
	{
		MainMenuRArray(array, size);
	}
}

//统计子菜单
void StatisticsMenuRArray(REAL array[], INTEGER size)
{
	char c;
	fflush(stdin);
	printf("X-最大值 N-最小值 S-总和 A-平均值 B-返回>");
	c = getchar();
	while (c != 'B' && c != 'b')
	{
		if(c != 'x' && c != 'X' && c != 'n' && c != 'N' && c != 's' && c != 'S' && c != 'a' && c != 'A')
		{
			printf("不正确的选项！");
			putchar('\n');
			fflush(stdin);
			putchar('\n');
			printf("X-最大值 N-最小值 S-总和 A-平均值 B-返回>");
			c = getchar();
		}
		else if(c == 'x' || c == 'X')
		{
			printf("最大值: " RPF "\n", MaxRArray(array, size));
			putchar('\n');
			MainMenuRArray(array, size);
		}
		else if(c == 'n' || c == 'N')
		{
			printf("最小值: " RPF "\n", MinRArray(array, size));
			putchar('\n');
			MainMenuRArray(array, size);
		}
		else if(c == 's' || c == 'S')
		{
			printf("总  和: " RPF "\n", SumRArray(array, size));
			putchar('\n');
			MainMenuRArray(array, size);
		}
		else
		{
			printf("平均值: " RPF "\n", AvgRArray(array, size));
			putchar('\n');
			MainMenuRArray(array, size);
		}
	}
	if(c == 'b' || c == 'B')
	{
		MainMenuRArray(array, size);
	}
} 

//最大值和最小值
REAL MaxRArray(const REAL array[], INTEGER size)
{
	INTEGER	i; 
	REAL max;
	max = array[0];
	for(i = 1;i < size;i++)
	{
		if(GT(array[i], max))
		{
			max = array[i];
		}
	}
	return max;
}

REAL MinRArray(const REAL array[], INTEGER size)
{
	INTEGER	i; 
	REAL min;
	min = array[0];
	for(i = 1;i < size;i++)
	{
		if(LT(array[i], min))
		{
			min = array[i];
		}
	}
	return min;
}

//总和和平均值
REAL SumRArray(const REAL array[], INTEGER size)
{
	REAL s = 0;
	INTEGER i;
	for(i = 0;i < size;i++)
	{
		s += array[i];
	}
	return s;
}

REAL AvgRArray(const REAL array[], INTEGER size)
{
	REAL s = 0;
	INTEGER i;
	for(i = 0;i < size;i++)
	{
		s += array[i];
	}
	return s / size;
}

 //填充实数
void FillValueRArray(REAL array[], INTEGER size, REAL value)
{
	INTEGER i;
	for(i = 0;i < size;i++)
	{
		array[i] = value;
	} 
}

//等差数列
void FillArithmeticRArray(REAL array[], INTEGER size, REAL start, REAL increment)
{
	INTEGER i;
	for(i = 0;i < size;i++)
	{
		array[i] = start + i * increment;
	}
}

//等比数列
void FillGeometricRArray(REAL array[], INTEGER size, REAL start, REAL ratio)
{
	INTEGER i;
	array[0] = start;
	for(i = 1;i < size;i++)
	{
		array[i] = array[i - 1] * ratio;
	}
}

//斐波那契数列
void FillFibonacciRArray(REAL array[], INTEGER size)
{
	INTEGER i;
	array[0] = 1;
	array[1] = 1;
	for(i = 2;i < size;i++)
	{
		array[i] = array[i - 1] + array[i - 2];
	}
}

//随机数列
void FillRandomRArray(REAL array[], INTEGER size, REAL minValue, REAL maxValue)
{
	INTEGER i;
	REAL a = RAND_MAX + 1.0, b = maxValue - minValue;
	for(i = 0;i < size;i++)
	{
		array[i] = b * rand() / a + minValue;
	}
}

//交换实数
void SwapReal(REAL *x, REAL *y)
{
	REAL t;
	t = *x;
	*x = *y;
	*y = t;
} 

//输入输出
void InputRArray(REAL array[], INTEGER size)
{
	INTEGER i;
	for(i = 0;i < size;i++)
	{
		scanf("%lg", &array[i]);
	}
}

void OutputRArray(REAL array[], INTEGER size)
{
	INTEGER i;
	for(i = 0;i < size;i++)
	{
		printf("%g", array[i]);
		putchar(' ');
	}
}  

//赋值
void CopyRArray(REAL dsArray[], const REAL srcArray[], INTEGER size)
{
	INTEGER i;
	for(i = 0;i < size;i++)
	{
		dsArray[i] = srcArray[i];
	}
} 

//逆置
void ReverseRArray(REAL array[], INTEGER size)
{
	INTEGER i;
	REAL array2[size];
	for(i = 0;i < size;i++)
	{
		array2[i] = array[i]; 
	}
	for(i = 0;i < size;i++)
	{
		array[i] = array2[size - i - 1]; 
	}
} 

//排序
//1.冒泡排序 
void SortRArray(REAL array[], INTEGER size)
{
 	INTEGER i, j, loop = 1;
 	for(i = size - 1;loop && i > 0;i--)
	{
		loop = 0;
		for(j = 0;j < i;j++)
		{
			if(array[j] > array[j + 1])
			{
				SwapReal(&array[j], &array[j + 1]);
				loop = 1;
			}
		} 
	}	 	
}

//查找
INTEGER FindRArray(const REAL array[], INTEGER size, REAL x)
{
	INTEGER i, k = 1;
	for(i = 0;k && i < size;i++)
	{
		if(EQ(array[i], x))
		{
			k = 0;
		}
	}
	return k == 1 ? 0 : i;
} 

//比较
BOOL EQRArray(const REAL array1[], const REAL array2[], INTEGER size)
{
	INTEGER i, k = 1;
	for(i = 0;k && i < size;i++)
	{
		if(NE(array1[i], array2[i]))
		{
			k = 0;
		} 
	}
	return k;
}

BOOL NERArray(const REAL array1[], const REAL array2[], INTEGER size)
{
	INTEGER i, k = 1;
	for(i = 0;k && i < size;i++)
	{
		if(EQ(array1[i], array2[i]))
		{
			k = 0;
		} 
	}
	return k;
}

BOOL EQ(REAL x, REAL y)
{
	return x - y <= epsilon && x - y >= -epsilon;
}

BOOL NE(REAL x, REAL y)
{
	return x - y > epsilon || x - y < -epsilon;
}

BOOL GT(REAL x, REAL y)
{
	return x > y + epsilon; 
}


BOOL LT(REAL x, REAL y)
{
	return x < y - epsilon;
}
