class Solution {
    public int romanToInt(String s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            // 小数在大数前面
            if (i + 1 < s.length() && getVal(s.charAt(i)) < getVal(s.charAt(i + 1))) {
                sum -= getVal(s.charAt(i));
            } else {
                sum += getVal(s.charAt(i));
            }
        }
        return sum;
    }

    int getVal(char c) {
        if (c == 'I') {
            return 1;
        }
        else if (c == 'V') {
            return 5;
        }
        else if (c == 'X') {
            return 10;
        }
        else if (c == 'L') {
            return 50;
        }
        else if (c == 'C') {
            return 100;
        }
        else if (c == 'D') {
            return 500;
        }
        else if (c == 'M') {
            return 1000;
        }
        else {
            return 0;
        }
    }
}