/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool storePaths(TreeNode *node, TreeNode *n, vector<TreeNode *> &path)
    {
        if(node->val==n->val) return true;
        if (node->left && storePaths(node->left,n,path)) path.push_back(node);
        else if (node->right && storePaths(node->right,n,path)) path.push_back(node);
        return !path.empty();
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode *>p_path;
        vector<TreeNode *>q_path;
        storePaths(root, p, p_path);
        storePaths(root, q, q_path);
        p_path.insert(p_path.begin(),p); q_path.insert(q_path.begin(),q);

        TreeNode *ans = root;
        while(!p_path.empty()&&!q_path.empty() && p_path.back()->val==q_path.back()->val)
        {
            ans = p_path.back();
            p_path.pop_back();
            q_path.pop_back();
        }
        return ans;
    }
};