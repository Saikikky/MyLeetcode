class Solution {
    List<List<Integer>> results;
    boolean[] flag;

    public List<List<Integer>> combine(int n, int k) {
        results = new ArrayList<>();
        flag = new boolean[n + 1];
        dfs(1, n, 0, new int[k]);
        return results;
    }

    public void dfs(int start, int n, int x, int[] param) {
        if (x == param.length) {
            List<Integer> result = Arrays.stream(param).boxed().collect(Collectors.toList());
            results.add(result);
        } else {
            for (int i = start; i < n + 1; i++) {
                if (flag[i] == false) {
                    param[x] = i;
                    flag[i] = true;

                    dfs(i + 1, n, x + 1, param);

                    flag[i] = false;

                }
            }
        }
    }
}