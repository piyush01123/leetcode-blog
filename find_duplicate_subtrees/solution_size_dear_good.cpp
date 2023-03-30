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
    vector<TreeNode*> res;
    unordered_map<string, int> tripletToId;
    unordered_map<int, int> freq;
public:
    int traverse(TreeNode *root)
    {
        if (!root) return 0;
        string cur = to_string(traverse(root->left))+","+to_string(root->val)\
                     +","+to_string(traverse(root->right));
        if (!tripletToId.count(cur)) tripletToId[cur] = tripletToId.size()+1;
        int id = tripletToId[cur];
        freq[id]++;
        if (freq[id]==2) res.push_back(root);
        return id;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        traverse(root);
        return res;        
    }
};