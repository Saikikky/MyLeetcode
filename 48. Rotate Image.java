class Solution {
    public void rotate(int[][] matrix) {
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < i; j++) {
                 int temp = matrix[i][j];
                 matrix[i][j] = matrix[j][i];
                 matrix[j][i] = temp;
            }
        }
        for (int i = 0; i < matrix.length; i++) {
            int k = 0, p = matrix.length - 1;
            while (k <= p) {
                int temp = matrix[i][k];
                matrix[i][k] = matrix[i][p];
                matrix[i][p] = temp;
                k++;
                p--;
            }
        }
    }

    public static void rotate1(int[][] matrix) {
        int length = matrix.length;
        // i代表起始位置 i=0是(0,0) i=1是(1,1)
        for (int i = 0; i < length / 2; i++) {
            // j代表当前正方形上的一条边上的一个点
            for (int j = i; j < length - i - 1; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[length-j-1][i];
                matrix[length-j-1][i] = matrix[length-i-1][length-j-1];
                matrix[length-i-1][length-j-1] = matrix[j][length-j-1];
                matrix[j][length-i-1] = temp;
            }
        }
    }
    
}