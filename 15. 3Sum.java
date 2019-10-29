class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> results = new ArrayList<>();
        for (int k = 0; k < nums.length - 2; k++) {
            if (nums[k] > 0) continue;
            if (k - 1 >= 0 && nums[k] == nums[k - 1]) continue;
            int i = k + 1, j = nums.length - 1;
            while (i < j) {
                if (nums[k] + nums[i] + nums[j] == 0) {
                    List<Integer> result = new ArrayList<>();
                    result.add(nums[k]);
                    result.add(nums[i]);
                    result.add(nums[j]);
                    results.add(result);
                    while (i < j && nums[i] == nums[i + 1]) i++;
                    while (i < j && nums[j] == nums[j - 1]) j--;
                    i++;
                    j--;
                } else if (nums[k] + nums[i] + nums[j] < 0) {
                    i++;
                } else {
                    j--;
                }
            }
        }
        return results;
    }
}