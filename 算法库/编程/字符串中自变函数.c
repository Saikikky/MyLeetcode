//自编函数输入字符串
/////第一种方法 
void GetStr(char *str,int size)
{
	int k = 0,m = size - 1, err;
	char x;
	fflush(stdin);
	do
	{
		while(x = getchar(),k < m && x != '\n')
		{
			str[k] = x;
			k++;
		}
		err = x != '\n';
		if(err)
		{
			printf("不正确的数据！请重新输入：");
			fflush(stdin);
		}
	}
	while(err);
	str[k] = '\0';
	ungetc(x,stdin);
} 
////第二种方法  全用指针
void GetStr(char *str,int size)
{
	char x, *p = str,*q = str + size - 1;
	int err;
	fflush(stdin);
	do
	{
		while(x = getchar(),p < q && x != '\n');
		{
			*p = x;
			p++;
		}
		err = x != '\n';
		if(err)
		{
			printf("不正确的数据！请重新输入：");
			fflush(stdin);
		}
	}
	while (err);
	*p = '\0';
	ungetc(x,stdin);
}

/////自编字符串赋值（复制）函数
////第一种方法 
char* StrCpy(char *dst,const char *src)
{
	int k = 0;
	for(k = 0;scr[k] != '\0';k++)
	{
		dst[k] = src[k];
	}
	dst[k] = '\0';
	return dst;
} 
/////第二种方法（全用指针）
 char* StrCpy(char *dst,const char *src)
 {
 	char *p = dst;
 	const char *q = src;
 	while(*q != '\0')
 	{
 		*p = *q;
 		p++;
 		q++;
 	}
 	*q = '\0';
 	return dst;
 } 
 ///指针改进版
  char* StrCpy(char *dst,const char *src)
  {
  	char *p = dst;
  	const char *q = src;
  	while(*p++ = *q++);//技巧 
  	return dst
  } 
