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
    TreeNode *lowestCommonAncestor(TreeNode *root, int x, int y)
    {
        if (!root) return NULL;
        if (root->val==x || root->val==y) return root;
        TreeNode *left_lca = lowestCommonAncestor(root->left, x, y);
        TreeNode *right_lca = lowestCommonAncestor(root->right, x, y);
        if (left_lca && right_lca) return root;
        return left_lca?left_lca:right_lca;
    }
    bool getPath(TreeNode *node, int val, string &str)
    {
        if (node->val==val) return true;
        if (node->left && getPath(node->left, val, str)) str.push_back('L');
        else if (node->right && getPath(node->right, val, str)) str.push_back('R');
        return !str.empty();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode *lca = lowestCommonAncestor(root, startValue, destValue);
        string sp, dp;
        getPath(lca,startValue,sp);
        getPath(lca,destValue,dp);
        return string(sp.size(), 'U') + string(dp.rbegin(), dp.rend());
    }
};