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
    void dfs(TreeNode *root, int val, int depth, int curDepth)
    {
        if (!root) return;
        if (depth==curDepth+1)
        {
            root->left = new TreeNode(val, root->left, NULL);
            root->right = new TreeNode(val, NULL, root->right);
            return;
        }
        dfs(root->left, val, depth, curDepth+1);
        dfs(root->right, val, depth, curDepth+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) 
    {
        if (depth==1) return new TreeNode(val, root, NULL);
        dfs(root, val, depth, 1);
        return root;
    }
};