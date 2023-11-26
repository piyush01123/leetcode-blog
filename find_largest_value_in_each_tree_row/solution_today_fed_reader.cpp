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
    void dfs(TreeNode *root, vector<int>&res, int d)
    {
        if (!root) return;
        if (d==res.size()) res.push_back(root->val);
        res[d] = max(res[d], root->val);
        dfs(root->left, res, d+1);
        dfs(root->right, res, d+1);
    }
    vector<int> largestValues(TreeNode* root) 
    {
        if (!root) return {};
        vector<int> res;
        dfs(root, res, 0);
        return res;
    }
};