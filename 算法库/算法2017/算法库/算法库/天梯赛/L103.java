import java.util.Scanner;

/**
 * Created by wang on 16/7/8.
 */
public class L103 {
    public static void main(String [] args)
    {
//        int n;
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int [] a = new int [11];
        for (int i = 0; i < s.length(); ++i)
        {
            int index = s.charAt(i) - 48;
            a[index] += 1;
        }

        for (int i = 0; i <= 9; ++i)
        {
            if (a[i] != 0)
                System.out.println(i + ":" + a[i]);
        }
    }
}
