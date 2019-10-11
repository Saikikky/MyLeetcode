class Solution {
    public int removeDuplicates(int[] nums) {
        int temp = Integer.MIN_VALUE;
        int i = 0;
        for (int j = 0; i < nums.length && j  < nums.length; ) {

            // 与之前的重复
            if (nums[j] == temp) {
                j++;
            } else {
                // 不与之前的重复
                nums[i] = nums[j];
                temp = nums[i];
                i++;
                j++;
            }
        }
        return i;
    }
}