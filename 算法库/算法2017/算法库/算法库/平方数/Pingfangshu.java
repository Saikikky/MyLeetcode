import java.util.Scanner;

/**
 * Created by Treasure_ on 16/5/24.
 */
public class Pingfangshu {

    int [][] a = new int[1000][1000];
    int minsqrt = 0;
    int ans = 100000;
    int temp;
    public static void main(String [] args)
    {
        int n;
        Scanner sc = new Scanner(System.in);
        Pingfangshu mm = new Pingfangshu();
        while (true) {
            n = sc.nextInt();
            mm.minsqrt = (int) Math.sqrt(n);
            System.out.println(mm.f(n,1));
            mm.cal(n, 1);
        }
    }

    public int f(int s, int k)
    {
        if (k < 0)
            return 0;
        if (a[s][k] > 0)
            return a[s][k];
        if (s == k * k)
            return a[s][k] = 1;
        else if (s > k * k)
            return a[s][k] = Math.min(f(s - k * k, k) + 1, f(s, k + 1));
        else return a[s][k] = s + 1;
    }

    public void cal(int s, int k)
    {
        if (s == k * k)
            System.out.print(k + " ");
        else if (a[s][k] == a[s - k * k][k] + 1){
            System.out.print(k + " ");
            cal(s - k * k, k);
        }
        else
            cal(s, k + 1);

    }
}
