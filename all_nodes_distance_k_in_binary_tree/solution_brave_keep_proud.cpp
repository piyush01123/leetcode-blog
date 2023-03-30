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
    void storeParents(TreeNode *root, unordered_map<TreeNode*,TreeNode*>&H)
    {
        if (root==NULL) return;
        if (root->left != NULL) H[root->left] = root;
        if (root->right != NULL) H[root->right] = root;
        storeParents(root->left,H);
        storeParents(root->right,H);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
    {
        unordered_map<TreeNode*,TreeNode*>H;
        storeParents(root, H);
        queue<TreeNode*>Q;
        Q.push(target);
        unordered_set<TreeNode *>visited;

        for (int ctr=0; ctr<K; ctr++)
        {
            if (Q.empty()) return {};
            for (int i=Q.size(); i>0; i--)
            {
                TreeNode *cur = Q.front();
                Q.pop();
                visited.insert(cur);
                if (cur->left && !visited.count(cur->left)) 
                    Q.push(cur->left);
                if (cur->right && !visited.count(cur->right)) 
                    Q.push(cur->right);
                if (H.count(cur) && !visited.count(H[cur])) 
                    Q.push(H[cur]);
            }
        }
        vector<int> res;
        while (!Q.empty())
        {
            res.push_back(Q.front()->val);
            Q.pop();
        }
        return res;
    }
};