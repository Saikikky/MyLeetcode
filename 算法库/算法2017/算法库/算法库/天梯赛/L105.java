import java.util.Scanner;

//中间两组数据超时
public class L105 {
    public static void main(String [] args)
    {
        int n, m;
        A [] p = new A[1001];

        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < n; ++i)
        {
            String s = sc.next();
            int k = sc.nextInt();
            p[k] = new A();
            p[k].a = s;
            p[k].c = sc.nextInt();
        }

        m = sc.nextInt();

        for (int i = 0; i < m; ++i)
        {
            int d = sc.nextInt();
            System.out.println(p[d].a + " " + p[d].c);
        }
    }
}

class A
{
    String a;
    int c;
}
