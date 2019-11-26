class Solution {

    boolean[][] flag;
    int length;
    String word;
    char[][] board;
    int[][] direction = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    int rowLength;
    int colLength;

    public boolean exist(char[][] board, String word) {
        if (board == null && board.length == 0) return false;

        rowLength = board.length;
        colLength = board[0].length;
        flag = new boolean[rowLength][colLength];
        char[] words = word.toCharArray();
        length = words.length;

        this.board = board;
        this.word = word;

        for (int i = 0; i < rowLength; i++) {
            for (int j = 0; j < colLength; j++) {
                if (dfs(i, j, 0)) return true;
            }
        }
        return false;
    }

    public boolean dfs(int i, int j, int start) {
        if (start == word.length() - 1) {
//            if (word.charAt(start) == board[i][j]) return true;
            return board[i][j] == word.charAt(start);
        } else {
            if (board[i][j] == word.charAt(start)) {
                flag[i][j] = true;
                for (int k = 0; k < 4; k++) {
                    int x = i + direction[k][0];
                    int y = j + direction[k][1];
                    if (isArea(x, y) && !flag[x][y]) {
                        if (dfs(x, y, start+1)) return true;
                    }
                }
                flag[i][j] = false;
            }
        }
        return false;
    }

    public boolean isArea(int i, int j) {
        if (i >= 0 && i < rowLength && j >= 0 && j < colLength) return true;
        return false;
    }
}