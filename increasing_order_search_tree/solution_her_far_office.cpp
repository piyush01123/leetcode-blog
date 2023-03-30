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
    void inOrder(TreeNode *root, vector<int>&v)
    {
        if (root==NULL) return;
        inOrder(root->left,v);
        v.push_back(root->val);
        inOrder(root->right,v);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> keys;
        inOrder(root,keys);
        root = new TreeNode();
        TreeNode *curr = root, *prev;
        for (int k: keys)
        {
            curr->val=k;
            curr->right = new TreeNode();
            prev=curr;
            curr=curr->right;
        }
        prev->right=NULL;
        return root;
    }
};