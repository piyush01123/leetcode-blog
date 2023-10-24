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
    vector<int> largestValues(TreeNode* root) 
    {
        if (!root) return {};
        queue<TreeNode*> Q;
        Q.push(root);
        vector<int> res;
        while(!Q.empty())
        {
            int val = INT_MIN;
            for(int i=Q.size(); i>0; i--)
            {
                TreeNode *cur = Q.front();
                Q.pop();
                if (cur->left) Q.push(cur->left);
                if (cur->right) Q.push(cur->right);
                val = max(val, cur->val);
            }
            res.push_back(val);
        }
        return res;
    }
};