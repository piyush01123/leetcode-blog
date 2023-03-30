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
        TreeNode *l=root->left, *r=root->right, *ll, *lr, *rl, *rr;
        if (l){ll=l->left; lr=l->right;}
        if (r){rl=r->left; rr=r->right;}
        int a = (l)?helper(ll,money)+helper(lr,money):0;
        int b = (r)?helper(rl,money)+helper(rr,money):0;
        return money[root]=max(root->val+a+b, helper(l,money)+helper(r,money));
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode *, int> moneys;
        return helper(root, moneys);
    }
};