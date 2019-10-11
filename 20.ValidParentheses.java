class Solution {
    public boolean isValid(String s) {
        Stack<Character> strs = new Stack<Character>();
        for (int i = 0 ; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '[' || c == '{') {
                strs.push(c);
            }
            if (s.charAt(i) == ')') {
                if (!strs.empty()) {
                    if (strs.pop() != '(') {
                        return false;
                    }
                } else {
                    return false;
                }

            } else if (s.charAt(i) == '}') {
                if (!strs.empty()) {
                    if (strs.pop() != '{') {
                        return false;
                    }
                } else {
                    return false;
                }
            } else if (s.charAt(i) == ']') {
                if (!strs.empty()) {
                    if (strs.pop() != '[') {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        if (strs.empty()) {
            return true;
        }
        return false;
    }
}