#include <stdio.h>
#include "MyDate.h"

//�ж�����
BOOL IsLeapYear(INTEGER year)
{
	return year % 4 == 0 && year % 100 != 0 ||year % 400 == 0;
} 

//������
INTEGER NumLeapYear(INTEGER year)
{
	return year / 4 - year / 100 + year / 400;
} 
