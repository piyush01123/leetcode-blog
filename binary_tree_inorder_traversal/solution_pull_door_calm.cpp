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
//     void recursive(TreeNode *root, vector<int> *v){
//         if (root==nullptr) return;
//         recursive(root->left, v);
//         v->push_back(root->val);
//         recursive(root->right, v);
//     }

//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> v;
//         recursive(root, &v);
//         return v;
//     }

    vector<int> inorderTraversal(TreeNode* root) {
        if (root==nullptr) return {};
        vector<int> w = inorderTraversal(root->left);
        w.push_back(root->val);
        vector<int> x = inorderTraversal(root->right);
        w.insert(w.end(), x.begin(), x.end());
        return w;
    }

};