/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution 
{
    void storeParents(TreeNode root, HashMap<TreeNode,TreeNode>H)
    {
        if (root==null) return;
        if (root.left!=null) H.put(root.left,root);
        if (root.right!=null) H.put(root.right,root);
        storeParents(root.left,H);
        storeParents(root.right,H);
    }
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) 
    {
        HashMap<TreeNode,TreeNode> H = new HashMap<TreeNode,TreeNode>();
        storeParents(root,H);
        Queue<TreeNode> Q = new LinkedList<TreeNode>();
        HashSet<TreeNode> visited = new HashSet<TreeNode>();
        Q.add(target);
        for (int ctr=0; ctr<K; ctr++)
        {
            if (Q.isEmpty()) return new ArrayList<Integer>();
            for (int i=Q.size(); i>0; i--)
            {
                TreeNode cur = Q.peek();
                Q.remove();
                visited.add(cur);
                if (cur.left!=null && !visited.contains(cur.left))
                    Q.add(cur.left);
                if (cur.right!=null && !visited.contains(cur.right))
                    Q.add(cur.right);
                if (H.containsKey(cur) && !visited.contains(H.get(cur)))
                    Q.add(H.get(cur));
            }
        }
        ArrayList<Integer> res = new ArrayList<Integer>();
        while (!Q.isEmpty())
        {
            res.add(Q.peek().val);
            Q.remove();
        }
        return res;
    }
}