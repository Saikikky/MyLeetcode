import java.util.Scanner;

/**
 * Created by wang on 16/7/10.
 */
public class L109 {

    public static void main(String [] args)
    {
        int n;
        String str;
        String [] a;
        int []fenzi = new int[100];
        int []fenmu = new int[100];
        int fenmuchengji = 1;
        int fenzisum = 0;
        int gongyueshu, fenzians, fenmuans, zhengshu;
        String [] temp;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        sc.nextLine();
        str = sc.nextLine();
        a = str.split(" ");

        for (int i = 0; i < n; ++i)
        {
            temp = a[i].split("/");
            fenzi[i] = Integer.parseInt(temp[0]);
            fenmu[i] = Integer.parseInt(temp[1]);
            fenmuchengji *= fenmu[i];
        }

        for (int i = 0; i < n; ++i)
        {
            fenzisum += fenmuchengji / fenmu[i] * fenzi[i];
        }

        L109 s = new L109();
        if (fenzisum < 0)
        {
            gongyueshu = s.A(-1 * fenzisum, fenmuchengji);
            fenzians = fenzisum / gongyueshu;
            fenmuans = fenmuchengji / gongyueshu;

            if (-fenzians % fenmuans == 0)
            System.out.print(fenzians / fenmuans);
            else if (-fenzians < fenmuans)
            {
                System.out.print(fenzians + "/" + fenmuans);
            }
            else
                System.out.print(fenzians / fenmuans + " " + fenzians % fenmuans + "/" + fenmuans);

        }
        else if (fenzisum == 0)
        {
            System.out.print(0);
        }
        else
        {
            gongyueshu = s.A(1 * fenzisum, fenmuchengji);
            fenzians = fenzisum / gongyueshu;
            fenmuans = fenmuchengji / gongyueshu;

            if (fenzians % fenmuans == 0)
                System.out.print(fenzians / fenmuans);
            else if (fenzians < fenmuans)
            {
                System.out.print(fenzians + "/" + fenmuans);
            }
            else
                System.out.print(fenzians / fenmuans + " " + fenzians % fenmuans + "/" + fenmuans);
        }
    }

    public int A(int n, int m)
    {
        if (m <= n)
            if (n % m == 0)
                return m;
            else
                return A(m, n % m);
        else
            return A(m, n);
    }
}
