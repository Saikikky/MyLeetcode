import java.util.Scanner;

/**
 * Created by Treasure_ on 16/5/24.
 */
public class cunzhuang {

    int v, p;
    int [] vill = new int[100];
    int [][] ans = new int[100][100];
    int tmp = 10000;
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);
        cunzhuang mm = new cunzhuang();
        mm.v = sc.nextInt();
        mm.p = sc.nextInt();
        for (int i = 1; i<= mm.v; ++i)
        {
            mm.vill[i] = sc.nextInt();
        }
        System.out.println(mm.f(mm.v, mm.p));
        mm.Cal(mm.v, mm.p);
    }

    public int f(int v, int p)
    {
        if (v == 0)
            return 0;
        if (ans[v][p] > 0)
            return ans[v][p];

        else if (p == 1) {
            return ans[v][p] = Len(1, v);
        }
        else{
            for (int k = 1;k <= v - p; ++k)
            {
                tmp = Math.min(tmp, f(v - k, p - 1) + Len(v - k + 1, v));
            }
            return ans[v][p] = tmp;
        }
    }

    private int Len(int v1, int v2) {
        int s = 0;
        int mid = (v1 + v2) / 2;
        for (int i = v1; i <= v2; ++i)
        {
            s += Math.abs(vill[i] - vill[mid]);
        }
        return s;
    }


    public void Cal(int v, int p)
    {
        int k;
        if (p == 1)
            System.out.print((v + 1) / 2 + " ");
        else
        {
            for (k = 1; k <= v - p; ++k)
            {
                if (ans[v][p] == ans[v - k][p - 1] + Len(v - k + 1, v))
                    break;
            }
            Cal(v - k, p - 1);
            System.out.print(v - k / 2 + " ");
        }
    }

}
