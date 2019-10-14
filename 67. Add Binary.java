class Solution {
    public String addBinary(String a, String b) {
        StringBuilder stringBuilder = new StringBuilder();
        int length1 = a.length();
        int length2 = b.length();
        int length = length1 > length2 ? length1 : length2;
        int gap = Math.abs(length1 - length2);
        char[] chars = new char[length];
        if (length1 < length2) {
            for (int i = 0; i < length; i++) {
                if (i < gap) chars[i] = '0';
                else chars[i] = a.charAt(i - gap);
            }
            a = String.valueOf(chars);
        } else {
            for (int i = 0; i < length; i++) {
                if (i < gap) chars[i] = '0';
                else chars[i] = b.charAt(i - gap);
            }
            b = String.valueOf(chars);
        }

        // 进位
        int temp = 0;
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 && j >= 0; i--, j--) {
            char s1 = a.charAt(i);
            char s2 = b.charAt(j);
            int n1 = s1 - '0';
            int n2 = s2 - '0';
            if (n1 + n2 + temp <= 1) {
                stringBuilder.append(n1 + n2 + temp);
                temp = 0;
            } else if (n1 + n2 + temp == 2) {
                temp = 1;
                stringBuilder.append(0);
            } else {
                temp = 1;
                stringBuilder.append(1);
            }
        }
        if (temp == 1) stringBuilder.append(1);
        stringBuilder.reverse();
        return stringBuilder.toString();

    }
}