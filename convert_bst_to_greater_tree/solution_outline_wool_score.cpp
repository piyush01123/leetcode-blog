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
    void traverse(TreeNode *root, unordered_map<int, TreeNode *>&H)
    {
        if (root==NULL) return;
        H[root->val] = root;
        traverse(root->left, H);
        traverse(root->right, H);
    }
    TreeNode* convertBST(TreeNode* root) {
        unordered_map<int, TreeNode *> H;
        traverse(root, H);
        vector<int> v1, v2;
        for (auto item: H) v1.push_back(item.first);
        sort(v1.begin(),v1.end(), greater<int>());
        int curr=0;
        for (int i: v1)
        {
            v2.push_back(curr+i);
            curr+=i;
        }
        for (int i=0; i<v1.size(); i++) H[v1[i]]->val = v2[i];
        return root;
    }
};