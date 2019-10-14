class Solution {
    public int lengthOfLastWord(String s) {
        if (s.equals("") || s.trim().isEmpty()) return 0;
        String[] strings = s.split(" ");
        String string = strings[strings.length - 1];
        return string.length();
    }
}