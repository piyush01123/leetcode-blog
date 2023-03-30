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
    unordered_set<int> S;
public:
    bool findTarget(TreeNode* root, int target) 
    {
        if (!root) return false;
        if (S.count(root->val)) return true;
        S.insert(target - root->val);
        return findTarget(root->left,target) || findTarget(root->right,target);
    }
};