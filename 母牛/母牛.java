import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // 年份
        int n = in.nextInt();
        // 不同年龄的母牛
        int[] ages = new int[10];
        ages[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 9; j > 0; j--) {
                ages[j] = ages[j - 1];
            }
            ages[0] = ages[2] + ages[3] + ages[4] + ages[5] + ages[6];
            for (int j = 0; j < 10; j++) System.out.print(ages[j]);
            System.out.println();
        }
        int sum = 0;
        for (int i = 0; i < 10; i++) {
            sum += ages[i];
        }
        System.out.println(sum);
    }
}