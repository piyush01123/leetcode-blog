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
    void dfsA(TreeNode *root, vector<int>&levels, int level)
    {
        if (!root) return;
        if (levels.size()==level) levels.push_back(0);
        levels[level] += root->val;
        dfsA(root->left, levels, level+1);
        dfsA(root->right, levels, level+1);
    }
    void dfsB(TreeNode *root, vector<int> &levels, int level)
    {
        if (!root) return;
        int cur = 0;
        if (root->left) cur += root->left->val;
        if (root->right) cur += root->right->val;
        if(root->left) root->left->val = levels[level+1]-cur;
        if (root->right) root->right->val = levels[level+1]-cur;
        dfsB(root->left, levels, level+1);
        dfsB(root->right, levels, level+1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) 
    {
        vector<int> levels;
        dfsA(root, levels, 0);
        dfsB(root, levels, 0);
        root->val = 0;
        return root;
    }
};