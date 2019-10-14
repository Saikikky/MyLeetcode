/**
 * 跳台阶
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
 */

/*
public class Solution {
    public static int JumpFloor(int target) {
        if (target == 1) {
            return 1;
        } else if (target == 2) {
            return 2;
        } else {
            return JumpFloor(target - 1) + JumpFloor(target - 2);
        }
    }
    public static void main(String[] args) {
        System.out.println(JumpFloor(4));
    }

}*/

/**
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * f(n)=f(n-1)+f(n-2)+f(n-3)+...+f(n-(n-1))+f(n-n)
 *     =f(0)+f(1)+f(2)+f(3)+...+f(n-1)
 * f(n-1)=f(0)+f(1)+f(2)+...+f(n-2)
 * f(n)=f(n-1)+f(n-1)=2*f(n-1)
 */

public class Solution {
    public int JumpFloorII(int target) {
        if (target < 1) return -1;
        else if (target == 1) return 1;
        else return 2*JumpFloorII(target-1);
    }
}

class Solution {
    public int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
}
