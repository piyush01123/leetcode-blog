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
    void inOrder(TreeNode *root, vector<int>&vals)
    {
        if (root==NULL) return;
        inOrder(root->left,vals);
        vals.push_back(root->val);
        inOrder(root->right,vals);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> vals;
        inOrder(root,vals);
        int n = vals.size();
        int i=0, j=n-1;
        while (i<j)
        {
            if (vals[i]+vals[j]==k) return true;
            else if (vals[i]+vals[j]<k) i++;
            else j--;
        }
        return false;
    }
};