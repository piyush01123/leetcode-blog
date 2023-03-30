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
    TreeNode *createNode(int val)
    {
        TreeNode *node = new TreeNode;
        node->val = val;
        return node;
    }
    void insert(TreeNode *root, int val)
    {
        if (!root->left && !root->right)
        {
            if (val < root->val) root->left = createNode(val);
            else root->right = createNode(val);
            return;
        }
        if (!root->left)
        {
            if (val < root->val) root->left = createNode(val);
            else insert(root->right, val);
            return;
        }
        if (!root->right)
        {
            if (val > root->val) root->right = createNode(val);
            else insert(root->left, val);
            return;
        }
        if (val<root->val) insert(root->left, val);
        else insert(root->right, val);
        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return createNode(val);
        insert(root, val);
        return root;
    }
};