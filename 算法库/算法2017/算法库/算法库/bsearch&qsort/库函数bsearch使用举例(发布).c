#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
//
// ϵͳ�⺯�� ���� ���ֲ���
//
// ������ʾ������bsearch��������ʵ�����ַ����ַ����ͽṹ��������п�������ķ���
//
////////////////////////////////////////////////////////////////////////////////
//
// ����ԭ��:
//   void* bsearch(
//     const void *key,                         // �ؼ���(�������ҵ�ֵ)
//     const void *buf,                         // ������ʼ��ַ(����ν������ַ)
//     size_t num,                              // �����С(������Ԫ�ظ���)
//     size_t size,                             // Ԫ�ش�С(��Ԫ�ص��ֽ���)
//     int (*cmp)(const void *x, const void *y) // ����ָ��(ָʾ�Ƚ�Ԫ�صĺ���)
//   );
// �����ҳɹ�, ����ֵΪԪ�صĵ�ַ, ����ΪNULL
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
// ����bsearch�ıȽϺ���
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
	int a[8] = {2, 3, 5, 6, 8, 11, 14, 15}, ka = 11, *pa; // ������������, �ؼ��ֺ�ָ��
	double b[10] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5}, kb = 4.5, *pb; // ����ʵ������, �ؼ��ֺ�ָ��
	char c[6] = {'a', 'b', 'c', 'd', 'e', 'f'}, kc = 'b', *pc; // �����ַ�����͹ؼ���
	struct TIME d[5] = {{0, 0, 0}, {8, 30, 15}, {8, 30, 45}, {12, 0, 0}, {23, 59, 59}}, kd = {8, 30, 15}, *pd; // ����ʱ������, �ؼ��ֺ�ָ��

	IntegerArrayOutput(a, 8); // �����������
	printf("%d\n", ka); // ����ؼ���
	pa = (int*)bsearch(&ka, a, 8, sizeof(int), IntegerCompare); // ���ٲ���
	pa ? printf("[%d]\n", pa - a + 1) : puts("Failed!"); // ����±��"Failed"
	putchar('\n');

	RealArrayOutput(b, 10); // ���ʵ������
	printf("%g\n", kb); // ����ؼ���
	pb = (double*)bsearch(&kb, b, 10, sizeof(double), RealCompare); // ���ٲ���
	pb ? printf("[%d]\n", pb - b + 1) : puts("Failed!"); // ����±��"Failed"
	putchar('\n');

	CharArrayOutput(c, 6); // ����ַ�����
	printf("%c\n", kc); // ����ؼ���
	pc = (char*)bsearch(&kc, c, 6, sizeof(char), CharCompare); // ���ٲ���
	pc ? printf("[%d]\n", pc - c + 1) : puts("Failed!"); // ����±��"Failed"
	putchar('\n');

	TimeArrayOutput(d, 5); // ���ʱ������
	printf("%02d:%02d:%02d\n", kd.hour, kd.minute, kd.second); // ����ؼ���
	pd = (struct TIME*)bsearch(&kd, d, 5, sizeof(struct TIME), TimeCompare); // ���ٲ���
	pd ? printf("[%d]\n", pd - d + 1) : puts("Failed!"); // ����±��"Failed"
	return 0;
}

