class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        int n = nums.size(), minDiff=INT_MAX, res=-1;
        long long total = 0, cur=0;
        for (int n: nums) total+=n;

        // // accumulate(nums.begin(),nums.end(),0);
        for (int i=0; i<n; i++)
        {
            cur += nums[i];
            int leftAvg = cur/(i+1);
            int rtAvg = (i==n-1 ? 0 : (total-cur)/(n-i-1));
            int diff = abs(leftAvg-rtAvg);
            if (diff<minDiff)
            {
                minDiff = diff;
                res = i;
            }
        }
        return res;
    }
};