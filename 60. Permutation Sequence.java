class Solution {
    boolean[] tag;
    int sum;
    int[] result;
    StringBuilder stringBuilder;

    public String getPermutation(int n, int k) {
        tag = new boolean[n+1];
        result = new int[n + 1];
        dfs(n, 1, k); // n为总数 0为位置 k为第几个
        return stringBuilder.toString();
    }

    public void dfs(int n, int x, int k) {
        if (x == n+1) {
            sum++;
            if (sum == k) {
                stringBuilder = new StringBuilder();
                for (int i = 1; i <= n; i++) {
                    stringBuilder.append(result[i]+0);
                }
            }
        } else {
            for (int i = 1; i <= n; i++) {
                if (tag[i] == false) {
                    result[x] = i;
                    tag[i] = true;

                    dfs(n, x+1, k);
                    tag[i] = false;
                }
            }
        }
    }
}