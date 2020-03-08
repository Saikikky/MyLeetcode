import java.util.ArrayList;
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
    TreeNode KthNode(TreeNode pRoot, int k)
    {
        if (k < 1) return null;
        ArrayList<TreeNode> inSort = new ArrayList<>();

        Sort(inSort, pRoot, k);

        if (inSort.size() >= k) return inSort.get(k - 1);
        return null;
    }
    
    public void Sort(ArrayList<TreeNode> result, TreeNode pRoot, int k) {
        if (pRoot == null) return;

        if (result.size() > k) return;

        if (pRoot.left != null) Sort(result, pRoot.left, k);
        result.add(pRoot);
        if (pRoot.right != null) Sort(result, pRoot.right, k);
    }


}