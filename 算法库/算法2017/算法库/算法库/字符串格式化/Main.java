/**
 * Created by Treasure_ on 16/3/4.
 */

//各种java中的格式化操作
public class Main
{
    public static void main(String [] args)
    {
        String str = String.format("%5d %-5d", 123, 456); //带后面的123表示整体的长度为5,所以前面的空格占2位 -表示左对齐
        String str1 = String.format("%05d", 123); //一共五位,不足在前面补0
        String str2 = String.format("%X", 123); //转化为16进制
        String str3 = String.format("%2$5d", 123, 456); //前面的2$表示用第二个参数
        System.out.print(str);

    }
}
