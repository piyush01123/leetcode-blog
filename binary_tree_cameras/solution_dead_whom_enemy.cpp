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
    // 0: Leaf, 1: Parent of Leaf (camera++), 2: Covered
    int dfs(TreeNode *root)
    {
        if (root==NULL) return 2;
        int L = dfs(root->left), R = dfs(root->right);
        if (L==0 || R==0)
        {
            ctr++;
            return 1;
        }
        if (L==1 || R==1) return 2;
        else return 0;
    }
    int minCameraCover(TreeNode* root) 
    {
        if (dfs(root)==0) ctr++;
        return ctr;
    }
};