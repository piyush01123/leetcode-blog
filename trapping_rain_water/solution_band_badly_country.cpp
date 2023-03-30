class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int curr=0;
        vector<int> maxLtoR(n,0), maxRtoL(n,0);
        for (int i=0; i<n; i++)
        {
            curr = max(curr, height[i]);
            maxLtoR[i] = curr;
        }
        curr = 0;
        for (int i=n-1; i>=0; i--)
        {
            curr = max(curr, height[i]);
            maxRtoL[i] = curr;
        }
        int amt_here, total_amt=0;
        for (int i=1; i<n-1; i++)
        {
            amt_here =  min(maxLtoR[i], maxRtoL[i]) - height[i];
            // cout << maxLtoR[i] << ' ' << maxRtoL[i] << ' ' << amt_here << endl;
            total_amt += amt_here;
        }
        return total_amt;
    }
};