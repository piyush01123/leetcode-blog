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
    vector<int> rightSideView(TreeNode* root) 
    {
        if (!root) return {};
        vector<int>res;
        queue<TreeNode *>Q;
        Q.push(root);
        while (!Q.empty())
        {
            int qsize = Q.size();
            for (int i=0; i<qsize; i++)
            {
                root = Q.front();
                Q.pop();
                if (root->left) Q.push(root->left);
                if(root->right) Q.push(root->right);
            }
            res.push_back(root->val);
        }
        return res;
    }
};