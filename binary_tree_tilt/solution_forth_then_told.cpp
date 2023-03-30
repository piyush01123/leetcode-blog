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
    int postorder(TreeNode *root, int &result)
    {
        if(!root) return 0;
        int a = postorder(root->left,result);
        int b = postorder(root->right,result);
        result += abs(a-b);
        return a+b+root->val;
    }
    int findTilt(TreeNode* root) 
    {
        int res=0;
        postorder(root,res);
        return res;
    }
};