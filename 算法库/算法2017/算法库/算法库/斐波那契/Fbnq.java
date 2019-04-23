import java.util.Scanner;

/**
 * Created by Treasure_ on 16/5/23.
 */
public class Fbnq {

    int []a = new int[100];
    public static void main(String [] args)
    {
        Fbnq f = new Fbnq();
        int n;
        Scanner sc = new Scanner(System.in);
        while (true){
        n = sc.nextInt();
        System.out.println(f.dp(n));
        }
    }

    public int dp(int n)
    {
        if (a[n] > 0)
            return a[n];
        if (n == 1)
            return a[n] = 1;
        if (n == 2)
            return a[n] = 1;
        if (n > 2)
            return a[n] = dp(n - 1) + dp(n - 2);
        return -1;
    }
}
