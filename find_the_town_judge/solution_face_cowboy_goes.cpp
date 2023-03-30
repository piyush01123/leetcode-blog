class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<pair<int,int>> trustData(n,{0,0});
        for (auto &p: trust)
        {
            int truster = p[0]-1, trusted = p[1]-1;
            trustData[truster].first++;
            trustData[trusted].second++;
        }
        for (int i=0; i<n; i++)
            if (trustData[i].first==0 && trustData[i].second==n-1)
                return i+1;
        return -1;
    }
};