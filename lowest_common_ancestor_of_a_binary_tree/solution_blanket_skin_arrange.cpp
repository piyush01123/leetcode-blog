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
    TreeNode* lowestCommonAncestorSolA(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (root==NULL) return NULL;
        if (root->val==p->val || root->val==q->val) return root;
        TreeNode *left_lca = lowestCommonAncestorSolA(root->left,p,q);
        TreeNode *right_lca = lowestCommonAncestorSolA(root->right,p,q);
        if (left_lca && right_lca) return root;
        return (left_lca!=NULL ? left_lca : right_lca);
    }
    bool hasNode(TreeNode *root, TreeNode *node)
    {
        if (root==NULL) return false;
        if (root->val==node->val) return true;
        return hasNode(root->left,node)||hasNode(root->right,node);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (hasNode(root->left,p)&&hasNode(root->left,q))
            return lowestCommonAncestor(root->left,p,q);
        if (hasNode(root->right,p)&&hasNode(root->right,q))
            return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};