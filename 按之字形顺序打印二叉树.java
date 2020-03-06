import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
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
    public ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
        ArrayList<ArrayList<Integer>> results = new ArrayList<>();
        if (pRoot == null) return results;

        // 0从左到右 1从右到左
        boolean tag = false;

        // 充当队列数组
        Queue<TreeNode> nodes = new LinkedList<>();
        nodes.add(pRoot);

        while (!nodes.isEmpty()) {
            int size = nodes.size();
            ArrayList<Integer> result = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                TreeNode node = nodes.poll();
                if (tag == false) {
                    result.add(node.val);
                } else {
                    result.add(0, node.val);
                }
                if (node.left != null) {
                    nodes.offer(node.left);
                }
                if (node.right != null) {
                    nodes.offer(node.right);
                }
            }
            results.add(result);
            tag = !tag;
        }
        return results;
    }

}