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
    int kthSmallest(TreeNode* root, int k) 
    {
        stack<TreeNode *> nodes;
        while(root || !nodes.empty())
        {
            while (root)
            {
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top();
            if (--k==0) break;
            nodes.pop();
            root = root->right;
        }
        return root->val;
    }
};