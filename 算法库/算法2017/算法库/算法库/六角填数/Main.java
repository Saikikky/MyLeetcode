/**
 * Created by Treasure_ on 16/3/3.
 */


public class Main {

    public int n = 12;
    public int []a = new int[100];

    boolean xianjie(int k, int j)
    {
        for(int i = 1; i <= k; i++)
        {
            if (a[i] == j)
            {
                return false;
            }
        }
        return true;
    }

    public boolean ans()
    {
        if (a[1] + a[3] + a[6] + a[8] == 26 && a[1] + a[4] + a[7] + a[11] == 26 && a[8] + a[9] + a[10] + a[11] == 26 &&
                a[2] + a[3] + a[4] + a[5] == 26 &&
                a[2] + a[6] + a[9] + a[12] == 26 && a[12] + a[10] + a[7] + a[5] == 26 && a[1] == 1 && a[2] == 8 && a[12] == 3)
            return true;
        return false;

    }
    public void dfs(int k)
    {
        if (k == n + 1 && ans())
        {
            //输出
            for (int j = 1; j <= n; j++)
            {
                System.out.print(a[j] +" ");
            }
            System.out.println("");
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (xianjie(k, i))
                {
                    a[k] = i;
                    dfs(k + 1);
                }
            }
        }
    }

    public static void main(String[] args)
    {
        Main m = new Main();
        m.dfs(1);
    }
}
