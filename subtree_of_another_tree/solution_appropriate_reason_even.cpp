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
    void serialize(TreeNode *root, string &res)
    {
        if (!root) {res += ",#"; return;}
        res += ","+to_string(root->val);
        serialize(root->left,res);
        serialize(root->right,res);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        string strRoot="", strSubRoot="";
        serialize(root, strRoot);
        serialize(subRoot, strSubRoot);
        return strRoot.find(strSubRoot) != string::npos;
    }
};