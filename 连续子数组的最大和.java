public class Solution {
    public int FindGreatestSumOfSubArray(int[] array) {
        int[] dp = new int[array.length];
        for (int i = 0; i < array.length; i++) {
            if (i - 1>= 0) {
                dp[i] = Math.max(dp[i-1]+array[i], array[i]);
            } else {
                dp[i] = array[i];
            }
        }
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < dp.length; i++) {
            if (dp[i] > max) max = dp[i];
        }
        return max;
    }
}