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
    void swap(TreeNode *n1, TreeNode *n2)
    {
        int t=n1->val;
        n1->val=n2->val;
        n2->val=t;
    }
    vector<int>getSwappedIndices(vector<int> keys)
    {
        int n=keys.size();
        int l=0, r=n-1, idx1=-1, idx2=-1;
        while (idx1==-1 || idx2==-1)
        {
            if (keys[l]>keys[l+1]) idx1=l;
            else l++;
            if (keys[r]<keys[r-1]) idx2=r;
            else r--;
        }
        return {idx1, idx2};
    }
    void traverse(TreeNode *root, unordered_map<int,TreeNode *>&H, vector<int>&keys)
    {
        if (root==NULL) return;
        traverse(root->left,H,keys);
        H[root->val]=root;
        keys.push_back(root->val);
        traverse(root->right,H,keys);
    }
    void recoverTree(TreeNode* root) {
        unordered_map<int,TreeNode *>H;
        vector<int> keys;
        traverse(root, H, keys);
        vector<int> swapped = getSwappedIndices(keys);
        int idx1=swapped[0], idx2=swapped[1];
        swap(H[keys[idx1]], H[keys[idx2]]);
    }
};