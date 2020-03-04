class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        // 目标列表中不存在endword 不可能到达
        if (!wordList.contains(endWord)) return 0;

        List<String> visited = new ArrayList<>();

        //  存放过程
        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);
        visited.add(beginWord);

        int level = 1;
        // beginWord入队
        int curnum = 1;
        // 下一层
        int nextnum = 0;

        while (!queue.isEmpty()) {
            String s = queue.poll();
            System.out.println(s);
            curnum--;

            for (String word : wordList) {
                if (canTouch(s, word)) {
                    if (!visited.contains(word)) {
                        if (word.equals(endWord)) {
                            return level+1;
                        }
                        queue.offer(word);
                        nextnum++;
                        visited.add(word);
                    }

                }
            }


//            for (int i = 0; i < s.length(); i++) {
//                char[] chs = s.toCharArray();
//
//
//                for (int j = 0; j < 26; j++) {
//                    if (chs[i] != (char)(j+97)) {
//                        chs[i] = (char)(j+97);
//                    }
//                    String string = new String(chs);
//                    if (string.equals(endWord)) {
//                        return level+1;
//                    }
//                    if (wordList.contains(string)) {
//                        queue.offer(string);
//                        nextnum++;
//                        wordList.remove(string);
//                    }
//                }
//            }

            // 这一层节点完成
            if (curnum == 0) {
                curnum = nextnum;
                nextnum = 0;
                level++;
            }
        }
        return 0;
    }
    public boolean canTouch(String s1, String s2) {
        if (s1.length() != s2.length()) return false;
        int count = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                count++;
            }
        }
        if (count == 1) return true;
        else return false;
    }
}