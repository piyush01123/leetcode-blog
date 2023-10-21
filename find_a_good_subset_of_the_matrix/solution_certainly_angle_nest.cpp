class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) 
    {
        int m=grid.size(), n=grid[0].size();
        unordered_map<int,int> H;
        for (int i=0; i<m; i++)
        {
            int cur = 0;
            for (int j=0; j<n; j++) cur += grid[i][j] * (1<<(n-1-j));
            if (cur==0) return {i};
            H[cur] = i;
        }
        for(int a=0; a<(1<<n); a++) for(int b=a+1; b<(1<<n); b++)
        if (((a&b)==0) && H.count(a) && H.count(b))
        {
            vector<int> res = {H[a],H[b]};
            sort(res.begin(),res.end());
            return res;
        }
        return {};
    }
};