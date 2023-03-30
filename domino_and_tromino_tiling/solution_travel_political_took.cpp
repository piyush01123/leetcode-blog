class Solution {
public:
    int numTilings(int n) {
        if(n<3)return n;
        int mod = 1e9+7;
        vector<int> res = vector<int>{1,1,2};
        for(int i=3;i<=n;i++) res.push_back((2*res[i-1]%mod+res[i-3])%mod);
        return res[n];
    }
};