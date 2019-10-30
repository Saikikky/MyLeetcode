/**
递归暴力解法 但要判断最后生成的串是否有效
**/
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> combination = new ArrayList<>();
        generateAll(new char[2*n], 0, combination);
        return combination;

    }
    
    public void generateAll(char[] current, int pos, List<String> result) {
        if (pos == current.length) {
            if (valid(current)) {
                result.add(new String(current));
            }
        } else {
            current[pos] = '(';
            generateAll(current, pos+1, result);
            current[pos] = ')';
            generateAll(current, pos+1, result);
        }
    }

    public boolean valid(char[] current) {
        int balance = 0;
        for (char c : current) {
            if (c == '(') balance++;
            else balance--;
            if (balance < 0) return false;
        }
        return (balance == 0);
    }
}