class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder stringBuilder = new StringBuilder("");
        int i = num1.length() - 1, j = num2.length() - 1, tag = 0;
        while (i >= 0 || j >= 0){
            int n1 = i >= 0 ? num1.charAt(i) - '0' : 0;
            int n2 = j >= 0 ? num2.charAt(j) - '0' : 0;
            int temp = n1 + n2 + tag;
            tag = temp / 10;
            stringBuilder.append(temp % 10);
            i--;
            j--;
        }
        if (tag == 1) stringBuilder.append(1);
        return stringBuilder.reverse().toString();
    }
}