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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if (n==0) return NULL;
        if (n==1) return new TreeNode(inorder[0]);
        int index = find(inorder.begin(),inorder.end(), postorder[n-1]) - inorder.begin();
        vector<int> inLeft = vector<int>(inorder.begin(), inorder.begin()+index);
        vector<int> inRight = vector<int>(inorder.begin()+index+1, inorder.end());
        vector<int> poLeft = vector<int>(postorder.begin(), postorder.begin()+index);
        vector<int> poRight = vector<int>(postorder.begin()+index,postorder.end()-1);
        return new TreeNode(postorder[n-1], buildTree(inLeft, poLeft), buildTree(inRight, poRight));
    }
};