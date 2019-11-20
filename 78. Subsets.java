class Solution {
    List<List<Integer>> results;
    boolean[] flag;
    public List<List<Integer>> subsets(int[] nums) {
        results = new ArrayList<>();
        flag = new boolean[nums.length];
        for (int i = 0; i <= nums.length; i++) {
            dfs(0, nums, 0, new int[i]) ;
        }

        return results;
    }
    
    public void dfs(int start, int[] nums, int x, int[] param) {
        if (x == param.length) {
            List<Integer> result = Arrays.stream(param).boxed().collect(Collectors.toList());
            results.add(result);
        } else {
            for (int i = start; i < nums.length; i++) {
                if (flag[i] == false) {
                    param[x] = nums[i];
                    flag[i] = true;

                    dfs(i + 1, nums, x + 1, param);

                    flag[i] = false;

                }
            }
        }
    }
}