/**
 * Created by Treasure_ on 16/5/14.
 */

/*
1.输出1~n的全排列。（时间：5分钟）
2.输出1~n中取m个的全排列。（时间：5分钟）
3.输出1~n的所有子集。（时间：6分钟）
4.输出1~n的包含k个元素的所有子集。（时间：8分钟）
5.输出1~n的和为S的子集（时间：8分钟）
6.输出1~n的含有k个元素且和为S的所有子集。（时间：10分钟）
7.将1~n分成k个互不相交、且并集为全集的非空子集，输出所有划分情况。（时间：30分钟）
  例如n=4,k=3,即将U={1,2,3,4}划分成3个互不相交且并集为U的所有子集，划分结果有：
            {1,2}, {3}, {4}
            {1,3}, {2}, {4}
            {1}, {2,3}, {4}
            {1,4}, {2}, {3}
            {1}, {2,4}, {3}
            {1}, {2}, {3,4}
（1,2为排列型，3,4,5,6,7为组合型）
*/

    /*
public class Main {

    int n = 4;
    int m = 3;
    int S = 9;
    int countm = 0;
    int countS = 0;
    int leftS = n * (n + 1) / 2;
    int [] a = new int[100];
    int [] count = new int[100];
    boolean [] visit = new boolean[100];

    public static void main(String [] args)
    {
        Main m = new Main();
//        for (int i = 0; i < 100; ++i)
//        {
//            m.visit[i] = false;
//        }
        m.dfs_7(1);
    }

    //1
    public void dfs_1(int k)
    {
        if (k == n + 1) {
            for (int i = 1; i <= n; ++i)
            {
                System.out.print(a[i] + "  ");
            }
            System.out.println();
        }

        else {
            for (int i = 1; i <= n; i++)
            {
                if (!visit[i])
                {
                    visit[i] = true;
                    a[k] = i;
                    dfs_1(k + 1);
                    visit[i] = false;
                }
            }
        }
    }

    //2
    public void dfs_2(int k)
    {
        if (k == m + 1)
        {
            for (int i = 1; i <= m; ++i)
            {
                System.out.print(a[i] + "  ");
            }
            System.out.println();
        }
        else
        {
            for (int i = 1; i <= n; ++i)
            {
                if (!visit[i])
                {
                    visit[i] = true;
                    a[k] = i;
                    dfs_2(k + 1);
                    visit[i] = false;
                }
            }
        }
    }

    //3
    public void dfs_3(int k)
    {
        if (k == n + 1)
        {
            for (int i = 1; i <= n; ++i)
            {
                if (a[i] == 1)
                    System.out.print(i);
            }
            System.out.println();
        }
        else
        {
            for (int i = 1; i <= 2; ++i)
            {
                a[k] = i;
                dfs_3(k + 1);
            }
        }
    }

    //4 子集内包含元素个数为m个
    public void dfs_4(int k)
    {
        if (k == n + 1)
        {
            for (int i = 1; i <= n; ++i)
            {
                if (a[i] == 1)
                {
                    System.out.print(i + " ");
                }
            }
            System.out.println();
        }

        else
        {
            for (int i = 1; i <= 2; ++i)
            {
                if (pruning_4(k, i))
                {
                    if (i == 1)
                        ++countm;
                    a[k] = i;
                    dfs_4(k + 1);
                    if (i == 1)
                        --countm;
                }
            }
        }
    }
    boolean pruning_4(int k, int i)
    {
        if (i == 1 && countm == m)
            return false;

        if (i == 2 && countm + n  - k < m)
            return false;

        return true;
    }

    // 5 和为S
    public void dfs_5(int k)
    {
        if (k == n + 1 && countS == S)
        {
            for (int i = 1; i <= n; ++i)
            {
                if (a[i] == 1)
                    System.out.print(i + " ");
            }
            System.out.println();
        }
        else
        {
            for (int i = 1; i <= 2; ++i)
            {
                if (pruning_5(k, i))
                {
                    if (i == 1) {
                        countS += k;
                        leftS -= k;
                    }
                    a[k] = i;
                    dfs_5(k + 1);
                    if (i == 1) {
                        countS -= k;
                        leftS += k;
                    }
                }
            }
        }
    }
    boolean pruning_5(int k, int i)
    {
        if (i == 1 && countS + k > S)
            return false;

        if (i == 2 && countS + leftS - k < S)
            return false;

        return true;
    }

    //6
    public void dfs_6(int k)
    {
        if (k == n + 1 && countS == S)
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == 1)
                    System.out.print(i + " ");
            }
            System.out.println();
        }

        else
        {
            for (int i = 1; i <= 2; ++i)
            {
                if (pruning_6(k, i))
                {
                    if (i == 1)
                    {
                        ++countm;
                        countS += k;
                        leftS -= k;
                    }
                    a[k] = i;
                    dfs_6(k + 1);
                    if (i == 1)
                    {
                        --countm;
                        countS -= k;
                        leftS += k;
                    }
                }
            }
        }
    }
    public boolean pruning_6(int k, int i)
    {
        if (i == 1 && countm + 1 > m)
            return false;

        if (i == 1 && countS + k > S)
            return false;

        if (i == 2 && countm + n - k < m)
            return false;

        if (i == 2 && countS + leftS - k < S)
            return false;

        return true;
    }

    //7  剪枝有一点点小问题
    public void dfs_7(int k)
    {
        if (k == n + 1)
        {
            for (int j = 1; j <= m; ++j)
            {
                System.out.print("{ ");
                for (int i = 1; i <= n; ++i)
                {
                    if (a[i] == j)
                        System.out.print(i + " ");
                }
                System.out.print("}  ");
            }
            System.out.println();
        }

        else
        {
            for (int i = 1; i <= m; ++i)
            {
                if (pruning_7(k, i))
                {
                    a[k] = i;
                    ++count[i];
                    dfs_7(k + 1);
                    --count[i];
                }
            }
        }
    }

    public boolean pruning_7(int k, int i)
    {
        if (i > 1 && count[i - 1] == 0)
            return false;

        if (k == n)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (j != i && count[j] == 0)
                    return false;
            }
        }

        return true;
    }

}


        */


//完美正方形

public class Main{

    int [] q = {21111, 2, 5, 9, 11, 16, 17, 19, 21, 22, 24, 26, 30, 31, 33, 35, 36, 41, 46, 47, 50, 52, 61, 211111};
    int n = 22;
    int S = 47;
    int [] a = new int[500];
    int p = 61;
    int counts = 0;
    int leftS = 0;

    public static void main(String [] args)
    {
        Main m = new Main();

        for (int i = 1; i <= 22; i++)
        {
            m.leftS += m.q[i];
        }

        m.dfs(1);

    }

    public void dfs(int k)
    {
        if (k == n + 1 && counts == S)
        {
            //if (have(p))
                for (int i = 1; i <= n; ++i)
                {
                    if (a[i] == 1)
                    {
                        System.out.print(q[i] + " ");
                    }
                }
                System.out.println();
        }

        else
        {
            for (int i = 1; i <= 2; ++i)
            {
                if (pruning(k, i))
                {
                    if (i == 1)
                    {
                        counts += q[k];
                        leftS -= q[k];
                    }
                    a[k] = i;
                    dfs(k + 1);
                    if (i == 1)
                    {
                        counts -= q[k];
                        leftS += q[k];
                    }
                }
            }
        }
    }

    public boolean pruning(int k, int i)
    {
        if (i == 1 && counts + q[k] > S)
            return false;
        if (i == 2 && counts + leftS - q[k] < S)
            return false;

        return true;
    }

    public boolean have(int p)
    {
        int i;
        for (i = 0; i <= 22; i++)
        {
            if (q[i] == p)
                break;
        }
        if (a[i] == 1)
            return true;
        else return false;
    }
}