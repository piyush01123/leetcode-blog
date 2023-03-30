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
    string tree2str(TreeNode* root) {
        if (root==NULL) return "";
        string s=to_string(root->val);
        if (root->left==NULL && root->right==NULL) return s;
        if (root->left==NULL) return s+"()("+tree2str(root->right)+')';
        if (root->right==NULL) return s+'('+tree2str(root->left)+')';
        return s+'('+tree2str(root->left)+")("+tree2str(root->right)+')';
    }
};