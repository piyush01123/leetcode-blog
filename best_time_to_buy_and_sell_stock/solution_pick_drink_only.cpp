class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int minPrice = prices[0], maxProfit=0;
        for (int i=1; i<prices.size(); i++)
        {
            int price = prices[i];
            int profit = price-minPrice;
            maxProfit = max(maxProfit, profit);
            minPrice = min(minPrice, price);
        }
        return maxProfit;
    }
};