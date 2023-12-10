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
    stack<TreeNode*> s;
public:
    void util(TreeNode *root)
    {
        while(root)
        {
            s.push(root);
            root = root->left;
        }
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> keys;
        util(root);
        while(!s.empty())
        {
            root = s.top();
            s.pop();
            keys.push_back(root->val);
            if(root->right) util(root->right);
        }
        return keys;
    }
};