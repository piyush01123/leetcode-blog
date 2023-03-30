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
    bool hasNode(TreeNode *root, int val)
    {
        if (root==NULL) return false;
        if (root->val==val) return true;
        return hasNode(root->left, val) || hasNode(root->right, val);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root) cout << root->val << endl;
        if (root->val==p->val || root->val==q->val) return root;
        if (hasNode(root->left, p->val) && hasNode(root->left, q->val))return lowestCommonAncestor(root->left, p, q);

        if (hasNode(root->right, p->val) && hasNode(root->right, q->val))return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};