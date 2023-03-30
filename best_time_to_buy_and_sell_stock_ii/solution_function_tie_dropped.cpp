class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0, n=prices.size(), profit=0;
        while(i<n)
        {
            while(i+1<n && prices[i+1]<=prices[i]) i++;
            int costPrice = prices[i];
            if (i==n-1) break;
            while(i+1<n && prices[i+1]>=prices[i]) i++;
            int sellingPrice = prices[i];
            profit += sellingPrice-costPrice;
        }
        return profit;
    }
};