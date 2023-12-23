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
    int res;
public:
    pair<int,int> treeAvg(TreeNode *root)
    {
        if (!root) return {-1,-1};
        pair<int,int> avgL = treeAvg(root->left), avgR = treeAvg(root->right);
        int sum=0, n=0;
        if (avgL.first!=-1) {sum+=avgL.first; n+=avgL.second;}
        if (avgR.first!=-1) {sum+=avgR.first; n+=avgR.second;}
        sum += root->val; n++;
        if (sum/n==root->val) res++;
        return {sum,n};
    }
    int averageOfSubtree(TreeNode* root) 
    {
        res = 0;
        treeAvg(root);
        return res;
    }
};