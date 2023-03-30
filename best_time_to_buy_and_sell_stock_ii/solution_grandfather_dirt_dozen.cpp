class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0, n=prices.size(), profit=0;
        while(i<n)
        {
            while(i+1<n && prices[i+1]<=prices[i]) i++;
            cout << "BUY " << i<<endl;
            int costPrice = prices[i];
            if (i==n-1) break;
            while(i+1<n && prices[i+1]>=prices[i]) i++;
            cout << "SELL " << i<<endl;
            int sellingPrice = prices[i];
            profit += sellingPrice-costPrice;
            cout << costPrice << ' '<<sellingPrice<<endl;
        }
        return profit;
    }
};