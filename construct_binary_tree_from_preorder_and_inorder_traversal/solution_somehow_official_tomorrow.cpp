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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if (n==0) return NULL;
        if (n==1) return new TreeNode(inorder[0]);
        int index = find(inorder.begin(),inorder.end(), preorder[0]) - inorder.begin();
        vector<int> inLeft = vector<int>(inorder.begin(), inorder.begin()+index);
        vector<int> inRight = vector<int>(inorder.begin()+index+1, inorder.end());
        vector<int> pLeft = vector<int>(preorder.begin()+1, preorder.begin()+index+1);
        vector<int> pRight = vector<int>(preorder.begin()+index+1,preorder.end());
        return new TreeNode(preorder[0], buildTree(pLeft, inLeft), buildTree(pRight, inRight));
        
    }
};