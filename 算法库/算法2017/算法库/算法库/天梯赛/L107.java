import java.util.Scanner;

/**
 * Created by wang on 16/7/9.
 */
public class L107 {
    public static void main(String [] args)
    {
        String [] a = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi",  "ba", "jiu", "fu"};

        Scanner sc = new Scanner(System.in);
        String str;
        str = sc.next();

        for (int i = 0; i < str.length() - 1; ++i)
        {
            if (str.charAt(i) == '-')
                System.out.print(a[10] + " ");
            else
                System.out.print(a[str.charAt(i) - 48] + " ");
        }
        System.out.print(a[str.charAt(str.length() - 1) - 48]);

    }
}
