/**
 * Created by Treasure_ on 16/3/3.
 */
public class Main
{

    int n = 9;
    int []a = new int[100];

    public boolean xianjie(int k, int j)
    {
        for (int i = 1; i < k; i++)
        {
            if (j == a[i])
                return false;
        }
        return true;
    }

    public boolean ans()
    {
        int a1 = a[1] * 100 + a[2] * 10 + a[3];
        int a2 = a[4] * 100 + a[5] * 10 + a[6];
        int a3 = a[7] * 100 + a[8] * 10 + a[9];
        if (a1 * 2 == a2 && a1 * 3 == a3)
            return true;
        return false;
    }

    public void dfs(int k)
    {
        if (k == n + 1 && ans())
        {
            for (int i = 1; i <= 9; i++)
            {
                System.out.print(a[i] + "  ");
            }
            System.out.println();
        }
        else
        {
            for (int i = 1; i <= 9; i++)
            {
                if (xianjie(k, i))
                {
                    a[k] = i;
                    dfs(k + 1);
                }
            }
        }
    }

    public static void main(String [] args)
    {
        Main mm = new Main();
        mm.dfs(1);
    }
}
