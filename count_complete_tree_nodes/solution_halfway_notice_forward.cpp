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
        return root == NULL ? -1 : 1+height(root->left);
    }
    int countNodes(TreeNode* root) 
    {
        if (!root) return 0;
        int h = height(root);
        if (h==0) return 1;
        if (height(root->right)==h-1) // Left Subtree is full
            // 2^(h) means (2^h - 1) nodes present in left subtree + 1 for root
            return (1<<h) + countNodes(root->right);
        else
            // 2^(h-1) means (2^(h-1)-1) nodes present in right subtree +1 for root
            return (1<<h-1) + countNodes(root->left);
        return -1;
    }
};