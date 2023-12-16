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
    void inorder(TreeNode *root, vector<int>&A)
    {
        if (!root) return;
        inorder(root->left, A);
        A.push_back(root->val);
        inorder(root->right, A);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) 
    {
        vector<int> A;
        inorder(root,A);
        vector<vector<int>> res;
        for (int query: queries)
        {
            auto it1 = lower_bound(A.begin(),A.end(),query);
            auto it2 = upper_bound(A.begin(),A.end(),query);
            int a, b;
            if (it1!=A.end())
            {
                if (*it1==query){a=query; b=query;}
                else if (it1==A.begin()) {a=-1;b=*it1;}
                else {a=*(--it1); b=*it2;}
            }
            else {a=*(--it1); b=-1;}
            res.push_back({a,b});
        }
        return res;
    }
};