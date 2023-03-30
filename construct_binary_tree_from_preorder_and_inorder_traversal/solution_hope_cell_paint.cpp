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
void pvec(vector<int>v){for (int i: v) cout << i << ' '; cout<<endl;}
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0||inorder.size()==0) return NULL;

        int rootIndex=0;
        while(inorder[rootIndex]!=preorder[0])  rootIndex++;
        vector<int> pre_left(preorder.begin()+1, preorder.begin()+rootIndex+1);
        vector<int> pre_right(preorder.begin()+rootIndex+1, preorder.end());
        vector<int> in_left(inorder.begin(), inorder.begin()+rootIndex);
        vector<int> in_right(inorder.begin()+rootIndex+1, inorder.end());

        TreeNode *root = new TreeNode;
        root->val = preorder[0];
        root->left = buildTree(pre_left, in_left);
        root->right = buildTree(pre_right, in_right);
        return root;
    }
};