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
    int helper(TreeNode *root, int curr=0)
    {
        if (root==NULL) return 0;
        curr = (curr<<1) + (root->val);
        if (root->left==NULL && root->right==NULL) return curr;
        return helper(root->left, curr) + helper(root->right, curr);
    }
    int sumRootToLeaf(TreeNode* root) {
        return helper(root);
    }
};