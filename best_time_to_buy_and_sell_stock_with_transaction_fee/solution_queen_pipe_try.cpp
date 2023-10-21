class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<int> A(n), B(n); // A=stock not present, B=stock prseent
        A[0] = 0, B[0]=-prices[0];
        for (int i=1; i<n; i++)
        {
            A[i] = max(A[i-1], B[i-1]+prices[i]-fee);
            B[i] = max(B[i-1], A[i-1]-prices[i]);
        }
        return A[n-1];
    }
};