/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution 
{
    List<Integer> res;
    void dfs(TreeNode root, int d)
    {
        if (root==null) return;
        if (res.size()==d) res.add(root.val);
        res.set(d, Math.max(res.get(d), root.val));
        if (root.left!=null) dfs(root.left, d+1);
        if (root.right!=null) dfs(root.right, d+1);
    }
    public List<Integer> largestValues(TreeNode root) 
    {
        res = new ArrayList();
        dfs(root, 0);
        return res;
    }
}