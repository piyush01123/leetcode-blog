class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m=mat.size(), n=mat[0].size();
        vector<vector<int>> strength (n+1, vector<int>());
        for (int i=0; i<m; i++)
        {
            vector<int> row=mat[i];
            int s=accumulate(row.begin(), row.end(), 0);
            strength[s].push_back(i);
        }
        // for (auto str: strength){cout<<'{';for (int i: str) cout<<i<<','; cout<<'}'<<endl;}
        vector<int> res;
        for (int i=0; i<n+1; i++)
        {
            if (strength[i].size()>0)
            {
                for (int idx: strength[i])
                {
                    res.push_back(idx);
                    if (res.size()==k) return res;
                }
            }
        }
        return {};
    }
};