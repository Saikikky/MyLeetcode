/**
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
**/

// 斐波那契f(n) = f(n-1)+f(n-2)

public class Solution {
    public int RectCover(int target) {
        if (target == 0) return 0;
        if (target == 1 || target == 2) return target;
        int a = 0, b = 1;
        for (int i = 1; i <= target; i++) {
            b += a;
            a = b - a;
        }
        return b;
    }
}