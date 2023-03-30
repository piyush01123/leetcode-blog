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
    int res = INT_MIN;
public:
    int util(TreeNode *root)
    {
        if (!root) return 0;
        int lval = max(util(root->left), 0);
        int rval = max(util(root->right),0);
        int cur = root->val + lval + rval;
        res = max(res, cur);
        return root->val + max(lval, rval);
    }
    int maxPathSum(TreeNode* root) 
    {
        util(root);
        return res;
    }
};