#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
//
// 系统库函数 —— 快速排序
//
// 本例演示了利用qsort对整数、实数、字符、字符串和结构体数组进行快速排序的方法
//
////////////////////////////////////////////////////////////////////////////////
//
// 函数原型:
//   void qsort(
//     void *buf,                               // 数组起始地址(即所谓缓存首址)
//     size_t num,                              // 数组大小(即排序元素个数)
//     size_t size,                             // 元素大小(即元素的字节数)
//     int (*cmp)(const void *x, const void *y) // 函数指针(指示比较元素的函数)
//   );
//
// 说明: 比较函数为通用函数, 可比较任何类型变量的值, 参数是变量的地址(通用指针)
// 要求: 若x所指变量的值大于y所指变量的值, 则函数值为正整数
//       若x所指变量的值小于y所指变量的值, 则函数值为负整数
//       若x所指变量的值等于y所指变量的值, 则函数值为零
//
////////////////////////////////////////////////////////////////////////////////


// 定义时间结构类型
struct TIME
{
	int hour, minute, second; // 时、分、秒
};

////////////////////////////////////////////////////////////////////////////////
// 用于qsort的比较函数
////////////////////////////////////////////////////////////////////////////////

// 比较整数
// 若x所指整数大于y所指整数, 则函数值为正整数
// 若x所指整数小于y所指整数, 则函数值为负整数
// 若x所指整数等于y所指整数, 则函数值为零
int IntegerCompare(const void *x, const void *y)
{
	return *(int*)x - *(int*)y;
}

// 比较实数
// 若x所指实数大于y所指实数, 则函数值为正整数
// 若x所指实数小于y所指实数, 则函数值为负整数
// 若x所指实数等于y所指实数, 则函数值为零
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

// 比较字符
// 若x所指字符大于y所指字符, 则函数值为正整数
// 若x所指字符小于y所指字符, 则函数值为负整数
// 若x所指字符等于y所指字符, 则函数值为零
int CharCompare(const void *x, const void *y)
{
	return *(char*)x - *(char*)y; // 字符型自动升级为整型
}

// 比较时间
// 若x所指字符大于y所指字符, 则函数值为正整数
// 若x所指字符小于y所指字符, 则函数值为负整数
// 若x所指字符等于y所指字符, 则函数值为零
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
// 用于查看数组的输出函数
////////////////////////////////////////////////////////////////////////////////

// 输出整数数组
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

// 输出实数数组
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

// 输出字符数组
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

// 输出时间数组
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
// 使用qsort函数进行快速排序
////////////////////////////////////////////////////////////////////////////////

int main()
{
	int a[8] = {2, 5, 1, 7, 3, 8, 4, 9}; // 定义整数数组
	double b[10] = {2.5, 6.5, 9.5, 8.5, 7.5, 4.5, 3.5, 1.5, 0.5, 5.5}; // 定义实数数组
	char c[6] = {'b', 'f', 'a', 'd', 'c', 'e'}; // 定义字符数组
	struct TIME d[5] = {{8, 30, 45}, {0, 0, 0}, {23, 59, 59}, {12, 0, 0}, {8, 30, 15}}; // 定义时间数组

	IntegerArrayOutput(a, 8); // 输出整数数组(排序前)
	qsort(a, 8, sizeof(int), IntegerCompare); // 快速排序
	IntegerArrayOutput(a, 8); // 输出整数数组(排序后)
	putchar('\n');

	RealArrayOutput(b, 10); // 输出实数数组(排序前)
	qsort(b, 10, sizeof(double), RealCompare); // 快速排序
	RealArrayOutput(b, 10); // 输出实数数组(排序后)
	putchar('\n');

	CharArrayOutput(c, 6); // 输出字符数组(排序前)
	qsort(c, 6, sizeof(char), CharCompare); // 快速排序
	CharArrayOutput(c, 6); // 输出字符数组(排序后)
	putchar('\n');

	TimeArrayOutput(d, 5); // 输出时间数组(排序前)
	qsort(d, 5, sizeof(struct TIME), TimeCompare); // 快速排序
	TimeArrayOutput(d, 5); // 输出时间数组(排序后)
	return 0;
}

