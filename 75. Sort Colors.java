class Solution {
    public void sortColors(int[] nums) {
        if (nums == null) return;
        int p0 = 0, p2 = nums.length - 1, cur = 0;
        while (cur <= p2) {
            if (nums[cur] == 2) {
                int temp = nums[cur];
                nums[cur] = nums[p2];
                nums[p2] = temp;
                p2--;
            } else if (nums[cur] == 1) {
                cur++;
            } else {
                int temp = nums[cur];
                nums[cur] = nums[p0];
                nums[p0] = temp;
                p0++;
                cur++;
            }
        }
    }
}