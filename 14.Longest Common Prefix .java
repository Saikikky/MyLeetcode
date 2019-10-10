class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }
        // 数组中的第一个字符串
        String ans = strs[0];
        for (int i = 1; i <= strs.length - 1; i++) {
            if (ans.equals("")) {
                return ans;
            }
            // 依次与 ans 比较
            String s = strs[i];
            int j = 0;
            for (; j < s.length() && j < ans.length(); j++) {
                if (s.charAt(j) != ans.charAt(j)) {
                    break;
                }
            }
            ans = ans.substring(0, j);
        }
        return ans;
    }
}