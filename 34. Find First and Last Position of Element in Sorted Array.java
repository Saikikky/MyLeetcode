class Solution {
    public int[] searchRange(int[] nums, int target) {
        if (nums == null || nums.length == 0) return new int[]{-1,-1};
        // 起始位置
        int start = -1, end = -1;
        int left = 0, right = nums.length - 1;
        int res = -1;
        if (left == right && nums[left] == target) return new int[]{left, left};
        while (left <= right) {
            int mid = (left + right)/2;
            if (nums[mid] == target) {
                res = mid;
                break;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        System.out.println(res);
        if (res != -1) {
            start = res;
            int k = res - 1;
            while (k >= 0) {
                if (nums[k] == target) {
                    start = k < start ? k : start;
                }
                k--;
            }
            end = res;
            k = res + 1;
            while (k < nums.length) {
                if (nums[k] == target) {
                    end = k > end ? k : end;
                }
                k++;
            }
        }
        if (start == -1 && end == -1) return new int[]{-1,-1};
        else return new int[]{start, end};
    }
}