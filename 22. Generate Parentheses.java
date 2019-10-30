/**
动态规划
**/
class Solution {
    public List<String> generateParenthesis(int n) {
        LinkedList<LinkedList<String>> result = new LinkedList<>();
        if (n == 0) {
            return result.get(0);
        }
        LinkedList<String> list0 = new LinkedList<>();
        list0.add("");
        result.add(list0);
        LinkedList<String> list1 = new LinkedList<>();
        list1.add("()");
        result.add(list1);
        for (int i = 2; i <= n; i++) {
            LinkedList<String> temp = new LinkedList<>();
            for (int j = 0; j < i; j++) {
                LinkedList<String> str1 = result.get(j);
                LinkedList<String> str2 = result.get(i - 1 - j);
                for (String s1 : str1) {
                    for (String s2 : str2) {
                        String str = "(" + s1 + ")" + s2;
                        temp.add(str);
                    }
                }
            }
            result.add(temp);
        }
        return result.get(n);

    }
}