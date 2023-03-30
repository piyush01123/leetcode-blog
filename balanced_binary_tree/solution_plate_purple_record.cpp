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
    int max(int a, int b){return (b>a)?b:a;}
    int abs_diff(int a, int b){ return (b>=a)?(b-a):(a-b);}
    int depth(TreeNode* root){
        if (root==nullptr) { return 0;}
        return max(depth(root->left), depth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        int d1 = depth(root->left);
        int d2 = depth(root->right);
        return abs_diff(d1,d2)<=1 && isBalanced(root->left) && isBalanced(root->right);
    }
};