class Solution {
    public void nextPermutation(int[] nums) {
        int i = nums.length - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = nums.length - 1;
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }
            if (nums[j] > nums[i]) {
                swap(nums, i, j);
            }
            int k1 = i + 1;
            int k2 = nums.length - 1;
            while (k1 < k2) {
                swap(nums, k1, k2);
                k1++;
                k2--;
            }
        } else {
            Arrays.sort(nums);
        }
        
    }
    
    public void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}