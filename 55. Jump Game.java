/**
k = max(k, i + nums[i]);
k表示当前可以跳到最远的地方（索引），i + nums[i] 代表站在索引（i）的格子上，
并且可以从这个格子能跳到最远的距离nums[i]。
这两个数值相比，较大的就可以继续保存成 k ，代表可以跳到最远的地方
**/
class Solution {
    boolean tag = false;
    public boolean canJump(int[] nums) {
        int k = 0;
        for (int i = 0; i < nums.length; i++) {
            if (i > k) return false;
            if (k >= nums.length) return true;
            k = Math.max(k, i + nums[i]);
        }
        return true;
    }
}

/** 回溯超时
public class JumpGame {

    static boolean tag = false;
    public static void main(String[] args) {
        int[] nums = {2,3,1,1,4};
        System.out.println(canJump(nums));
    }

    public static boolean canJump(int[] nums) {
        if (nums.length == 0 && nums == null) return true;
        dfs(nums, 0);
        return tag;
    }

    public static void dfs(int[] nums, int x) {
        if (x == nums.length - 1) {
            tag = true;
            return;
        } else if (x > nums.length - 1) return;
        else {
            int maxLength = nums[x];
            if (maxLength == 0) return;
            for (int i = maxLength; i >= 1; i--) {

                if (x + i < nums.length) {
                    dfs(nums, x+i);
                }

            }
        }
    }
}
**/
