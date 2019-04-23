#include <stdio.h>
#include <stdlib.h>
#include "MyRArray.h"

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


void MainMenuRArray(REAL array[], INTEGER size)
{
	char c;
	REAL x;
	INTEGER r;
	fflush(stdin);
    printf("I-���� O-��� D-���� R-���� S-���� F-���� T-ͳ�� Q-�˳�>");
    c = getchar();
	while (c != 'q' && c != 'Q')
	{
		if(c != 'i' && c != 'I' && c != 'o' && c != 'O' && c != 'R' && c != 'r' && c != 'f' && c != 'F' && c != 's' && c != 'S' && c != 'd' && c != 'D' && c != 't' && c != 'T')
		{
			printf("����ȷ��ѡ�");
			putchar('\n');
		}
		if(c == 'i' || c == 'I')
		{
			printf("���飺");
			InputRArray(array, size);
		}
		if(c == 'o' || c == 'O')
		{
			printf("���飺");
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
			printf("����");
			putchar('\n');
		}
		if(c == 's' || c == 'S')
		{
			SortRArray(array, size);
			printf("����");
			putchar('\n');
		}
		if(c == 'f' || c == 'F')
		{
			printf("����: ");
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
			putchar('\n');
		}
		if(c == 't' || c == 'T')
		{
			StatisticsMenuRArray(array, size);
		}
		fflush(stdin);
		putchar('\n');
		printf("I-���� O-��� D-���� R-���� S-���� F-���� T-ͳ�� Q-�˳�>");
		c = getchar();
	}
	exit(1);
}

//�����Ӳ˵�
void FillMenuRArray(REAL array[], INTEGER size)
{
	char c;
	REAL x, f, r, d, lower, upper;
	fflush(stdin);
    printf("V-ʵ��ֵ A-�Ȳ����� G-�ȱ����� F-쳲��������� R-������� B-����>");
    c = getchar();
	while (c != 'B' && c != 'b')
	{
		if(c != 'v' && c != 'V' && c != 'a' && c != 'A' && c != 'g' && c != 'G' && c != 'f' && c != 'F' && c != 'r' && c != 'R')
		{
			printf("����ȷ��ѡ�");
			putchar('\n');
			fflush(stdin);
			putchar('\n');
			printf("V-ʵ��ֵ A-�Ȳ����� G-�ȱ����� F-쳲��������� R-������� B-����>");
			c = getchar();
		}
		else if(c == 'v' || c == 'V')
		{
			printf("���: ");
			scanf(RSF, &x);
			FillValueRArray(array, size, x);
			putchar('\n');
			MainMenuRArray(array, size);
		}
		else if(c == 'a' || c == 'A')
		{
			printf("����: ");
			scanf(RSF, &f);
			printf("����: ");
			scanf(RSF, &d);
			FillArithmeticRArray(array, size, f, d);
			putchar('\n');
			MainMenuRArray(array, size);
		}
		else if(c == 'g' || c == 'G')
		{
			printf("����: ");
			scanf(RSF, &f);
			printf("����: ");
			scanf(RSF, &r);
			FillGeometricRArray(array, size, f, r);
			putchar('\n');
			MainMenuRArray(array, size);
		}
		else if(c == 'f' || c == 'F')
		{
			FillFibonacciRArray(array, size);
			printf("쳲���������\n");
			putchar('\n');
			MainMenuRArray(array, size);
		}
		else
		{
			printf("����: ");
			scanf(RSF, &lower);
			printf("����: ");
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

//ͳ���Ӳ˵�
void StatisticsMenuRArray(REAL array[], INTEGER size)
{
	char c;
	fflush(stdin);
	printf("X-���ֵ N-��Сֵ S-�ܺ� A-ƽ��ֵ B-����>");
	c = getchar();
	while (c != 'B' && c != 'b')
	{
		if(c != 'x' && c != 'X' && c != 'n' && c != 'N' && c != 's' && c != 'S' && c != 'a' && c != 'A')
		{
			printf("����ȷ��ѡ�");
			putchar('\n');
			fflush(stdin);
			putchar('\n');
			printf("X-���ֵ N-��Сֵ S-�ܺ� A-ƽ��ֵ B-����>");
			c = getchar();
		}
		else if(c == 'x' || c == 'X')
		{
			printf("���ֵ: " RPF "\n", MaxRArray(array, size));
			putchar('\n');
			MainMenuRArray(array, size);
		}
		else if(c == 'n' || c == 'N')
		{
			printf("��Сֵ: " RPF "\n", MinRArray(array, size));
			putchar('\n');
			MainMenuRArray(array, size);
		}
		else if(c == 's' || c == 'S')
		{
			printf("��  ��: " RPF "\n", SumRArray(array, size));
			putchar('\n');
			MainMenuRArray(array, size);
		}
		else
		{
			printf("ƽ��ֵ: " RPF "\n", AvgRArray(array, size));
			putchar('\n');
			MainMenuRArray(array, size);
		}
	}
	if(c == 'b' || c == 'B')
	{
		MainMenuRArray(array, size);
	}
} 

//���ֵ����Сֵ
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

//�ܺͺ�ƽ��ֵ
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

 //���ʵ��
void FillValueRArray(REAL array[], INTEGER size, REAL value)
{
	INTEGER i;
	for(i = 0;i < size;i++)
	{
		array[i] = value;
	} 
}

//�Ȳ�����
void FillArithmeticRArray(REAL array[], INTEGER size, REAL start, REAL increment)
{
	INTEGER i;
	for(i = 0;i < size;i++)
	{
		array[i] = start + i * increment;
	}
}

//�ȱ�����
void FillGeometricRArray(REAL array[], INTEGER size, REAL start, REAL ratio)
{
	INTEGER i;
	array[0] = start;
	for(i = 1;i < size;i++)
	{
		array[i] = array[i - 1] * ratio;
	}
}

//쳲���������
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

//�������
void FillRandomRArray(REAL array[], INTEGER size, REAL minValue, REAL maxValue)
{
	INTEGER i;
	REAL a = RAND_MAX + 1.0, b = maxValue - minValue;
	for(i = 0;i < size;i++)
	{
		array[i] = b * rand() / a + minValue;
	}
}

//����ʵ��
void SwapReal(REAL *x, REAL *y)
{
	REAL t;
	t = *x;
	*x = *y;
	*y = t;
} 

//�������
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

//��ֵ
void CopyRArray(REAL dsArray[], const REAL srcArray[], INTEGER size)
{
	INTEGER i;
	for(i = 0;i < size;i++)
	{
		dsArray[i] = srcArray[i];
	}
} 

//����
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

//����
//1.ð������ 
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

//����
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

//�Ƚ�
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
