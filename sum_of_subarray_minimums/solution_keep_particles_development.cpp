#define ll long long int
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size(), mod=1000000007;
        ll res = 0;
        vector<ll> dp(n,-1);
        stack<int> stk;
        for (int i=0; i<n; i++)
        {
            while (!stk.empty() && arr[i]<=arr[stk.top()]) stk.pop();
            if (!stk.empty())
            {
                int j = stk.top();
                dp[i] = dp[j] + arr[i]*(i-j);
            } 
            else dp[i] = arr[i]*(i+1);
            stk.push(i);
        }
        for (int x: dp) res+=x;
        return (int)(res%mod);
    }
};