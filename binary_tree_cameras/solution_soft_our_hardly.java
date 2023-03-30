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
class Solution {
    int ctr = 0;
    int dfs(TreeNode root)
    {
        if (root==null) return 2;
        int L=dfs(root.left), R=dfs(root.right);
        if (L==0 || R==0)
        {
            ctr++;
            return 1;
        }
        if (L==1 || R==1) return 2;
        else return 0;
    }
    public int minCameraCover(TreeNode root) 
    {
        if (dfs(root)==0) ctr++;
        return ctr;
    }
}