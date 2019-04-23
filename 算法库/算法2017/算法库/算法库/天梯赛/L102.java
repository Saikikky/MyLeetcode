import java.util.Scanner;

/**
 * Created by wang on 16/7/8.
 */

//错了一个两份数据,不知道哪错了
public class L102 {
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        String c;
        int f = 0;
        int singlef = f;
        int space = 0;
        int n;
        int s = 0;
        int [] a = new int[26];
        a[0] = -1;
        for (int i = 1; i <= 25; ++i)
        {
            a[i] = 2 * i * i - 1;
        }

        n = sc.nextInt();
        c = sc.next();

//        System.out.print(n + " " + c);

        for (int i = 1; i <= 25; ++i)
        {
            if (a[i] <= n)
            {f = i;s = a[i];}
            else if(a[i] > n)
                break;
        }
//        System.out.print(f);

        singlef = f = 2 * f - 1;

        for (int i = 1; i <= (f + 1) /2 ; ++i)
        {
            for (int j = 1; j <= i - 1; ++j)
                System.out.print(" ");
            for (int j = 1; j <= singlef; ++j)
                System.out.print(c);
            singlef -= 2;
            System.out.println();
        }

        space = (f - 1) / 2 - 1;
        singlef = 3;
        for (int i = 1; i <= (f - 1) / 2; ++i)
        {
            for (int  j = 1; j <= space; ++j)
                System.out.print(" ");
            for (int j = 1; j <= singlef; ++j)
                System.out.print(c);
            singlef+= 2;
            space -= 1;
            System.out.println();
        }

        int dis = n - s;
        if (dis != 0)
            System.out.print(dis);
    }
}
