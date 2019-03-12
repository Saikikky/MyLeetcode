class Solution {
    public boolean isPalindrome(int x) {
        // 不转成字符串 直接求转置看是否一样
        if (x < 0) return false;
        int revert = 0, num = x;
        while (num != 0) {
            revert = revert * 10 + num % 10;
            num = num / 10;
        }
        if (x == revert) return true;
        return false;
        /*
        转成字符串
        String s = String.valueOf(x);
        int length = s.length();
        // 偶数
        for (int i = 0; i < length / 2; i++) {
            if (s.charAt(i) != s.charAt(length - 1 - i)) return false;
        }
        return true;
        */
    }
}