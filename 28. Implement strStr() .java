class Solution {
    public int strStr(String haystack, String needle) {
        int strLen = haystack.length(), subLen = needle.length();
        if (subLen == 0) {
            return 0;
        }
        for (int index = 0; index < strLen; index++) {
            // 第一个字符不匹配
            if (haystack.charAt(index) != needle.charAt(0)) {
                continue;
            }
            // 超出长度 不匹配
            if (index + subLen > strLen) {
                break;
            }
            int temp = index + 1;
            // 完全相同则 tmp == index + subLen 
            for(;temp < index + subLen; temp++){
                if (haystack.charAt(temp) != needle.charAt(temp - index)) {
                    break;
                }

            }

            if (temp == index + subLen) {
                return index;
            }
        }
        return -1;
    }
}