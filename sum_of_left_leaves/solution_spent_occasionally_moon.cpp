/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isLeaf(TreeNode *node){
        return node->left==NULL && node->right==NULL;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if (root==NULL) return 0;
        int res = 0;
        if (root->left!=NULL){
            if (isLeaf(root->left)) res+=root->left->val;
            else res+=sumOfLeftLeaves(root->left);
        }
        if (root->right!=NULL){
            res+=sumOfLeftLeaves(root->right);
        }
        return res;
    }
};