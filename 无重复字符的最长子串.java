class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0 || s == null) return 0;
        if (s.length() == 1) return 1;
        Map<Character, Integer> map = new HashMap<>();
        int sum = 0;
        int max = 0;
        boolean tag = false;

        for (int i = 0; i < s.length(); i++) {
            map.clear();
            map.put(s.charAt(i), i);
            tag = false;
            for (int j = i + 1; j < s.length(); j++) {
                if (!map.containsKey(s.charAt(j))) {
                    map.put(s.charAt(j), j);
                }
                else {
                    sum = j - i;
                    if (max < sum) max = sum;
                    sum = 0;
                    tag = true;
                    break;
                }

            }
            if (tag == false) {
                sum = s.length() - i;
                if (max < sum) max = sum;
            }

        }
        return max;
    }
}