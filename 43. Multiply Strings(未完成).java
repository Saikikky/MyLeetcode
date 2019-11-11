class Solution {
    
    private static List<List<Integer>> result = new ArrayList<>();
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> result = new ArrayList<>();
        if (candidates == null || candidates.length == 0) return result;
        Arrays.sort(candidates);
        dfs(candidates, target, 0, new Stack<>(), result);
        return result;
    }
    
    public void dfs(int[] candidates, int target, int start, Stack<Integer> stack, List<List<Integer>> result) {
        if (target == 0) {
            List<Integer> list = new ArrayList<>(stack);
            if (!result.contains(list)) {
                result.add(new ArrayList<>(stack));
            }

        } else {
            for (int i = start; i < candidates.length && target - candidates[i] >= 0; i++) {
                stack.add(candidates[i]);
                dfs(candidates, target - candidates[i], i+1, stack, result);
                stack.pop();
            }
        }
    }
}