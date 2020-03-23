class Solution {
    public int trap(int[] height) {
        int ans = 0;
        int length = height.length;
        for (int i = 1; i < length; i++) {
            int max_left = 0, max_right = 0;
            for (int j = i; j >= 0; j--) {
                // 往左边找到最大值
                max_left = Math.max(max_left, height[j]);
            }
            for (int j = i; j < length; j++) {
                // 往右边找到最大值
                max_right = Math.max(max_right, height[j]);
            }
            ans += Math.min(max_left, max_right) - height[i];
        }
        return ans;
    }
}