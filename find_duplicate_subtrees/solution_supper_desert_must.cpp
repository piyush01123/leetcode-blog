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
    vector<TreeNode*> res;
    unordered_map<string, int> H;
public:
    string traverse(TreeNode *root)
    {
        if (!root) return "";
        string rep = "("+traverse(root->left)+")"+to_string(root->val)+\
                     "("+traverse(root->right)+")";
       H[rep]++;
       if (H[rep]==2) res.push_back(root);
       return rep;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        traverse(root);
        return res;
    }
};