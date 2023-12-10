class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        if (n<2) return 0;
        vector<int> A(n), B(n); // A=stock not present, B=stock prseent
        A[0] = 0, B[0]=-prices[0];
        int maxb=-prices[0];
        for (int i=1; i<n; i++)
        {
            // A[i] = B[i-1]+prices[i]-fee;
            // B[i] = max(B[i-1], A[i-1]-prices[i]);

            A[i] = max(A[i-1], maxb + prices[i] - fee);
            B[i] = max(B[i-1], A[i-1]-prices[i]);
            maxb = max(maxb, B[i]);
        }
        // for (int a: A) cout<<a<<',';cout<<endl;
        // for (int b: B) cout<<b<<',';cout<<endl;
        return A[n-1];
    }
};