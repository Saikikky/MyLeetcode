import java.util.HashSet;
import java.util.Scanner;

/**
 * 最长公共子序列LCS
 *
 dp[i, j] = 0 (i = 0 || j = 0)
 dp[i, j] = dp[i-1, j-1] + 1 (ch1[i] = ch2[j])
 dp[i, j] = max(dp[i - 1, j], dp[i, j - 1])(ch1[i]!=ch2[j])
 */


public class Solution {

    static int dp[][];
    // 记录方向 1为左上 2为左 3为上
    static int direct[][];
    static int lcs;
    public static void LCS(char[] ch1, char[] ch2) {
        // 这里的存储从1开始 但字符串从0开始
        for (int i = 1; i < ch1.length + 1; i++) {
            for (int j = 1; j < ch2.length + 1; j++) {
                if (ch1[i - 1] == ch2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    direct[i][j] = 1;
                } else if(dp[i][j - 1] > dp[i - 1][j]){
                    dp[i][j] = dp[i][j - 1];
                    direct[i][j] = 2;
                } else {
                    dp[i][j] = dp[i - 1][j];
                    direct[i][j] = 3;
                }
                if (dp[i][j] > lcs) lcs = dp[i][j];
            }
        }

    }

    /**
     * 用于输出一个LCS 用方向标记
     * @param ch1
     * @param i
     * @param j
     */
    public static void Output(char[] ch1, int i, int j) {
        if (i == 0 || j == 0) return;
        System.out.println("i" + i + " j" + j);
        if (direct[i][j] == 1) {
            Output(ch1, i - 1, j - 1);
            System.out.print(ch1[i - 1]);
        } else if (direct[i][j] == 2){
            Output(ch1, i, j - 1);
        } else {
            Output(ch1, i - 1, j);
        }
    }

    /**
     * 输出所有的最长公共子序列
     * 若dp[i][j] => ch1[i-1][j-1] = ch2[i-1][j-1] 将该字符存入string中 接着进行dp[i-1][j-1]的判断
     * 若上述不成立，则比较左和上两个格子中的最大值 选择更大的那个进入上述操作
     * 若左上相等则，左和上都要进行回溯判断
     * @param ch1
     * @param ch2
     * @param i
     * @param j
     */
    public static void OutputAll(char[] ch1, char[] ch2, int i, int j) {
        StringBuffer sb = new StringBuffer();
        while (i >0 && j > 0) {
            if (ch1[i - 1] == ch2[j - 1]) {
                sb.append(ch1[i - 1]);
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) //向左走
                    --i;
                else if (dp[i - 1][j] < dp[i][j - 1]) //向上走
                    --j;
                else { //此时向上向右均为LCS的元素
                    OutputAll(ch1, ch2, i - 1, j);
                    OutputAll(ch1, ch2, i, j - 1);
                    return;
                }
            }
        }
        System.out.println(sb);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String x = sc.nextLine();
        String y = sc.nextLine();
        char[] ch1 = x.toCharArray();
        char[] ch2 = y.toCharArray();
        // 此处要多存储一行0；
        dp = new int[ch1.length + 1][ch2.length + 1];
        direct = new int[ch1.length + 1][ch2.length + 1];
        LCS(ch1, ch2);
        for (int i = 0; i < ch1.length + 1; i++) {
            for (int j = 0; j < ch2.length + 1; j++) {
                System.out.print(dp[i][j]);
            }
            System.out.println();
        }
        System.out.println();
        for (int i = 0; i < ch1.length + 1; i++) {
            for (int j = 0; j < ch2.length + 1; j++) {
                System.out.print(direct[i][j]);
            }
            System.out.println();
        }
        OutputAll(ch1, ch2, ch1.length, ch2.length);

    }
}