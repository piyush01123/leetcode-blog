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
    int widthOfBinaryTree(TreeNode* root) 
    {
        unsigned long long res = 0;
        queue<pair<TreeNode*,unsigned long long>> Q;
        Q.push({root,0});
        while(!Q.empty())
        {
            res = max(res, 1+Q.back().second-Q.front().second);
            for (int i=Q.size(); i>0; i--)
            {
                TreeNode* cur = Q.front().first;
                auto curNum = Q.front().second;
                Q.pop();
                if(cur->left) Q.push({cur->left, 2*curNum+1});
                if(cur->right) Q.push({cur->right, 2*curNum+2});
            }
        }
        return (int)res;
    }
};