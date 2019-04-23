/**
 * Created by Treasure_ on 16/5/21.
 */
public class LCS {


    int [][] a = new int[100][100];
    static String s1 = "abcdefgmn";
    static String s2 = "zxcdefxmn";
    public static void main(String []args)
    {
        LCS ll = new LCS();
        System.out.print(ll.Lcs(s1.length() - 1, s2.length() - 1));
    }

    public int Lcs(int i, int j)
    {
        if (a[i][j] != 0)
            return a[i][j];
        if (i == 0 || j == 0)
            return a[i][j] = 0;
        else if (s1.charAt(i) == s2.charAt(j))
            return a[i][j] = Lcs(i - 1, j - 1) + 1;
        else
            return max(Lcs(i - 1, j), Lcs(i, j - 1));

    }

    private int max(int i, int j) {
        if (i > j)return i;
        else return j;
    }
}
