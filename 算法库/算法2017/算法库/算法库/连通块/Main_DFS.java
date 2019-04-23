import java.util.Scanner;

/**
 * Created by Treasure_ on 16/5/18.
 */
public class Main_DFS {

    int m, n; // m hang  n lie

    char [][] oil = new char[102][102];
    boolean [][] visit = new boolean[102][102];
    int block = 0;
    int [][]dis = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {1, 1}, {-1, 1}};

    public static void main(String [] args)
    {
        Scanner sc= new Scanner(System.in);
        Main_DFS mm = new Main_DFS();
        String str;
        while (true)
        {
            mm.m= sc.nextInt();
            mm.n = sc.nextInt();

            mm.block = 0;
            sc.nextLine();
            if (mm.m == 0 && mm.n == 0)
                break;

            for (int i = 0; i < mm.m; ++i)
            {
                str = sc.nextLine();
                for (int j = 0; j < mm.n; ++j)
                {
                    mm.oil[i][j] = str.charAt(j);
                    mm.visit[i][j] = false;
                }
            }

//            for (int i = 0; i < m; ++i)
//            {
//                for (int j = 0; j < n; ++j)
//                {
//                    System.out.print(mm.oil[i][j] + " ");
//                }
//                System.out.println();
//            }

            for (int i = 0; i < mm.m; ++i)
            {
                for (int j = 0; j < mm.n; ++j)
                {
                    if (!mm.visit[i][j] && mm.oil[i][j] == '@')
                    {
                        ++mm.block;
                        mm.dfs(i, j);
                    }
                }
            }
            System.out.println(mm.block);
        }
    }


    private void dfs(int i, int j) {
        int nextx, nexty;
        for (int p = 0; p < 8; ++p)
        {
            nextx = i + dis[p][0];
            nexty = j + dis[p][1];

            if (isRightPos(nextx, nexty))
            {
                visit[nextx][nexty] = true;
                dfs(nextx, nexty);
            }
        }
    }

    public boolean isRightPos(int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j > n)
            return false;
        if (visit[i][j])
            return false;
        if (oil[i][j] == '*')
            return false;
        return true;
    }


}
