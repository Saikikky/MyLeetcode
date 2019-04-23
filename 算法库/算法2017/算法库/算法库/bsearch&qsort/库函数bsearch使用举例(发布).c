#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
//
// 系统库函数 —— 二分查找
//
// 本例演示了利用bsearch对整数、实数、字符、字符串和结构体数组进行快速排序的方法
//
////////////////////////////////////////////////////////////////////////////////
//
// 函数原型:
//   void* bsearch(
//     const void *key,                         // 关键字(即待查找的值)
//     const void *buf,                         // 数组起始地址(即所谓缓存首址)
//     size_t num,                              // 数组大小(即数组元素个数)
//     size_t size,                             // 元素大小(即元素的字节数)
//     int (*cmp)(const void *x, const void *y) // 函数指针(指示比较元素的函数)
//   );
// 若查找成功, 则函数值为元素的地址, 否则为NULL
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
// 用于bsearch的比较函数
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
	int a[8] = {2, 3, 5, 6, 8, 11, 14, 15}, ka = 11, *pa; // 定义整数数组, 关键字和指针
	double b[10] = {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5}, kb = 4.5, *pb; // 定义实数数组, 关键字和指针
	char c[6] = {'a', 'b', 'c', 'd', 'e', 'f'}, kc = 'b', *pc; // 定义字符数组和关键字
	struct TIME d[5] = {{0, 0, 0}, {8, 30, 15}, {8, 30, 45}, {12, 0, 0}, {23, 59, 59}}, kd = {8, 30, 15}, *pd; // 定义时间数组, 关键字和指针

	IntegerArrayOutput(a, 8); // 输出整数数组
	printf("%d\n", ka); // 输出关键字
	pa = (int*)bsearch(&ka, a, 8, sizeof(int), IntegerCompare); // 快速查找
	pa ? printf("[%d]\n", pa - a + 1) : puts("Failed!"); // 输出下标或"Failed"
	putchar('\n');

	RealArrayOutput(b, 10); // 输出实数数组
	printf("%g\n", kb); // 输出关键字
	pb = (double*)bsearch(&kb, b, 10, sizeof(double), RealCompare); // 快速查找
	pb ? printf("[%d]\n", pb - b + 1) : puts("Failed!"); // 输出下标或"Failed"
	putchar('\n');

	CharArrayOutput(c, 6); // 输出字符数组
	printf("%c\n", kc); // 输出关键字
	pc = (char*)bsearch(&kc, c, 6, sizeof(char), CharCompare); // 快速查找
	pc ? printf("[%d]\n", pc - c + 1) : puts("Failed!"); // 输出下标或"Failed"
	putchar('\n');

	TimeArrayOutput(d, 5); // 输出时间数组
	printf("%02d:%02d:%02d\n", kd.hour, kd.minute, kd.second); // 输出关键字
	pd = (struct TIME*)bsearch(&kd, d, 5, sizeof(struct TIME), TimeCompare); // 快速查找
	pd ? printf("[%d]\n", pd - d + 1) : puts("Failed!"); // 输出下标或"Failed"
	return 0;
}

