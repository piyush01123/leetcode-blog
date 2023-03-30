class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int meh=0, res=INT_MIN;
        for (int n: nums)
        {
            meh += n;
            res = max(res, meh);
            if (meh<0) meh=0;
        }
        return res;
    }
};