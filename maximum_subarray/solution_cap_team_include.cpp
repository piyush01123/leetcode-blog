class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int meh=0, res=INT_MIN;
        for (int n: nums)
        {
            meh = max(meh, 0) + n;
            res = max(res, meh);
        }
        return res;
    }
};