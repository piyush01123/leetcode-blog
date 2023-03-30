/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isUnivalTreeUtil(TreeNode *root, int val)
    {
        if(root==NULL) return true;
        return root->val==val && isUnivalTreeUtil(root->left,val) && isUnivalTreeUtil(root->right,val);
    }
    bool isUnivalTree(TreeNode* root) 
    {
        return isUnivalTreeUtil(root, root->val);
    }
};