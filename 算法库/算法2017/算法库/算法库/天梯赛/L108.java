import java.util.Scanner;

/**
 * Created by wang on 16/7/9.
 */
public class L108 {
    public static void main(String [] args)
    {
        int a, b, a1, n;
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        a1 = a;
        int dis = b - a + 1; // 个数
        int sum = 0;
        if (dis % 5 != 0)
          n = dis / 5 + 1; // 行数
        else n = dis / 5;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= 5; ++j)
            {
                if (a <= b)
                    System.out.printf("%5d", a);
                ++a;
            }
            System.out.println();
        }

        sum = dis * a1 + (dis - 1) * dis / 2;
        System.out.print("Sum = "  +  sum);
    }
}
