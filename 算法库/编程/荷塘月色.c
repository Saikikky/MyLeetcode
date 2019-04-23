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
	puts("      荷塘月色");
	puts("   词曲：张    超");
	puts("   演唱：凤凰传奇");
}
void SectionA()
{
	puts("剪一段时光缓缓流淌 ");
	puts("流进了月色中微微荡漾 ");
    puts("弹一首小荷淡淡的香 ");
	puts("美丽的琴音就落在我身旁 ");
}
void SectionB()
{
    puts("萤火虫点亮夜的星光  ");
	puts("谁为我添一件梦的衣裳  ");
	puts("推开那扇心窗远远地望 ");
	puts("谁采下那一朵昨日的忧伤 ");
}
void SectionC()
{
	puts("我像只鱼儿在你的荷塘  ");
    puts("只为和你守候那皎白月光   ");
    puts("游过了四季 荷花依然香  ");
    puts("等你宛在水中央   ");
}
void SectionD()
{
	puts("那时年轻的你 和你水中的模样   ");
    puts("依然不变的仰望漫天迷人的星光  ");
    puts("谁能走进你的心房 采下一朵莲");
    puts("是那夜的芬芳 还是你的发香    ");
}
void SectionE()
{
	puts("荷塘呀荷塘 你慢慢慢慢唱哟    ");
    puts("月光呀月光 你慢慢慢慢听哟  ");
    puts("鱼儿呀鱼儿 你慢慢慢慢游哟 ");
    puts("淡淡的淡淡的 淡淡的月光   ");
}
void Epilogue()
{
	puts("等你宛在水中央......"); 
}
void Newline()
{
	puts("\n");
}
