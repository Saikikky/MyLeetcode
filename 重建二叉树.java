class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Solution {
    public TreeNode reConstructBinaryTree(int [] pre, int [] in) {
        int length = pre.length;
        if (pre == null || in == null || length <= 0) return null;
        return ConstructCore(pre, 0, pre.length - 1, in, 0, length - 1);
    }

    private TreeNode ConstructCore(int[] pre, int startPre, int endPre, int[] in, int startIn, int endIn) {
        if (startPre > endPre || startIn > endIn) return null;

        // 根结点
        TreeNode root = new TreeNode(pre[startPre]);

        for (int i = startIn; i <= endIn; i++) {
            if (in[i] == pre[startPre]) {
                root.left = ConstructCore(pre, startPre + 1, startPre + i - startIn, in, startIn, i - 1 );
                root.right = ConstructCore(pre, startPre + i - startIn + 1, endPre, in, i+1, endIn);
            }
        }
        return root;
    }
}