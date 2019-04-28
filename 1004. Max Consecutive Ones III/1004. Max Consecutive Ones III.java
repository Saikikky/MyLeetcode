/**
 * 滑动窗口解法(双指针)
 */
class Solution {
    public int longestOnes(int[] A, int K) {
        int max = 0;
        // 在当前窗口中0的个数
        int count = 0;
        // 窗口的下限
        int low = 0;
        // 寻找窗口
        for (int i = 0; i < A.length; i++) {
            // 往后挪上限指针
            if (A[i] == 0) count++;
            // 一旦窗口中的0的个数大于K就开始网上挪下限
            // 直至0的个数小于K
            while (count > K) {
                if (A[low] == 0) count--;
                low++;
            }
            max = Math.max(max, i - low + 1);
        }
        return max;
    }
}

/////////////////////////////////////////////////////
import java.util.Scanner;

/**
 * 回溯的递归写法(必然超时)
 */
/*
public class Main {
    // 最长相同子串初始化为0
    static int length = 0;
    static int n;
    static int k;
    static int[] a;

    // 做改变操作
    // 此时是第m次修改 若等于k次则跳出 但每次修改之后都要查看一下最长长度
    public static void DFS(int k, int m) {
        if (m == k || m > a.length) {
            int tempLength = Length();
            if (tempLength > length) length = tempLength;
        } else {
            for (int i = 0; i < a.length; i++) {
                if (a[i] == 0) {
                    a[i] = 1;
                    int tempLength = Length();
                    if (tempLength > length) length = tempLength;

                    DFS(k, m + 1);

                    a[i] = 0;

                }
            }
        }
    }

    // get最长相同子串长度
    public static int Length() {
        // 用于存放每个数的最长字串
        int[] flag = new int[n];
        if (a[0] == 1) flag[0] = 1;
        else flag[0] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] == 1 && a[i - 1] == 1) flag[i] = flag[i - 1] + 1;
            else if (a[i] == 1) flag[i] = 1;
            else flag[i] = 0;
        }
        int tempLength = flag[0];
        for (int i = 1; i < n; i++) {
            if (flag[i] > tempLength) tempLength = flag[i];
        }
        return tempLength;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        // n个整数
        n = in.nextInt();
        // k次变化机会
        k = in.nextInt();
        a = new int[n];
        int num0 = 0;
        for (int i = 0; i < n; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) num0++;
        }
        if (num0 == k) System.out.println(a.length);
        else {
            DFS(k, 0);

            System.out.println(length);
        }


    }
}*/