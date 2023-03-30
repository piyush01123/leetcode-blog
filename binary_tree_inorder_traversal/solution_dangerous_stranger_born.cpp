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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        stack<TreeNode *>nodes;
        while(root || !nodes.empty())
        {
            while(root)
            {
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top();
            res.push_back(root->val);
            nodes.pop();
            root = root->right;
        }
        return res;
    }
};