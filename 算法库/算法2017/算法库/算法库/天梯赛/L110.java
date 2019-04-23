import java.util.Arrays;
import java.util.Scanner;

/**
 * Created by wang on 16/7/10.
 */
public class L110 {
    public static void main(String [] args)
    {
        int [] a = new int[3];
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 3; ++i)
            a[i] = sc.nextInt();

        Arrays.sort(a);
        for (int i = 0; i < 2;  ++i)
            System.out.print(a[i] + "->");

        System.out.print(a[2]);
    }
}
