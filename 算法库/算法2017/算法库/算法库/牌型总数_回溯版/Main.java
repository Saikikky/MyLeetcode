/**
 * Created by Treasure_ on 16/3/3.
 */
public class Main
{
    int []visit = new int[20];
    int n = 54, m = 13;
    int count = 0;
    int []a = new int[500];

    public boolean xianjie(int k , int i)
    {
        if (visit[i] <= 0) return false;
        return true;
    }

    public void dfs(int k)
    {
        if (k == m + 1)
        {
            ++count;
        }
        else
        {
            for (int i = 1; i <= 13; i++)
            {
                if (xianjie(k, i))
                {
                    a[k] = i;
                    visit[i] -= 1;
                    dfs(k + 1);
                    visit[i] += 1;
                }
            }
        }
    }

    public static void main(String [] args)
    {
        Main m = new Main();
        for (int i = 1; i <= 13; ++i)
        {
            m.visit[i] = 4;
        }

        m.dfs(1);
        System.out.print(m.count);
    }
}
