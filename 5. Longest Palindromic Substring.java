/**
中心扩展法 21ms
**/
class Solution {
    public String longestPalindrome(String s) {
        // 中心扩展法
        if (s == null || s.length() == 0) return "";
        // 对串进行扩充，可以从中心扩展
        StringBuffer stringBuffer = new StringBuffer();
        for (int i = 0; i < s.length(); i++) {
            stringBuffer.append("#");
            stringBuffer.append(s.charAt(i));
        }
        stringBuffer.append("#");

        char chs[] = stringBuffer.toString().toCharArray();
        int max_lens = 0;
        int start = 0;
        for (int i = 0; i < chs.length; i++) {
            int temp = subPalindrome(chs, i);
            if (temp > max_lens) {
                max_lens = temp;
                start = i;
            }
        }
        String str = stringBuffer.substring(start - max_lens, start + max_lens);
        str = str.replaceAll("#", "");
        return str;
    }
    
    public int subPalindrome(char[] chars, int i) {
        int len = 0;
        for (int k = 0; k <= i && i + k < chars.length; k++) {
            if (chars[i - k] == chars[i + k]) len++;
            else break;
        }

        return len - 1;
    }
}


/**
动态规划 44ms
**/
class Solution {
    public String longestPalindrome(String s) {
        if (s == null || s.length() == 0) return "";
        char[] chars = s.toCharArray();
        boolean f[][] = new boolean[s.length()][s.length()];
        int start = 0;
        int max_len = 0;
        for (int j = 0; j < s.length(); j++) {
            for (int i = 0; i <= j; i++) {
                int temp = 0;
                if (j - i + 1 <= 2 && chars[i] == chars[j]) {
                    f[i][j] = true;
                    temp = j - i + 1;
                } else if (chars[i] == chars[j] && f[i + 1][j - 1]) {
                    f[i][j] = true;
                    temp = j - i + 1;
                }
                if (max_len < temp) {
                    max_len = temp;
                    start = i;
                }
            }
        }
        String str = s.substring(start, start + max_len);
        return str;
    }
}