/*
public class TreeLinkNode {
    int val;
    TreeLinkNode left = null;
    TreeLinkNode right = null;
    TreeLinkNode next = null;

    TreeLinkNode(int val) {
        this.val = val;
    }
}
*/
public class Solution {
    public TreeLinkNode GetNext(TreeLinkNode pNode)
    {
        if (pNode == null) return null;

        // 有右子树 找最左节点
        if (pNode.right != null) {
            TreeLinkNode node = pNode.right;
            while (node.left != null) {
                node = node.left;
            }
            return node;
        } else {
            // 没有右子树
            TreeLinkNode father = pNode.next;
            if (father != null) {
                while (father.left != pNode) {
                    // pNode不是父节点的左节点 即是右节点
                    pNode = father;
                    father = pNode.next;
                    if (father == null) return null;
                }
                return father;
            }
        }
        return null;
    }
}