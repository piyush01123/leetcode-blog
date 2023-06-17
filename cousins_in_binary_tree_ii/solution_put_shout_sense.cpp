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
    TreeNode* replaceValueInTree(TreeNode* root) 
    {
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            int curSum = 0;
            vector<TreeNode*> levelNodes;
            for (int i=Q.size(); i>0; i--)
            {
                TreeNode* cur = Q.front();
                Q.pop();
                levelNodes.push_back(cur);
                if (cur->left)
                {
                    curSum += cur->left->val;
                    Q.push(cur->left);
                }
                if (cur->right)
                {
                    curSum += cur->right->val;
                    Q.push(cur->right);
                }
            }
            for (TreeNode* node: levelNodes)
            {
                int cousinSum = curSum;
                if (node->left) cousinSum -= node->left->val;
                if (node->right) cousinSum -= node->right->val;
                if (node->left) node->left->val = cousinSum;
                if (node->right) node->right->val = cousinSum;
            }
        }
        root->val = 0;
        return root;
    }
};