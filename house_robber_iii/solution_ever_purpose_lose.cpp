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
        int a=0, b=0;
        TreeNode *l=root->left, *r=root->right, *ll, *lr, *rl, *rr;
        if (l){ll=l->left; lr=l->right;}
        if (r){rl=r->left; rr=r->right;}
        if (l) a = helper(ll,money)+helper(lr,money);
        if (r) b = helper(rl,money)+helper(rr,money);
        return money[root]=max(root->val+a+b, helper(l,money)+helper(r,money));
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode *, int> money;
        return helper(root, money);
    }
};