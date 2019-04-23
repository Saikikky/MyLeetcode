import java.util.ArrayList;
import java.util.Dictionary;
import java.util.Hashtable;

/**
 * Created by Treasure_ on 16/3/6.
 */
//
//public class Main
//{
//
//    int [][] a= new int[6][5];
//    int n = 5, m = 4;
//
//    public int dp(int i, int j)
//    {
//        if (i > n || j > m)
//            return 0;
//        if (a[i][j] != 0) return a[i][j];
//        if (i == n || j == m)
//            return 1;
//        else
//            return a[i][j] = dp(i + 1, j) + dp(i, j + 1);
//    }
//
//    public static void main(String [] args)
//    {
//        Main mm = new Main();
//        System.out.print(mm.dp(1, 1));
//    }
//}


public class Main
{
    int []m = {0, 1, 2, 3, 4, 5, 9, 7, 8, 6};
    int []a = new int[10000];
    int n = 4;
    int q1, q2;
//    ArrayList<Integer> al1 = new ArrayList<>();
//    ArrayList<Integer> al2 = new ArrayList<>();
    Hashtable<Integer, Integer> al1 = new Hashtable<>();
    Hashtable<Integer, Integer> al2 = new Hashtable<>();

    public void dfs(int k)
    {
        if (k == n + 1)
        {
            q1 = a[1] * 1000 + a[2] * 100 + a[3] * 10 + a[4];
            q2 = m[a[4]] * 1000 + m[a[3]] * 100 + m[a[2]] * 10 + m[a[1]];
            if (q1 - q2 <= 300 && q1 - q2 >= 200)
            {
                al1.put(q1, q1 - q2);
//                System.out.println(a[1]+" " +a[2]+" " + a[3]+" "+a[4]+"     " +  m[a[4]] + " " + m[a[3]]  + " " + m[a[2]] + " " +m[a[1]]);

            }
        }
        else
        {
            for (int i = 0; i <= 9; i++)
            {
                    a[k] = i;
                    dfs(k + 1);
            }
        }
    }


    public void dfs1(int k)
    {
        if (k == n + 1)
        {
            q1 = a[1] * 1000 + a[2] * 100 + a[3] * 10 + a[4];
            q2 = m[a[4]] * 1000 + m[a[3]] * 100 + m[a[2]] * 10 + m[a[1]];
            if (q2 - q1 <= 900 && q2 - q1 >= 800)
                al2.put(q1, q2 - q1);
        }
        else
        {
            for (int i = 0; i <= 9; i++)
            {
                a[k] = i;
                dfs1(k + 1);
            }
        }
    }

    public static void main(String [] args)
    {
        Main mm = new Main();

        mm.dfs(1);
        mm.dfs1(1);
        for (int i:mm.al1.keySet())
        {
            for (int j :mm.al2.keySet())
            {
                if (mm.al1.get(i) - mm.al2.get(j) == -558)
                    System.out.println(i + "  " + j);
            }
        }
    }
}