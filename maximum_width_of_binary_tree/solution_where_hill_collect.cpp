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
    int widthOfBinaryTree(TreeNode* root) 
    {
        unordered_map<TreeNode*, unsigned long long> H;
        int res = 0;
        queue<TreeNode*> Q;
        Q.push(root);
        H[root] = 0;
        while(!Q.empty())
        {
            int L, R, qsize=Q.size();
            vector<TreeNode*> nodes;
            for (int i=0; i<qsize; i++)
            {
                TreeNode* cur = Q.front();
                nodes.push_back(cur);
                Q.pop();
                if(i==0) L = H[cur];
                if(i==qsize-1) R = H[cur];
                if(cur->left) Q.push(cur->left);
                if(cur->right) Q.push(cur->right);
            }
            res = max(res, R-L+1);
            for(int i=0; i<nodes.size(); i++)
            {
                if(nodes[i]->left) H[nodes[i]->left] = 2*H[nodes[i]]+1;
                if(nodes[i]->right) H[nodes[i]->right] = 2*H[nodes[i]]+2;
            }
        }
        return res;
    }
};