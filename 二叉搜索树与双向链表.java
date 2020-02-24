/**
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
    TreeNode tmp = null;
    public TreeNode Convert(TreeNode pRootOfTree) {
        if (pRootOfTree == null) return null;
        f(pRootOfTree);

        while (tmp != null && tmp.left != null) tmp = tmp.left;
        return tmp;
    }
    public  void f(TreeNode pRoot) {
        if (pRoot == null) return;
        f(pRoot.left);
        pRoot.left = tmp;
        if (tmp != null) {
            tmp.right = pRoot;
        }
        tmp = pRoot;
        f(pRoot.right);
    }
}