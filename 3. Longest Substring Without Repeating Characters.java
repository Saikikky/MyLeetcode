class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> set = new HashSet<>();
        int ans = 0, i = 0, j = 0, n = s.length();
        while (i < n && j < n) {
            if (!set.contains(s.charAt(j))) {
                set.add(s.charAt(j));
                j++;
                ans = Math.max(ans, j -i);
            } else {
                set.remove(s.charAt(i));
                i++;
            }
        }
        return ans;
    }
}