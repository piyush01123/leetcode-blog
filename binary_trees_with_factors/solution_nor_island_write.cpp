class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        int n = arr.size(), mod = 1000000007, res=0;
        sort(arr.begin(), arr.end());
        unordered_map<int,int> amap;
        for(int i=0;i<n;i++)amap[arr[i]] = i;
        vector<long> dp(n);
        for (int i=0; i<n; i++)
        {
            dp[i] = 1;
            for (int j=0; j<i; j++) if (arr[i]%arr[j]==0 && amap.count(arr[i]/arr[j])) dp[i] += dp[j]*dp[amap[arr[i]/arr[j]]] % mod;
            dp[i]%= mod;
            res += dp[i];
            res %= mod;
        }
        return res;
    }
};