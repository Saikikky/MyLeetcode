class Solution {
    public String convertToTitle(int n) {
        StringBuilder stringBuilder = new StringBuilder();
        char c = ' ';
        while (n > 0){
            if (n % 26 == 0){
                stringBuilder.append('Z');
                n=n/26-1;
            }else {
                c = (char) ((n % 26) + 64);
                stringBuilder.append(c);
                n = n / 26;
            }
        }
        return String.valueOf(stringBuilder.reverse());
    }
}