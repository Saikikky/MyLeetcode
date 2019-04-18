
/**
 * 最长递增子序列
 * a[i]的最长递增子序列长度L[i] 要么是1，
 * 要么是 L[j]+1 这里的L[j]是前i-1各元素中最长的递增子序列且a[j]<a[i]
 */

public class Solution {

    static int dp[];
    // 最长串长度
    static int lis;

    public static int MaxLength(int[] a) {
        for (int i = 0; i < a.length; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                int LIS = dp[j] + 1;
                if (a[j] < a[i] && dp[i] < LIS) {
                    dp[i] = LIS;
                    if (lis < dp[i]) lis = dp[i];
                }
            }
            System.out.println(i + ":" + dp[i]);
        }
        return lis;
    }

    public static void Output(int[] a, int index) {
        if (index < 0 || lis == 0) return;
        boolean isSelected = false;
        if (lis == dp[index]) {
            --lis;
            isSelected = true;
        }
        Output(a, index - 1);
        if (isSelected) System.out.print(a[index]);
    }

    public static void main(String[] args) {
        int[] a = {3, 1, 6, 4, 2, 9, 7, 4, 2, 7, 10};
        dp = new int[a.length];
        lis = MaxLength(a);
        System.out.println(lis);
        Output(a, a.length - 1);
    }
}