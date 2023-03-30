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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if  (!root) return {};
        queue<TreeNode *> Q;
        Q.push(root);
        int level = 1;
        vector<vector<int>> res;
        while(!Q.empty())
        {
            vector<int> levelVals;
            for (int i=Q.size()-1; i>=0; --i)
            {
                TreeNode *node = Q.front();
                levelVals.push_back(node->val);
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                Q.pop();
            }
            if (level%2 == 0)
                reverse(levelVals.begin(), levelVals.end());
            res.push_back(levelVals);
            level ++;
        }
        return res;
    }
};