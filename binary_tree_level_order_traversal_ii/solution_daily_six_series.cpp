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
        if(root==NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    void level (TreeNode *root, int h, vector<int> &vals)
    {
        if (root==NULL || h<0) return;
        if (h==0) vals.push_back(root->val);
        level(root->left, h-1, vals);
        level(root->right, h-1, vals);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int H = height(root);
        vector<vector<int>> res;
        for (int h=0; h<H; h++)
        {
            vector<int> levelVals;
            level(root,h, levelVals);
            res.push_back(levelVals);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};