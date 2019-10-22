class Solution {
    public int titleToNumber(String s) {
        int ans = 0;
        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            int num = chars[i] - 'A' + 1;
            ans = ans * 26 + num;
        }
        return ans;
    }
}