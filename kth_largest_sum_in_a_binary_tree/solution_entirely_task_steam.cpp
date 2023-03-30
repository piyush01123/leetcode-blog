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
    long long kthLargestLevelSum(TreeNode* root, int K) 
    {
        vector<long long> levelSums;
        queue<TreeNode*>Q;
        Q.push(root);
        while (!Q.empty())
        {
            long long curSum = 0;
            for (int i=Q.size(); i>0; i--)
            {
                TreeNode *cur = Q.front();
                curSum += cur->val;
                Q.pop();
                if (cur->left) Q.push(cur->left);
                if (cur->right) Q.push(cur->right);
            }
            levelSums.push_back(curSum);
        }
        if (levelSums.size()<K) return -1;
        sort(levelSums.rbegin(), levelSums.rend());
        return levelSums[K-1];
    }
};