//�Աຯ�������ַ���
/////��һ�ַ��� 
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
			printf("����ȷ�����ݣ����������룺");
			fflush(stdin);
		}
	}
	while(err);
	str[k] = '\0';
	ungetc(x,stdin);
} 
////�ڶ��ַ���  ȫ��ָ��
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
			printf("����ȷ�����ݣ����������룺");
			fflush(stdin);
		}
	}
	while (err);
	*p = '\0';
	ungetc(x,stdin);
}

/////�Ա��ַ�����ֵ�����ƣ�����
////��һ�ַ��� 
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
/////�ڶ��ַ�����ȫ��ָ�룩
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
 ///ָ��Ľ���
  char* StrCpy(char *dst,const char *src)
  {
  	char *p = dst;
  	const char *q = src;
  	while(*p++ = *q++);//���� 
  	return dst
  } 
