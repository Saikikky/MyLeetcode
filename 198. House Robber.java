class Solution {
    public int rob(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];
        int[] arr = new int[nums.length];
        arr[0] = nums[0];
        // 只有两家时选最大的
        arr[1] = nums[1] > nums[0] ? nums[1] : nums[0];
        // 大于两家的时候
        // 这一家的价值num[i]+num[i-2]>num[i-1] 选较大值作为第i家的最大价值
        for (int i = 2; i < nums.length; i++) {
            arr[i] = (nums[i] + arr[i - 2]) > arr[i - 1] ? nums[i] + arr[i-2] : arr[i-1];
        }
        return arr[nums.length - 1];
    }
}