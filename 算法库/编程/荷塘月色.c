#include <stdio.h>
void LotuslnMoonlight(); 
void Title();
void SectionA();
void SectionB();
void SectionC();
void SectionD();
void SectionE();
void Epilogue();
void Newline();
int main()
{
	LotuslnMoonlight(); 
	return 0;
}
void LotuslnMoonlight()
{
	Title();
	Newline();
	SectionA();
	Newline();
	SectionB();
	Newline();
	SectionC();
	Newline();
	SectionB();
	Newline();
	SectionC();
	Newline();
	SectionD();
	Newline();
	SectionE();
	Newline();
	SectionC();
    Newline();
    Epilogue();
}
void Title()
{
	puts("      ������ɫ");
	puts("   ��������    ��");
	puts("   �ݳ�����˴���");
}
void SectionA()
{
	puts("��һ��ʱ�⻺������ ");
	puts("��������ɫ��΢΢���� ");
    puts("��һ��С�ɵ������� ");
	puts("���������������������� ");
}
void SectionB()
{
    puts("ө������ҹ���ǹ�  ");
	puts("˭Ϊ����һ���ε�����  ");
	puts("�ƿ������Ĵ�ԶԶ���� ");
	puts("˭������һ�����յ����� ");
}
void SectionC()
{
	puts("����ֻ�������ĺ���  ");
    puts("ֻΪ�����غ������¹�   ");
    puts("�ι����ļ� �ɻ���Ȼ��  ");
    puts("��������ˮ����   ");
}
void SectionD()
{
	puts("��ʱ������� ����ˮ�е�ģ��   ");
    puts("��Ȼ����������������˵��ǹ�  ");
    puts("˭���߽�����ķ� ����һ����");
    puts("����ҹ�ķҷ� ������ķ���    ");
}
void SectionE()
{
	puts("����ѽ���� ������������Ӵ    ");
    puts("�¹�ѽ�¹� ������������Ӵ  ");
    puts("���ѽ��� ������������Ӵ ");
    puts("�����ĵ����� �������¹�   ");
}
void Epilogue()
{
	puts("��������ˮ����......"); 
}
void Newline()
{
	puts("\n");
}
