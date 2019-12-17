/**
数组 [ 1 2 2 ] 
[ ] 的所有子串 [ ]
[ 1 ] 的所有子串 [ ] [ 1 ] 
[ 1 2 ] 的所有子串 [ ] [ 1 ] [ 2 ][ 1 2 ]
[ 1 2 2 ] 的所有子串 [ ] [ 1 ] [ 2 ] [ 1 2 ] [ 2 ] [ 1 2 ] [ 2 2 ] [ 1 2 2 ] 
记住新解的位置从新解开始增加 原先没有重复的元素的时候是直接将所有的结果增加`
**/
class Solution {

    List<List<Integer>> results;
    // boolean[] flag;
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        results = new ArrayList<>();
        // 添加空数字为其中一个结果
        results.add(new ArrayList<>());
        // 保存每一步的新解开始的位置
        int start = 1;
        for (int i = 0; i < nums.length; i++) {
            List<List<Integer>> result = new ArrayList<>();
            for (int j = 0; j < results.size(); j++) {
                List<Integer> ans = results.get(j);
                // 若有重复数字跳过
                if (i > 0 && nums[i] == nums[i - 1] && j < start) {
                    continue;
                }
                List<Integer> temp = new ArrayList<>(ans);
                temp.add(nums[i]);
                result.add(temp);
            }

            // 新解的位置
            start = results.size();
            results.addAll(result);
        }
        return results;
    }










class Solution {

    List<List<Integer>> results;
    boolean[] flag;
    public List<List<Integer>> subsetsWithDup(int[] nums) {
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
            Collections.sort(result);
            if (!results.contains(result)) {
                results.add(result);
            }

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