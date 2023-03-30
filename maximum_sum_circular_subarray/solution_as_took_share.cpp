class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) 
    {
        int maxEH=0, minEH=0, minSub=INT_MAX, maxSub=INT_MIN, totSum=0;
        for (int n: nums)
        {
            totSum += n;
            minEH = min(minEH,0) + n;
            maxEH = max(maxEH,0) + n;
            minSub = min(minSub, minEH);
            maxSub = max(maxSub, maxEH);
            // cout << '('<< minEH <<','<<maxEH <<')';
        }
        if (totSum==minSub) return maxSub;
        else return max(maxSub, totSum-minSub);
    }
};