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
    public int maxLevelSum(TreeNode root) 
    {
        int curLevel=1, resLevel=0, maxSum=Integer.MIN_VALUE;
        Queue<TreeNode> Q = new LinkedList<>();
        Q.add(root);
        while(!Q.isEmpty())
        {
            int curSum = 0;
            for(int i=Q.size(); i>0; i--)
            {
                TreeNode cur = Q.poll();
                curSum += cur.val;
                if(cur.left!=null) Q.add(cur.left);
                if(cur.right!=null) Q.add(cur.right);
            }
            if (curSum>maxSum)
            {
                maxSum = curSum;
                resLevel = curLevel;
            }
            curLevel++;
        }
        return resLevel;
    }
}