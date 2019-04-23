import java.util.Scanner;

/**
 * Created by Treasure_ on 16/5/24.
 */
public class MostMoney {

    int m, n;
    Scanner sc = new Scanner(System.in);
    int [][]money = new int[21][51];
    int [] ans = new int[100];
    int temp = 0;
    public static void main(String [] args)
    {
        MostMoney mm = new MostMoney();
        mm.init();
        System.out.print(mm.f(mm.m));
    }

    public void init()
    {
        m = sc.nextInt();
        n = sc.nextInt();
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m + 1; ++j)
            {
                money[i][j] = sc.nextInt();
            }
        }
    }

    public int f(int m)
    {
        if (m <= 0)
            return 0;
        if (ans[m] > 0)
            return ans[m];

        else {
            for (int i = 1; i <= m + 1; ++i) {
                for (int j = 1; j <= n; ++j) {
                    temp = Math.max(f(m - i) + money[j][i], temp);
                }
            }
            return ans[m] = temp;
        }
    }
}
