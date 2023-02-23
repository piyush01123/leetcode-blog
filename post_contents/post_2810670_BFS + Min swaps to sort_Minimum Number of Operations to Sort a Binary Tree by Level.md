Use BFS to get nodes at each level. Then we need an algorithm to find minimum number of swaps to sort an array. I used [this reference](https://www.youtube.com/watch?v=kFe_LRWuZjE) for this part. The idea is simple: Traverse through sorted version of array and try to get back original array by swapping repeatedly.

```
class Solution {
public:
    int numSwaps(vector<int> &A)
    {
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
```