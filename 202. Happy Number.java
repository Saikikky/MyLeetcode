class Solution {
    public boolean isHappy(int n) {
        Set<Integer> set = new TreeSet<>();
        // 用来存储平方
        int plus = 0;
        while (true) {
            while (n != 0) {
                plus += (int)Math.pow(n%10, 2);
                n /= 10;
            }
            if (plus == 1) return true;
            if (set.contains(plus)) return false;
            else {
                set.add(plus);
                n = plus;
                plus = 0;
            }
        }
    }
}