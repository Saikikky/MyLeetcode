class Solution {
    boolean[] flag;
    int[][] direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public int findCircleNum(int[][] M) {
        if (M == null || M.length == 0) return 0;
        int row = M.length;
        flag = new boolean[row];
        int count = 0;
        for (int i = 0; i < row; i++) {
            if (!flag[i]) {
                helper(M, i);
                count++;
            }
        }
        return count;
    }

    public void helper(int[][] M, int i) {

        for (int j = 0; j < M.length; j++) {
            if (!flag[j] && M[i][j] == 1) {
                flag[j] = true;
                helper(M, j);
            }
        }
    }
}