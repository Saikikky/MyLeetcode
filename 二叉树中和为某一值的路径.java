import java.util.ArrayList;
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
    public ArrayList<ArrayList<Integer>> results = new ArrayList<>();
    public ArrayList<Integer> result = new ArrayList<>();
    public ArrayList<ArrayList<Integer>> FindPath(TreeNode root,int target) {
        if (root == null) return results;
        if (target >= 0) {
            result.add(root.val);
            target -= root.val;
            if (target == 0 && root.left == null && root.right == null) {
                results.add(new ArrayList<>(result));
            }
            if (root.left != null) FindPath(root.left, target);
            if (root.right != null) FindPath(root.right, target);
            result.remove(result.size() - 1);
            // 加不加都可 值传递都是函数栈中的局部变量
            // 返回上一个函数栈时 上一个函数栈中的target是一个没减之前的 所以加不加是没有任何影响的
            //target += root.val;
        }

        return results;
    }
}