class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int sum = nums[0] + nums[1] + nums[2];
        for (int k = 0; k < nums.length - 2; k++) {
            int i = k + 1, j = nums.length - 1;
            while (i < j) {
                int temp = nums[k] + nums[i] + nums[j];
                if (Math.abs(temp - target) < Math.abs(sum - target)) {
                    sum = temp;
                }
                if (temp < target) {
                    i++;
                } else if (temp > target) {
                    j--;
                } else {
                    return sum;
                }
            }

        }
        return sum;

    }
}