class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> A(n), B(n), C(n); // A=can buy, B=bought and holding, C=just sold
        A[0] = 0; B[0] = -prices[0], C[0] = INT_MIN;
        for (int i=1; i<n; i++)
        {
            A[i] = max(A[i-1], C[i-1]);
            B[i] = max(B[i-1], A[i-1]-prices[i]);
            C[i] = B[i-1] + prices[i];
        }
        return max(A[n-1], C[n-1]);
    }
};