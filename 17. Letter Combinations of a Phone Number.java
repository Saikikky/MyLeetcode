class Solution {
    public List<String> letterCombinations(String digits) {
        LinkedList<String> queue = new LinkedList<>();
        if (digits == null || digits.length() == 0) return queue;

        char[] dc = digits.toCharArray();

        String[] buttons = new String[]{"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        queue.offer("");

        for (int i = 0; i < dc.length; i++) {
            char[] letters = buttons[Character.getNumericValue(dc[i])].toCharArray();
            while (queue.peek().length() == i) {
                String row = queue.poll();
                for (char l : letters) {
                    queue.offer(row + l);
                }
            }
        }
        return queue;
    }
}