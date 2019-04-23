import java.util.LinkedList;
import java.util.Scanner;

/**
 * Created by Treasure_ on 16/5/18.
 */
public class Main_BFS {
    private static Scanner sc = new Scanner(System.in);
    int m, n;
    char [][] oil = new char[102][102];
    int [][]dis = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}, {1, 1}, {-1, 1}};
    boolean[][] visit = new boolean[102][102];
    LinkedList<Node> queue = new LinkedList<Node>();
    int block = 0;

    public static void main(String [] args)
    {
        Main_BFS mm = new Main_BFS();
        String str;
        while (true)
        {
            mm.block = 0;

            mm.m = sc.nextInt();
            mm.n = sc.nextInt();
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

            for (int i = 0; i < mm.m; ++i)
            {
                for (int j = 0; j < mm.n; ++j)
                {
                    if (mm.oil[i][j] == '@' && !mm.visit[i][j])
                    {
                        mm.bfs(i, j);
                        ++mm.block;
                    }
                }
            }
            System.out.println(mm.block);

        }
    }

    private void bfs(int i, int j) {
        Node now = new Node(i, j);
        queue.add(now);

        while (!queue.isEmpty())
        {
            now = queue.poll();
//            visit[now.x][now.y] = true;

            for (int k = 0; k < 8; ++k)
            {
                Node next = new Node(now.x + dis[k][0], now.y + dis[k][1]);
                if (isRight(next))
                {
                    queue.add(next);
                    visit[next.x][next.y] = true;
                }
            }
        }
    }

    public boolean isRight(Node now)
    {
        if (now.x < 0 || now.x >= m || now.y < 0 || now.y >= n)
            return false;
        if (visit[now.x][now.y])
            return false;
        if (oil[now.x][now.y] == '*')
            return false;
        return true;
    }

}

class Node{
    int x;
    int y;
    public Node(int i, int j)
    {x = i; y = j;}

}
