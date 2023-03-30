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
#define ull unsigned long long
class Solution {
public:
    ull maxProd = 0;
    ull total;
    ull mod = 1000000007;
    ull treeSum(TreeNode *root)
    {
        if (root==NULL) return 0;
        return treeSum(root->left)+treeSum(root->right)+(ull)root->val;
    }
    ull getMaxProduct(TreeNode *root)
    {
        if (root==NULL) return 0;
        ull left = getMaxProduct(root->left);
        ull right = getMaxProduct(root->right);
        maxProd = max(maxProd, (total-left)*left);
        maxProd = max(maxProd, (total-right)*right);
        return left + right + (ull)root->val;
    }
    int maxProduct(TreeNode* root) 
    {
        total = treeSum(root);
        getMaxProduct(root);
        return (int)(maxProd%mod);
    }
};