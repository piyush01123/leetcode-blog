class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n = arr.size();
        long res = 0;
        stack<int> stk;
        for (int i=0; i<=n; i++)
        {
            while (!stk.empty() && (i==n || arr[i]<arr[stk.top()]))
            {
                int j = stk.top();
                stk.pop();
                int k = (stk.empty()) ? -1 : stk.top();
                res += (long) arr[j] * (i-j) * (j-k);
            }
            stk.push(i);
        }
        return (int) (res % (long) (1e9+7));
    }
};