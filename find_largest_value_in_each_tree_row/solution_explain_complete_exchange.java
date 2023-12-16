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
    public List<Integer> largestValues(TreeNode root) 
    {
        if (root==null) return new ArrayList();
        List<Integer> res = new ArrayList();
        Queue<TreeNode> Q = new LinkedList();
        Q.add(root);
        while(!Q.isEmpty())
        {
            int val = Integer.MIN_VALUE;
            for (int i=Q.size(); i>0;  i--)
            {
                TreeNode cur = Q.poll();
                if (cur.left!=null) Q.add(cur.left);
                if (cur.right!=null) Q.add(cur.right);
                val = Math.max(val, cur.val);
            }
            res.add(val);
        }
        return res;
    }
}