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
        return 1 + max(height(root->left), height(root->right));
    }
    void dfs(TreeNode *root, vector<int>&levelVals, int h)
    {
        if (!root || h<0) return;
        if (h==0) levelVals.push_back(root->val);
        dfs(root->left, levelVals, h-1);
        dfs(root->right, levelVals, h-1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int H = height(root);
        vector<vector<int>> res;
        for (int h=0; h<H; h++)
        {
            vector<int> levelVals;
            dfs(root, levelVals, h);
            res.push_back(levelVals);
        }
        return res;
    }
};