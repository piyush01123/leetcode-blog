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
    int preOrderIndex;
    unordered_map<int,int> inOrderIndexMap;
public:
    TreeNode *helper(vector<int>preorder, int left, int right)
    {
        if (left>right) return NULL;
        int rootVal = preorder[preOrderIndex];
        preOrderIndex++;
        int inOrderIndex = inOrderIndexMap[rootVal];
        TreeNode *root = new TreeNode;
        root->val = rootVal;
        root->left = helper(preorder, left, inOrderIndex-1);
        root->right = helper(preorder, inOrderIndex+1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preOrderIndex=0;
        for(int i=0; i<inorder.size(); i++) inOrderIndexMap[inorder[i]]=i;
        return helper(preorder, 0, preorder.size()-1);
    }
};