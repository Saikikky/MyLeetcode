import java.util.Scanner;

/**
 * Created by Treasure_ on 16/3/16.
 */

/*
*
标题：地宫取宝

    X 国王有一个地宫宝库。是 n x m 个格子的矩阵。每个格子放一件宝贝。每个宝贝贴着价值标签。

    地宫的入口在左上角，出口在右下角。

    小明被带到地宫的入口，国王要求他只能向右或向下行走。

    走过某个格子时，如果那个格子中的宝贝价值比小明手中任意宝贝价值都大，小明就可以拿起它（当然，也可以不拿）。

    当小明走到出口时，如果他手中的宝贝恰好是k件，则这些宝贝就可以送给小明。

    请你帮小明算一算，在给定的局面下，他有多少种不同的行动方案能获得这k件宝贝。

   【数据格式】

    输入一行3个整数，用空格分开：n m k (1<=n,m<=50, 1<=k<=12)

    接下来有 n 行数据，每行有 m 个整数 Ci (0<=Ci<=12)代表这个格子上的宝物的价值

    要求输出一个整数，表示正好取k个宝贝的行动方案数。该数字可能很大，输出它对 1000000007 取模的结果。

    例如，输入：
    2 2 2
    1 2
    2 1
    程序应该输出：
    2

    再例如，输入：
    2 3 2
    1 2 3
    2 1 5
    程序应该输出：
    14
* */


public class Main
{

    int m, n, k;
    int [][]maze = new int[51][51]; //存储宝贝的价值
    int [][] walk = new int[51][51]; //存储从i j 到终点的走法
    int [][][][]f = new int[51][51][13][13];


    public void init()
    {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                maze[i][j] = sc.nextInt();
                walk[i][j] = 0;
            }
        }

//        for (int i = 0; i < n; ++i)
//        {
//            for (int j = 0; j < m; ++j)
//            {
//                System.out.print(maze[i][j] +" ");
//            }
//            System.out.println();
//        }

    }

    public int Walk(int i, int j) // 计算walk的函数
    {
        if (i < 0 || j < 0 || i >= n || j >= m)
            return 0;
        if (walk[i][j] != 0) return walk[i][j];
        if (i == n - 1 || j == m - 1)
            return walk[i][j] = 1;
        else
            return walk[i][j] = Walk(i + 1, j) + Walk(i, j + 1);
    }

    public int F(int i, int j, int t, int max) // 在i j 的位置, 手中有t件宝物, 最大的价值为max
    {
        if (i >= n || j >= m)
            return 0;
        if (t == k - 1 && maze[i][j] > max && i == n - 1 && j == m - 1)
            return f[i][j][t][maze[i][j]] = 1;
        if (t == k)
            return f[i][j][t][max] = Walk(i, j);
        if (maze[i][j] <= max)
            return f[i][j][t][max] = F(i + 1, j, t, max) + F(i, j + 1, t, max);
        else
            return f[i][j][t][max] = F(i + 1, j, t, max) + F(i, j + 1, t, max) +
                    F(i + 1, j, t + 1, maze[i][j]) + F(i, j + 1, t + 1, maze[i][j]);
    }

    public static void main(String [] args)
    {
        Main mm = new Main();
        mm.init();
        mm.Walk(0, 0);
        System.out.print(mm.F(0, 0, 0, 0));
    }
}