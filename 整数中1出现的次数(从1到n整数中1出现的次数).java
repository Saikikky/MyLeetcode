public class Solution {
    public int NumberOf1Between1AndN_Solution(int n) {
        if (n < 1) return 0;
        int count = 0;
        for (int i = 1; i <= n; i *= 10) {
            int divider = i*10;
            count += (n / divider) * i;
            if (n % divider > 2*i-1) count += i;
            else if (n % divider < i) count += 0;
            else count += (n % divider) - i + 1;
        }
        return count;
    }
}