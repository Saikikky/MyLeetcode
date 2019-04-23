class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
/**
 * 判读平衡二叉树  递归判断子树高度 O(n^2)
 */
public class Solution {
    public boolean IsBalanced_Solution(TreeNode root) {
        if (root == null) return true;
        int left = Depth(root.left);
        int right = Depth(root.right);
        if (Math.abs(left-right) <= 1) return true;
        return false;
    }

    public int Depth(TreeNode root) {
        if (root == null) return 0;
        int right = Depth(root.right);
        int left = Depth(root.left);
        return right>left?right+1:left+1;
    }
}

