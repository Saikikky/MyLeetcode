class Solution {
    public int myAtoi(String str) {
         // 去掉空格
        str = str.trim();
        if (str == null || str.length() == 0) return 0;
        // 判断第一个是否为正负号
        char c = str.charAt(0);
        boolean tag = true;
        int start = 0;
        if (c == '+') {
            tag = true;
            start++;
        }
        else if (c == '-') {
            tag = false;
            start++;
        } else if (!Character.isDigit(c)) {
            return 0;
        }
        long sum = 0;
        for (int i = start; i < str.length(); i++) {
            c = str.charAt(i);
            if (Character.isDigit(c)) {
                sum = sum * 10 + c - '0';
                if (sum > Integer.MAX_VALUE && tag == true) return Integer.MAX_VALUE;
                else if (sum > Integer.MAX_VALUE && tag == false) return Integer.MIN_VALUE;
            } else break;
        }


        return tag == true ? (int)sum : (int)-sum;
    }
}