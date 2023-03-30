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
    int height(TreeNode *root)
    {
        if (!root) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    void util(TreeNode *root, int h, int &res)
    {
        if (!root) return;
        if (h==0) res+=root->val;
        util(root->left, h-1, res);
        util(root->right, h-1, res);
    }
    int deepestLeavesSum(TreeNode* root) {
        int H = height(root);
        int res=0;
        util(root, H-1, res);
        return res;
    }
};