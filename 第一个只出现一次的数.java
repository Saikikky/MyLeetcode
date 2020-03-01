import java.util.HashMap;
import java.util.Map;
public class Solution {
    public int FirstNotRepeatingChar(String str) {
       Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < 26; i++) {
            map.put((char)(65+i), -1);
            map.put((char)(97+i), -1);
        }
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (map.containsKey(ch)) {
                if (map.get(ch) == -1) {
                    // 更新位置
                    map.put(ch, i);
                } else {
                    // 不止一次出现 直接删除
                    map.remove(ch);
                }
            }
        }

        int index = -1;
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            if (entry.getValue() == -1) continue;
            if (index == -1) index = entry.getValue();
            else {
                if (index > entry.getValue()) index = entry.getValue();
            }
        }

        return index;
    }
}