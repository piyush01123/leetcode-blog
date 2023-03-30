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
    int helper(TreeNode *root, unordered_map<TreeNode *, int> &money)
    {
        if (root==NULL) return 0;
        if (money.find(root)!=money.end()) return money[root];
        int left_max = 0, right_max = 0;
        if (root->left) left_max = helper(root->left->left,money)+helper(root->left->right,money);
        if (root->right) right_max = helper(root->right->left,money)+helper(root->right->right,money);
        return money[root]=max(root->val+left_max+right_max, helper(root->left,money)+helper(root->right,money));
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode *, int> money;
        return helper(root, money);
    }
};