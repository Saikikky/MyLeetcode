import java.util.ArrayList;
import java.util.ArrayDeque;
import java.util.Queue;
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
    public ArrayList<Integer> PrintFromTopToBottom(TreeNode root) {
        // 保存TreeNode的val队列
        Queue<TreeNode> queue = new ArrayDeque<>();
        // 保存二叉树的结点值
        ArrayList<Integer> result = new ArrayList<>();
        if (root == null) return result;
        TreeNode treeNode = null;


        queue.offer(root);
        while (!queue.isEmpty()) {
            treeNode = queue.poll();
            result.add(treeNode.val);
            if (treeNode.left != null) queue.offer(treeNode.left);
            if (treeNode.right != null) queue.offer(treeNode.right);
        }
        return result;
    }
}