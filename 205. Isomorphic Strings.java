class Solution {
    public boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) return false;
        if (s.length() == 0 && t.length() == 0) return true;
        StringBuilder sb = new StringBuilder();
        Map<Character, Character> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char chs = s.charAt(i);
            char cht = t.charAt(i);
            if (map.containsKey(chs) && map.get(chs) == cht) {
                continue;
            }
            // 若不存在map的key值且value值不存在就加入map
            if (!map.containsKey(chs) && !map.containsValue(cht)) {
                map.put(chs, cht);
            } else {
                return false;
            }

        }
        return true;
    }
}