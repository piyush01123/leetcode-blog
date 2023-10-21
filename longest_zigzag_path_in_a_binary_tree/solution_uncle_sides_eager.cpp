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
    int res=0;
    void dfs(TreeNode* root, bool isLeft, int steps)
    {
        if (!root) return;
        res = max(res, steps);
        dfs(root->left, true, isLeft?1:steps+1);
        dfs(root->right, false, isLeft?steps+1:1);
    }
public:
    int longestZigZag(TreeNode* root) 
    {
        dfs(root, true, 0);
        dfs(root, false, 0);
        return res;
    }
};