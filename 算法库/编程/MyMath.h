//////////////////////////////////// 
//数据类型
////////////////////////////////////
#include <math.h>
#include<stdlib.h>
#include <ctype.h>

//逻辑类型 
typedef short int BOOL;
#define TRUE 1
#define FALSE 0
#define BSF "%hd" 
#define BPF "%hd"

//整数类型 
typedef long long int INTEGER;
#define ISF "%I64d"
#define IPF "%I64d"

//实数类型 
#define RSF "%lg" 
#define RPF "%.15g"
#define epsilon 1e-8
typedef double REAL;

//求x的n次方
REAL Power(REAL x,INTEGER n);


//求闰年
INTEGER IsLeapYear(INTEGER year);



///////////////////////////////////////////
//整数运算
///////////////////////////////////////////

//最大值 最小值
INTEGER Max(INTEGER x, INTEGER y);
INTEGER Min(INTEGER x, INTEGER y);

//判断偶数 奇数
BOOL IsOdd(INTEGER x);
BOOL IsEven(INTEGER x);

//判断倍数
BOOL IsMultiple(INTEGER m, INTEGER n);

//最大公约数 最小公倍数
INTEGER Gcd(INTEGER m, INTEGER n);
INTEGER Lcm(INTEGER m, INTEGER n);

//整数的最高位 （0的最高位按0处理）
INTEGER TopDigit(INTEGER x);
//整数的最低位 （0的最低位按0处理）
INTEGER LowDigit(INTEGER x);

//整数x的第n位数字
INTEGER Digit(INTEGER x, INTEGER n);

//整数的位数（0作1位数计）
INTEGER NumDigit(INTEGER x);

//整数各位数字之和
INTEGER SumDigit(INTEGER x);

//阶乘函数
REAL Fac(INTEGER n);

//排列数函数
REAL Fac(INTEGER n);

//组合数函数
REAL Cmb(INTEGER m, INTEGER n);

//以任意数制输出整数
void PrintInteger(INTEGER x, INTEGER r);




///////////////////////////////////////////
//实数运算 
///////////////////////////////////////////

//最大值 最小值 
REAL FMax(REAL x, REAL y);
REAL FMin(REAL x, REAL y); 


//判断大于 大于等于 小于 小于等于 等于 不等于 
int GT(REAL x, REAL y);
int GE(REAL x, REAL y);
int LT(REAL x, REAL y);
int LE(REAL x, REAL y);
int EQ(REAL x, REAL y);
int NE(REAL x, REAL y);

//一元一次方程
//ax2 + bx + c = 0
// 0 无解
//-1 唯一解
//-2 无穷多解 
INTEGER LinearEquation(REAL *x, REAL a, REAL b);


//一元二次方程
//ax2 + bx + c = 0
// 0 无解
//-1 唯一解
//-2 无穷多解
// 1 两个相等的实根
// 2 两个不等的实根
// 3 两个共轭的虚根
INTEGER QuadraticEquation(REAL *x1, REAL *x2, REAL a, REAL b,REAL c); 


//二元一次方程组
//a1x + b1y = c1
//a2x + b2y = c2
// 0 无解
// 1 唯一解
// 2 无穷多解
INTEGER EquationGroup(REAL *x,REAL *y, REAL a1,REAL b1, REAL c1, REAL a2,REAL b2, REAL c2);


//符号函数
REAL Sign(REAL x); 


//任意实数的任意整数次幂
REAL Power(REAL x, INTEGER n); 

//取整
INTEGER ToInteger(REAL x); 


