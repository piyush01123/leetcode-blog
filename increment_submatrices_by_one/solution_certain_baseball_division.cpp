class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) 
    {
        vector<vector<int>> M = vector<vector<int>>(n+1, vector<int>(n+1,0));
        for (auto &q: queries)
        {
            int r1=q[0], c1=q[1], r2=q[2], c2=q[3];
            M[r1][c1]++;
            M[r2+1][c1]--;
            M[r1][c2+1]--;
            M[r2+1][c2+1]++;
        }
        // for (auto &v: M){for(int k: v)cout<<k<<',';cout<<endl;}
        vector<vector<int>> res = vector<vector<int>>(n, vector<int>(n,0));
        res[0][0] = M[0][0];
        for (int i=1; i<n; i++) res[i][0]=res[i-1][0]+M[i][0];
        for (int j=1; j<n; j++) res[0][j]=res[0][j-1]+M[0][j];
        for (int i=1; i<n; i++) for (int j=1; j<n; j++)
            res[i][j] = -res[i-1][j-1]+res[i][j-1]+res[i-1][j]+M[i][j];
        return res;
    }
};