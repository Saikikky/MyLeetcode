import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

/**
 * Created by Treasure_ on 16/3/3.
 */

//JAVA 排序 字符串分割

public class Main
{
    String string;
    String [] str = new String[200];
    ArrayList al = new ArrayList(100);

    public void f()
    {
        Scanner sc = new Scanner(System.in);

        int hangshu = sc.nextInt();
        sc.nextLine();
        int trans;
        for (int i = 0; i < hangshu; ++i)
        {
            string =  sc.nextLine();
//            System.out.print(mm.str[i]);
            str = string.split(" ");
            for (int q = 0; q < str.length; q++)
            {
                trans = Integer.parseInt(str[q]);
                al.add(trans);
            }

        }
        for (Object s : al)
        {
            System.out.print(s + "  ");
        }
    }

    public static void main(String [] args)
    {
        Main mm = new Main();
        mm.f();
    }
}
