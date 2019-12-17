class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        f(s, 0, result, new ArrayList<>());
        return result;
    }
    
    
    public void f(String s, int pos, List<String> result, List<String> cur) {
        if (cur.size() == 4) {
            if (pos == s.length()) {
                result.add(String.join(".", cur));
            }
            return;
        } else {
            // 每一段最多3个 若0必须单独为0 且不能超过255
            for (int i = 1; i < 4; i++) {
                if (pos + i > s.length()) {
                    break;
                }
                String seg = s.substring(pos, pos + i);
                if (seg.length()>1 && seg.startsWith("0") || Integer.parseInt(seg) > 255 && i == 3) continue;
                cur.add(seg);
                f(s, pos+i, result, cur);
                cur.remove(cur.size() - 1);
            }
        }
    }
}