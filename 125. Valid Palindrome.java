///////时间很长要20s
class Solution {
    public boolean isPalindrome(String s) {
        if (s.length() == 0) return true;
        // // 去掉首尾空格 用于判断空字符串
        // if (s.trim().isEmpty()) return true;
        // // 去掉空格
        // s = s.replaceAll(" ", "");
        s = s.toLowerCase();
        s = s.replaceAll("[^0-9a-z]", "");
        for (int i = 0, j = s.length() - 1; i <= j; i++, j--) {
            if (s.charAt(i) != s.charAt(j)) return false;
        }
        return true;
    }
}


// 需要7s
class Solution {
    public boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        s = s.toLowerCase();
        while(i < j) {
            if (!Character.isLetterOrDigit(s.charAt(i))) {
                i++;
                continue;
            }
            if (!Character.isLetterOrDigit(s.charAt(j))) {
                j--;
                continue;
            }               
            if (s.charAt(j) != s.charAt(i)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}