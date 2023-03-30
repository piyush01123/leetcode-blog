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
    int numSwaps(vector<int> &A)
    {
        // for (int a: A) cout<<a<<',';cout<<endl;
        int swaps = 0, n=A.size();
        vector<pair<int,int>> vec;
        for (int i=0; i<n; i++) vec.push_back({A[i],i});
        sort(vec.begin(),vec.end());
        for (int i=0; i<n; i++)
        {
            int value=vec[i].first, index=vec[i].second;
            if (i!=index)
            {
                swaps++;
                swap(vec[i], vec[index]);
                i--;
            }
        }
        // cout<<swaps<<endl;
        return swaps;
    }
    int minimumOperations(TreeNode* root) 
    {
        queue<TreeNode *>Q;
        Q.push(root);
        int ctr = 0;
        while(!Q.empty())
        {
            vector<int> vals;
            for (int i=Q.size(); i>0; i--)
            {
                TreeNode *u = Q.front();
                Q.pop();
                vals.push_back(u->val);
                if (u->left) Q.push(u->left);
                if (u->right) Q.push(u->right);
            }
            if (vals.size()<=1) continue;
            ctr += numSwaps(vals);
        }
        return ctr;
    }
};