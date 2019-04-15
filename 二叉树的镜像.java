/**
 * 二叉树的镜像
 * 先交换跟结点再接着递归交换子结点至交换至叶子结点终止
 */
class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;
    }

}
public class Solution {
    public void Mirror(TreeNode root) {
        if (root == null) return;
        if (root.left == null && root.right == null) return;

        TreeNode tempRoot = root.left;
        root.left = root.right;
        root.right = tempRoot;

        if (root.left != null) {
            Mirror(root.left);
        }
        if (root.right != null) {
            Mirror(root.right);
        }
    }
}