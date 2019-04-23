#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
//
// ϵͳ�⺯�� ���� ��������
//
// ������ʾ������qsort��������ʵ�����ַ����ַ����ͽṹ��������п�������ķ���
//
////////////////////////////////////////////////////////////////////////////////
//
// ����ԭ��:
//   void qsort(
//     void *buf,                               // ������ʼ��ַ(����ν������ַ)
//     size_t num,                              // �����С(������Ԫ�ظ���)
//     size_t size,                             // Ԫ�ش�С(��Ԫ�ص��ֽ���)
//     int (*cmp)(const void *x, const void *y) // ����ָ��(ָʾ�Ƚ�Ԫ�صĺ���)
//   );
//
// ˵��: �ȽϺ���Ϊͨ�ú���, �ɱȽ��κ����ͱ�����ֵ, �����Ǳ����ĵ�ַ(ͨ��ָ��)
// Ҫ��: ��x��ָ������ֵ����y��ָ������ֵ, ����ֵΪ������
//       ��x��ָ������ֵС��y��ָ������ֵ, ����ֵΪ������
//       ��x��ָ������ֵ����y��ָ������ֵ, ����ֵΪ��
//
////////////////////////////////////////////////////////////////////////////////


// ����ʱ��ṹ����
struct TIME
{
	int hour, minute, second; // ʱ���֡���
};

////////////////////////////////////////////////////////////////////////////////
// ����qsort�ıȽϺ���
////////////////////////////////////////////////////////////////////////////////

// �Ƚ�����
// ��x��ָ��������y��ָ����, ����ֵΪ������
// ��x��ָ����С��y��ָ����, ����ֵΪ������
// ��x��ָ��������y��ָ����, ����ֵΪ��
int IntegerCompare(const void *x, const void *y)
{
	return *(int*)x - *(int*)y;
}

// �Ƚ�ʵ��
// ��x��ָʵ������y��ָʵ��, ����ֵΪ������
// ��x��ָʵ��С��y��ָʵ��, ����ֵΪ������
// ��x��ָʵ������y��ָʵ��, ����ֵΪ��
int RealCompare(const void *x, const void *y)
{
	double vx = *(double*)x, vy = *(double*)y;
	int result;
	if (vx > vy)
	{
		result = 1;
	}
	else if (vx == vy)
	{
		result = 0;
	}
	else // vx < vy
	{
		result = -1;
	}
	return result;
}

// �Ƚ��ַ�
// ��x��ָ�ַ�����y��ָ�ַ�, ����ֵΪ������
// ��x��ָ�ַ�С��y��ָ�ַ�, ����ֵΪ������
// ��x��ָ�ַ�����y��ָ�ַ�, ����ֵΪ��
int CharCompare(const void *x, const void *y)
{
	return *(char*)x - *(char*)y; // �ַ����Զ�����Ϊ����
}

// �Ƚ�ʱ��
// ��x��ָ�ַ�����y��ָ�ַ�, ����ֵΪ������
// ��x��ָ�ַ�С��y��ָ�ַ�, ����ֵΪ������
// ��x��ָ�ַ�����y��ָ�ַ�, ����ֵΪ��
int TimeCompare(const void *x, const void *y)
{
	int result;
	result = ((struct TIME*)x)->hour - ((struct TIME*)y)->hour;
	if (0 == result)
	{
		result = ((struct TIME*)x)->minute - ((struct TIME*)y)->minute;
	}
	if (0 == result)
	{
		result = ((struct TIME*)x)->second - ((struct TIME*)y)->second;
	}
	return result;
}

////////////////////////////////////////////////////////////////////////////////
// ���ڲ鿴������������
////////////////////////////////////////////////////////////////////////////////

// �����������
void IntegerArrayOutput(const int array[], int size)
{
	int k;
	putchar('(');
	for (k = 0; k < size; k++)
	{
		printf(" %d", array[k]);
	}
	putchar(' ');
	putchar(')');
	putchar('\n');
}

// ���ʵ������
void RealArrayOutput(const double array[], int size)
{
	int k;
	putchar('(');
	for (k = 0; k < size; k++)
	{
		printf(" %g", array[k]);
	}
	putchar(' ');
	putchar(')');
	putchar('\n');
}

// ����ַ�����
void CharArrayOutput(const char array[], int size)
{
	int k;
	putchar('(');
	for (k = 0; k < size; k++)
	{
		putchar(' ');
		putchar(array[k]);
	}
	putchar(' ');
	putchar(')');
	putchar('\n');
}

// ���ʱ������
void TimeArrayOutput(const struct TIME array[], int size)
{
	int k;
	putchar('(');
	for (k = 0; k < size; k++)
	{
		printf(" %02d:%02d:%02d", array[k].hour, array[k].minute, array[k].second);
	}
	putchar(' ');
	putchar(')');
	putchar('\n');
}

////////////////////////////////////////////////////////////////////////////////
// ʹ��qsort�������п�������
////////////////////////////////////////////////////////////////////////////////

int main()
{
	int a[8] = {2, 5, 1, 7, 3, 8, 4, 9}; // ������������
	double b[10] = {2.5, 6.5, 9.5, 8.5, 7.5, 4.5, 3.5, 1.5, 0.5, 5.5}; // ����ʵ������
	char c[6] = {'b', 'f', 'a', 'd', 'c', 'e'}; // �����ַ�����
	struct TIME d[5] = {{8, 30, 45}, {0, 0, 0}, {23, 59, 59}, {12, 0, 0}, {8, 30, 15}}; // ����ʱ������

	IntegerArrayOutput(a, 8); // �����������(����ǰ)
	qsort(a, 8, sizeof(int), IntegerCompare); // ��������
	IntegerArrayOutput(a, 8); // �����������(�����)
	putchar('\n');

	RealArrayOutput(b, 10); // ���ʵ������(����ǰ)
	qsort(b, 10, sizeof(double), RealCompare); // ��������
	RealArrayOutput(b, 10); // ���ʵ������(�����)
	putchar('\n');

	CharArrayOutput(c, 6); // ����ַ�����(����ǰ)
	qsort(c, 6, sizeof(char), CharCompare); // ��������
	CharArrayOutput(c, 6); // ����ַ�����(�����)
	putchar('\n');

	TimeArrayOutput(d, 5); // ���ʱ������(����ǰ)
	qsort(d, 5, sizeof(struct TIME), TimeCompare); // ��������
	TimeArrayOutput(d, 5); // ���ʱ������(�����)
	return 0;
}

