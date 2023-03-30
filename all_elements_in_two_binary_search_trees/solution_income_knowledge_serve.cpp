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
    void inOrder(TreeNode *root, vector<int>&v)
    {
        if(!root) return;
        inOrder(root->left,v);
        v.push_back(root->val);
        inOrder(root->right,v);
    }
    void merge(vector<int>&v1,vector<int>&v2,vector<int>&v3)
    {
        int n1=v1.size(), n2=v2.size(), i=0, j=0;
        while(i<n1 && j<n2)
        {
            if (v1[i]<v2[j]){v3.push_back(v1[i]); i++;}
            else {v3.push_back(v2[j]); j++;}
        }
        while (i<n1) {v3.push_back(v1[i]); i++;}
        while (j<n2) {v3.push_back(v2[j]); j++;}
        return;
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1, v2, v3;
        inOrder(root1,v1);
        inOrder(root2,v2);
        merge(v1,v2,v3);
        return v3;
    }
};


