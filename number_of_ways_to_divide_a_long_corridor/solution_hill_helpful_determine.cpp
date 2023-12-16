class Solution {
    int mod = 1e9+7;
public:
    int numberOfWays(string corridor) 
    {
        int n = corridor.length();
        vector<int> positions;
        for(int i=0; i<n; i++) if(corridor[i]=='S') positions.push_back(i);
        int m = positions.size();
        if (m%2==1 || m==0) return 0;
        long res = 1;
        for (int i=0; i<m; i++)
        {
            if (i==0 || i%2==1) continue;
            res *= (long)(positions[i]-positions[i-1]);
            res %= mod;
        }
        return res;
    }
};