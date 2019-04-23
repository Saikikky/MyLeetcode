import java.util.Scanner;

/**
 * Created by Treasure_ on 16/5/24.
 */
public class CutRod {

    int []a = {10000, 1, 5, 8, 9, 10, 17, 17, 20};
    int [] ans = new int[1000];
    int temp = 0;
    public static void main(String [] args)
    {
        CutRod f = new CutRod();
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        System.out.println(f.dp(n));

    }

    private int dp(int n) {
        if (ans[n] > 0)
            return ans[n];
        if (n == 0)
            return 0;
        else {
            for (int i = 1; i <= n; ++i) {
                temp = Math.max(temp, dp(n - i) + a[i]);
            }
            return ans[n] = temp;
        }
    }

}
