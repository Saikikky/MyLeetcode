
/**
 * 130. Surrounded Regions
 * 解法是从边界往里进行dfs如果有'O'就将其标记
 * 最后将所有标记的'O'保留 其他变为'X'
 */

class Solution {
    public static void solve(char[][] board) {
        if(board == null || board.length <= 2) return;
        // 行数
        int row = board.length;
        // 列数
        int col = board[0].length;

        // 先从左右边界开始
        for (int i = 0; i < row; i++) {
            // 左边界
            if (board[i][0] == 'O') DFS(board, row, col, i, 0);
            // 右边界
            if (board[i][col - 1] == 'O') DFS(board, row, col, i, col-1);
        }

        // 从上下边界开始
        for (int j = 0; j < col; j++) {
            // 上边界
            if (board[0][j] == 'O') DFS(board, row, col, 0, j);
            // 下边界
            if (board[row - 1][j] == 'O') DFS(board, row, col, row - 1, j);
        }


        // 将数组修改成要输出的样式
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == '#') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }

    public static void DFS(char[][] board, int row, int col, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = '#';
            if (i - 1 > 0 && board[i-1][j] == 'O') DFS(board, row, col, i - 1, j);
            if (j - 1 > 0 && board[i][j - 1] == 'O') DFS(board, row, col, i, j - 1);
            if (i + 1 < row - 1 && board[i + 1][j] == 'O') DFS(board, row, col, i + 1, j);
            if (j + 1 < col - 1 && board[i][j + 1] == 'O') DFS(board, row, col, i, j + 1);
        }
    }

    public static void main(String[] args) {
        char[][] board = {{'X','X','X','X'},{'X', 'O', 'O', 'X'}, {'X','X','O','X'}, {'X','O','X','X'}};
        solve(board);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                System.out.print(board[i][j]);
            }
            System.out.println();
        }
    }


}