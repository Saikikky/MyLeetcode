import java.util.Scanner;

/**
 * Created by Treasure_ on 16/3/4.
 */

/*
*
* 问题描述
如果一个自然数N的K进制表示中任意的相邻的两位都不是相邻的数字，那么我们就说这个数是K好数。
求L位K进制数中K好数的数目。例如K = 4，L = 2的时候，所有K好数为11、13、20、22、30、31、33 共7个。
由于这个数目很大，请你输出它对1000000007取模后的值。
输入格式
输入包含两个正整数，K和L。
输出格式
输出一个整数，表示答案对1000000007取模后的值。
样例输入
4 2
样例输出
7
数据规模与约定
对于30%的数据，KL <= 106；
对于50%的数据，K <= 16， L <= 10；
对于100%的数据，1 <= K,L <= 100。

* */

public class Main
{
    int k, l;
    int s = 0;

    int [][]a = new int[100][100];
    final int mm = 1000000007;

    public int dp(int i, int length)
    {
        int s = 0;
        if (i < 0 || i >= k) return 0;
        if (a[i][length] != 0) return a[i][length];
        if (length == 1) return 1;

        for (int t = 0; t < k; t++)
        {
            if (t != i - 1 && t != i + 1)
            {
                s = (s + dp(t, length - 1)) % mm;
            }
        }
        return a[i][length] = s;
    }

    public void f()
    {
        Scanner sc = new Scanner(System.in);
        k = sc.nextInt();
        l = sc.nextInt();

        for (int i = 1; i < k; ++i)
        {
            s = s + dp(i, l);
        }
        System.out.print(s);

    }


    public static void main(String [] args)
    {
        Main w = new Main();
        w.f();
    }
}
