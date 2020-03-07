/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    boolean isSymmetrical(TreeNode pRoot)
    {
        if (pRoot == null) return true;
        return judge(pRoot.left, pRoot.right);
    }
    
    boolean judge(TreeNode root1, TreeNode root2) {
        if (root1 == null && root2 == null) return true;
        if (root1 == null || root2 == null) return false;
        if (root1.val == root2.val) {
            return judge(root1.left, root2.right) && judge(root2.left, root1.right);
        } else {
            return false;
        }
    }
}