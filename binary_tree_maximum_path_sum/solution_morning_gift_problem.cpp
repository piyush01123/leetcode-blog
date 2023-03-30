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
    int getMaxGain(TreeNode *root, int &res)
    {
        if (!root) return 0;
        int gainOnLeft = max(getMaxGain(root->left,res), 0);
        int gainOnRight = max(getMaxGain(root->right,res), 0);
        int curMaxWithRoot = root->val + gainOnLeft + gainOnRight;
        res = max(res, curMaxWithRoot);
        return root->val + max(gainOnLeft, gainOnRight);
    }
    int maxPathSum(TreeNode* root) 
    {
        int res=INT_MIN;
        getMaxGain(root, res);
        return res;
    }
};