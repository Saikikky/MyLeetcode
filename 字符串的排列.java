/**
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。

换句话说，第一个字符串的排列之一是第二个字符串的子串。

示例1:

输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
**/
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int length1 = s1.length();
        int length2 = s2.length();
        if (length1 > length2) return false;

        int[] num1 = new int[26];
        for (int i = 0; i < length1; i++) {
            num1[s1.charAt(i) - 'a']++;
        }

        int i = 0, j = i + length1 - 1;
        while (j < length2) {
            int[] num2 = new int[26];
            int flag = 0;
            for (int k = i; k <= j; k++) {
                num2[s2.charAt(k) - 'a']++;
            }
            for (int k = 0; k < 26; k++) {
                if (num2[k] - num1[k] != 0) {
                    flag++;
                    i++;
                    j++;
                    break;
                }
            }
            if (flag == 0) return true;
        }

        return false;
    }
}