#include "MyMath.h"


/////////////////////////////////////////
//数据类型
/////////////////////////////////////////

//日期类型
typedef long long int INTEGER;
#define DSF "%I64d-%I64d-%I64d"
#define DPF "%04I64d-%02I64d-%02I64d"

//判断闰年
//BOOL IsLeapYear(INTEGER year);
//闰年数
INTEGER NumLeapYear(INTEGER year);
//月天数
INTEGER MonthDay(INTEGER year,INTEGER month);
//显示星期汉字
void ShowDow(INTEGER x); 
