class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) 
    {
        int cur=0;
        vector<int>A(n,0), res;
        for (auto &query: queries)
        {
            int i=query[0], v=query[1];
            if (i>0 && A[i]>0 && A[i]==A[i-1]) cur--;
            if (i<n-1 && A[i]>0 && A[i]==A[i+1]) cur--;
            A[i] = v;
            if (i>0 && A[i]==A[i-1]) cur++;
            if (i<n-1 && A[i]==A[i+1]) cur++;
            res.push_back(cur);
        }
        return res;
    }
};