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
    List<Integer> res;
    int cur_elem, cur_count, max_elem, max_count;
    boolean first_element;

    void inorder(TreeNode root)
    {
        if(root==null) return;
        inorder(root.left);
        int elem = root.val;
        if (first_element)
        {
            first_element = false;
            cur_elem = elem;
            max_elem = elem;
            cur_count = 1;
            max_count = 1;
            res.add(elem);
            inorder(root.right);
            return;
        }
        if (elem==cur_elem) cur_count ++;
        else
        {
            cur_elem = elem;
            cur_count = 1;
        }
        if (cur_count>max_count)
        {
            max_elem = cur_elem;
            max_count = cur_count;
            res.clear();
            res.add(max_elem);
        }
        if (cur_count==max_count && cur_elem!=max_elem) res.add(cur_elem);
        inorder(root.right);
    }
    public int[] findMode(TreeNode root)
    {
        res = new ArrayList();
        first_element = true;
        inorder(root);
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}