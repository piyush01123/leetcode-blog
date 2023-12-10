class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) 
    {
        int n = nums.size(), curL=0, curR=0;
        vector<int> leftSum, rightSum;
        for(int i=0; i<n; i++)
        {
            curL += nums[i];
            leftSum.push_back(curL);
        }
        for(int i=n-1; i>=0; i--)
        {
            curR += nums[i];
            rightSum.push_back(curR);
        }
        reverse(rightSum.begin(),rightSum.end());
        vector<int> res;
        for (int i=0; i<n; i++)
        {
            int lsum = leftSum[i]-nums[i], rsum = rightSum[i]-nums[i];
            res.push_back(rsum - lsum + (-n+1+2*i)*nums[i]);
        }
        return res;
    }
};
/*
R-L+(-2)*a
*/