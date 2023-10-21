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
    int res = 0;
    void dfs(TreeNode* root, bool goLeft, int steps) //goLeft for zigzag
    {
        if (!root) return;
        res = max(res, steps);
        if (goLeft)
        {
            dfs(root->left, false, steps+1); //root is part of zigzag path
            dfs(root->right, true, 1); //not part of zigzag
        }
        else
        {
            dfs(root->left, false, 1); // not part of zigzag
            dfs(root->right, true, steps+1); //part of zigzag
        }
    }
public:
    int longestZigZag(TreeNode* root) 
    {
        dfs(root, true, 0);
        dfs(root, false,  0);
        return res;
    }
};