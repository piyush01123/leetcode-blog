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
    int findDepth(TreeNode *root, int &res)
    {
        if(!root) return 0;
        int a = findDepth(root->left, res);
        int b = findDepth(root->right, res);
        res = max(res, a+b);
        return max(a,b)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res=0;
        findDepth(root, res);
        return res;
    }
};