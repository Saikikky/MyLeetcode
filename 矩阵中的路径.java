public class Solution {
    int[][] direction = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    boolean[][] flag;
    int r;
    int c;
     
    public boolean hasPath(char[] matrix, int rows, int cols, char[] str) {
        char[][] matrixs = new char[rows][cols];
        r = rows;
        c = cols;
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrixs[i][j] = matrix[k++];
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                flag = new boolean[rows][cols];
                boolean tag = dfs(matrixs, i, j, str, 0);
                if (tag == true) return true;
            }
        }
        return false;
    }
    public boolean dfs(char[][] matrixs, int rows, int cols, char[] str, int k) {
        if (k == str.length) return true;
        if (rows < 0 || rows >= r || cols < 0 || cols >= c) return false;
        if (flag[rows][cols] == true || matrixs[rows][cols] != str[k]) return false;
 
        flag[rows][cols] = true;
        for (int[] dir: direction) {
            if(dfs(matrixs, rows + dir[0], cols + dir[1], str, k + 1)) {
                return true;
            }
        }
        flag[rows][cols] = false;
        return false;
 
    }
 
 
}