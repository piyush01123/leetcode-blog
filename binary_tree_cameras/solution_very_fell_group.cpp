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
    int ctr = 0;
    enum status{uncovered, hasCamera, covered};
    int dfs(TreeNode *root)
    {
        if (root==NULL) return covered;
        int L=dfs(root->left), R=dfs(root->right);
        if (L==uncovered || R==uncovered)
        {
            ctr++;
            return hasCamera;
        }
        if (L==hasCamera || R==hasCamera)
            return covered;
        else
            return uncovered;
    }
    int minCameraCover(TreeNode* root) 
    {
        if (dfs(root)==uncovered)
            ctr++;
        return ctr;
    }
};