/**
 * 最大子序列和
 */

public class Solution {

    public static int  MaxSum(int[] a) {
        int maxSum = Integer.MIN_VALUE;
        int start = 0;
        int end = 0;
        int sum = 0;
        for (int i = 0; i < a.length; i++) {
            if (sum < 0) {
                sum = a[i];
                start = i;
            } else {
                sum += a[i];
            }
            if (sum > maxSum) {
                maxSum = sum;
                end = i;
            }
        }
        System.out.println(start);
        System.out.println(end);
        return maxSum;
    }

    public static void main(String[] args) {
        int[] a = {-1, 2, 4, -10, 2, 8};
        System.out.println(MaxSum(a));
    }
}