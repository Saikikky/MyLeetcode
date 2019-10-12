class Solution {
    public int searchInsert(int[] nums, int target) {
        int i = 0;
        if (nums[0] > target) {
            return 0;
        }
        for (; i < nums.length; i++) {
            if (nums[i] == target) {
                return i;
            } else if (nums[i] < target && i + 1 < nums.length && nums[i + 1] > target) {
                return i + 1;
            }
        }
        return i;
    }
}