/**
该题将一个有序数组转成平衡二叉树
从中位数做根节点递归创建左右子数
**/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode sortedArrayToBST(int[] nums) {
        return makeTree(nums, 0, nums.length - 1);
    }
    public TreeNode makeTree(int[] nums, int from, int to) {
        if (from > to) return null;
        int mid = (from + to) / 2;
        TreeNode treeNode = new TreeNode(nums[mid]);
        treeNode.left = makeTree(nums, from, mid - 1);
        treeNode.right = makeTree(nums, mid + 1, to);
        return treeNode;
    }
}
