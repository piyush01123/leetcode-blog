/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasNode(TreeNode *root, TreeNode *node)
    {
        if (!root) return false;
        if (root->val==node->val) return true;
        return hasNode(root->left,node) || hasNode(root->right,node);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (hasNode(root->left,p) && hasNode(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        if (hasNode(root->right,p) && hasNode(root->right,q)) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};