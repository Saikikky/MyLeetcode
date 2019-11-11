class Solution {
    
    int[] tag;
    List<List<Integer>> results;
    
    public List<List<Integer>> permute(int[] nums) {
        tag = new int[nums.length];
        results = new ArrayList<>();
        DFS(nums, 0, new int[nums.length]);
        return results;
    }
    
    public void DFS(int[] nums, int x, int[] stack) {
        if (x == nums.length) {
            results.add(Arrays.stream(stack).boxed().collect(Collectors.toList()));
        } else {
            for (int i = 0; i < nums.length; i++) {
                if (tag[i] == 0) {
                    tag[i] = 1;

                    stack[x] = nums[i];
                    DFS(nums, x + 1, stack);

                    tag[i] = 0;

                }
            }
        }
    }
}