//////////////////////////////////// 
//��������
////////////////////////////////////
#include <math.h>
#include<stdlib.h>
#include <ctype.h>

//�߼����� 
typedef short int BOOL;
#define TRUE 1
#define FALSE 0
#define BSF "%hd" 
#define BPF "%hd"

//�������� 
typedef long long int INTEGER;
#define ISF "%I64d"
#define IPF "%I64d"

//ʵ������ 
#define RSF "%lg" 
#define RPF "%.15g"
#define epsilon 1e-8
typedef double REAL;

//��x��n�η�
REAL Power(REAL x,INTEGER n);


//������
INTEGER IsLeapYear(INTEGER year);



///////////////////////////////////////////
//��������
///////////////////////////////////////////

//���ֵ ��Сֵ
INTEGER Max(INTEGER x, INTEGER y);
INTEGER Min(INTEGER x, INTEGER y);

//�ж�ż�� ����
BOOL IsOdd(INTEGER x);
BOOL IsEven(INTEGER x);

//�жϱ���
BOOL IsMultiple(INTEGER m, INTEGER n);

//���Լ�� ��С������
INTEGER Gcd(INTEGER m, INTEGER n);
INTEGER Lcm(INTEGER m, INTEGER n);

//���������λ ��0�����λ��0����
INTEGER TopDigit(INTEGER x);
//���������λ ��0�����λ��0����
INTEGER LowDigit(INTEGER x);

//����x�ĵ�nλ����
INTEGER Digit(INTEGER x, INTEGER n);

//������λ����0��1λ���ƣ�
INTEGER NumDigit(INTEGER x);

//������λ����֮��
INTEGER SumDigit(INTEGER x);

//�׳˺���
REAL Fac(INTEGER n);

//����������
REAL Fac(INTEGER n);

//���������
REAL Cmb(INTEGER m, INTEGER n);

//�����������������
void PrintInteger(INTEGER x, INTEGER r);




///////////////////////////////////////////
//ʵ������ 
///////////////////////////////////////////

//���ֵ ��Сֵ 
REAL FMax(REAL x, REAL y);
REAL FMin(REAL x, REAL y); 


//�жϴ��� ���ڵ��� С�� С�ڵ��� ���� ������ 
int GT(REAL x, REAL y);
int GE(REAL x, REAL y);
int LT(REAL x, REAL y);
int LE(REAL x, REAL y);
int EQ(REAL x, REAL y);
int NE(REAL x, REAL y);

//һԪһ�η���
//ax2 + bx + c = 0
// 0 �޽�
//-1 Ψһ��
//-2 ������ 
INTEGER LinearEquation(REAL *x, REAL a, REAL b);


//һԪ���η���
//ax2 + bx + c = 0
// 0 �޽�
//-1 Ψһ��
//-2 ������
// 1 ������ȵ�ʵ��
// 2 �������ȵ�ʵ��
// 3 ������������
INTEGER QuadraticEquation(REAL *x1, REAL *x2, REAL a, REAL b,REAL c); 


//��Ԫһ�η�����
//a1x + b1y = c1
//a2x + b2y = c2
// 0 �޽�
// 1 Ψһ��
// 2 ������
INTEGER EquationGroup(REAL *x,REAL *y, REAL a1,REAL b1, REAL c1, REAL a2,REAL b2, REAL c2);


//���ź���
REAL Sign(REAL x); 


//����ʵ����������������
REAL Power(REAL x, INTEGER n); 

//ȡ��
INTEGER ToInteger(REAL x); 


