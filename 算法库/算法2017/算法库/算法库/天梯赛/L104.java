import java.util.Scanner;

/**
 * Created by wang on 16/7/8.
 */
public class L104 {
    public static void main(String [] args)
    {
        int n;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        System.out.print("Celsius = " + 5 * (n - 32) / 9);
    }
}
