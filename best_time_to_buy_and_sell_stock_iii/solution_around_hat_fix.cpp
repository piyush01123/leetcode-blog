class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int buyOne = INT_MAX, buyTwo=INT_MAX, selOne=0, selTwo=0;
        for (int p: prices)
        {
            buyOne = min(buyOne, p);
            selOne = max(selOne, p-buyOne);
            buyTwo = min(buyTwo, p-selOne);
            selTwo = max(selTwo, p-buyTwo);
            // cout<<p<<':'<<buyOne<<','<<selOne<<','<<buyTwo<<','<<selTwo<<endl;
        }
        return selTwo;
    }
};