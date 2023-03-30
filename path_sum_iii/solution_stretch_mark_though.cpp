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
    int pathSum(TreeNode* root, int targetSum) 
    {
        if (!root) return 0;
        return sumUp(root, 0, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
    int sumUp(TreeNode *root, long long curr, int target)
    {
        if (!root) return 0;
        curr += root->val;
        return (curr==target) + sumUp(root->left, curr, target) + sumUp(root->right,curr,target);
    }
};