class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length <= 1) return nums.length;
        // 新插入的应该写入current+1
        int current = 1;
        // 前两个数字符合条件，从第三个开始
        for (int i = 2; i < nums.length; i++) {
            if (nums[i] != nums[current-1]) {
                current++;
                nums[current] = nums[i];
            }
        }
        return current+1;
    }
}