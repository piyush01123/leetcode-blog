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


//     bool isBalancedUtil(TreeNode *root, int *height){
//         if (root==nullptr) return true;
//         *height = *height+1;
//         int lh = 0, rh = 0;
//         bool lbal = isBalancedUtil(root->left, &lh);
//         bool rbal = isBalancedUtil(root->right, &rh);
//         return lbal && rbal && abs(lh,rh)<=1;
//     }

//     bool isBalanced(TreeNode* root) {
//      int height=0;
//      return isBalancedUtil(root, &height)   
//     }

};