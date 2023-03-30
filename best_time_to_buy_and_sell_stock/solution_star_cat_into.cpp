class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> minFromLeft(n,0), maxFromRight(n,0);
        minFromLeft[0]=prices[0]; maxFromRight[n-1]=prices[n-1];
        for(int i=1;i<n;i++) minFromLeft[i]=min(minFromLeft[i-1],prices[i]);
        for(int i=n-2;i>=0;i--) maxFromRight[i]=max(maxFromRight[i+1],prices[i]);
        int res=INT_MIN;
        for(int i=0;i<n;i++) res=max(res, maxFromRight[i]-minFromLeft[i]);
        return res;
    }
};