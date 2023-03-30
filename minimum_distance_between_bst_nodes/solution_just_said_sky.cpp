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
    int res = INT_MAX;
    int prev = -1;
    void traverse(TreeNode *root)
    {
        if(!root) return;
        traverse(root->left);
        if (prev!=-1) res = min(res, root->val-prev);
        prev = root->val;
        traverse(root->right);
    }
    int minDiffInBST(TreeNode* root) 
    {
        traverse(root);
        return res;        
    }
};