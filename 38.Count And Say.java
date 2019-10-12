class Solution {
    public String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        String str = countAndSay(n - 1) + "*";
        char[] chs = str.toCharArray();
        StringBuilder stringBuilder = new StringBuilder();
        // 用来记数(每一个数字出现几次)
        int count = 1;
        for (int i = 0; i < chs.length - 1; i++) {
            if (chs[i] == chs[i + 1]) {
                count++;
            } else {
                // 不同时将现有的加在 stringBuilder 后面
                stringBuilder.append("" + count + chs[i]);
                count = 1;
            }
        }
        return stringBuilder.toString();
    }
}