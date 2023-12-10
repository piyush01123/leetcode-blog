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
    vector<int> keys;
    void f(TreeNode *root)
    {
        if (!root) return;
        f(root->left);
        keys.push_back(root->val);
        f(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        f(root);
        return keys;
    }
};