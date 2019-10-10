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
    List<List<Integer>> results = new ArrayList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        
        dfs(root, sum, new ArrayList<>());
        
        return results;
        
    }
    
    void dfs(TreeNode root, int sum, List<Integer> result) {
        if (root == null) return;
        
        sum -= root.val;
        result.add(root.val);
        
        // 若为叶子节点且符合结果
        if (root.left == null && root.right == null && sum == 0) results.add(new ArrayList<>(result));
        else {
            dfs(root.left, sum, result);
            dfs(root.right, sum, result);
        }
       
        // 回溯
        result.remove(result.size() - 1);
    }
}