/**
 * Created by Treasure_ on 16/3/3.
 */


public class Main
{
    int n = 8;
    char []s = new char[10];
    char []a = {'R', 'A', 'A', '2', '2', '3', '3', '4', '4', 'R'};
    boolean []visit = new boolean[10];

    public boolean xianjie() {
        int i1 = 9, i2 = 9, i3 = 9, i4 = 9;
        for (int i = 1; i <= 8; i++) {
            if (s[i] == 'A') i1 = i;
            if (s[i] == '2') i2 = i;
            if (s[i] == '3') i3 = i;
            if (s[i] == '4') i4 = i;
        }
        if (i1 > 1 && i2 > 2 && i3 > 3 && i4 > 4 && s[i1 - 2] == 'A' && s[i2 - 3] == '2' && s[i3 - 4] == '3' && s[i4 - 5] == '4')
            return true;
        return false;
    }

    public void dfs(int k)
    {
        if (k == n + 1 && xianjie())
        {
            for (int i= 1; i <= 8; ++i)
            {
                System.out.print(s[i] + "  ");
            }
            System.out.println();
        }
        else
        {
            for (int i = 1; i <= 8; ++i)
            {
                if (!visit[i])
                {
                    s[k] = a[i];
                    visit[i] = true;
                    dfs(k + 1);
                    visit[i] = false;
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