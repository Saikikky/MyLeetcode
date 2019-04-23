/**
 * 合唱队问题 最长递增子序列变形
 * 假设第i（0<= i <= n - 1）个同学为最高点
 * 分别求出此时i左边的最长递增子序列长度inc1[i]
 * i右边的最长递减子序列长度inc2[i] 由于最高点i同时包括在了inc1[i]和inc2[i]之中
 * 因此实际的合唱队形的长度为inc1[i] + inc2[i] - 1
 * 而我们求得的最后结果就是i从1到n - 1中
 * 使得inc1[i] + inc2[i] - 1最大的情况。
 * 现在设i为下标，循环i从0到n-1，求得各种i值对应的inc1[i]；循环i从0到n-1，求得各种i值对应的inc2[i]。
 * 最后循环i从0到n-1，求得各种i值对应的inc[i] + inc2[i] - 1最大的情况ans，然后n - ans即为出列同学的人数。
 *
 */

import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // 人数
        int n = in.nextInt();
        // 保存每个人的身高
        int a[] = new int[n];
        // 递增序列的长度
        int inc1[] = new int[n];
        // 递减序列的长度
        int inc2[] = new int[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }

        inc1[0] = 1;
        for (int i = 1; i < n; i++) {
            inc1[i] = 1;
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j] && inc1[j] + 1 > inc1[i]) {
                    inc1[i] = inc1[j] + 1;
                }
            }
        }

        inc2[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            inc2[i] = 1;
            for (int j = n - 1; j > i; j--) {
                if (a[i] > a[j] && inc2[j] + 1 > inc2[i]) {
                    inc2[i] = inc2[j] + 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            int temp = inc1[i] + inc2[i] - 1;
            if (temp > ans) ans = temp;
        }

        System.out.println(n - ans);


    }
}
