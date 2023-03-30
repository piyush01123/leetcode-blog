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
    int findSum(TreeNode *root)
    {
        if (!root) return 0;
        return root->val+findSum(root->left)+findSum(root->right);
    }
    int findTilt(TreeNode* root) 
    {
        if (!root) return 0;
        int a = findSum(root->left), b = findSum(root->right);
        return findTilt(root->left)+findTilt(root->right) + ((a>b)?a-b:b-a);
    }
};