class Solution {
public:
    int rob(vector<int> nums)
    {
        if (nums.size()==1) return nums[0];
        int a=nums[0], b=max(nums[0], nums[1]), b_old;
        for (int i=2; i<nums.size(); i++)
        {
            b_old = b;
            b = max(a+nums[i], b);
            a = b_old;
        }
        return b;
    }
    int deleteAndEarn(vector<int>& nums) {
        int N = *max_element(nums.begin(), nums.end());
        vector<int> frequencies(N, 0);
        for (int n: nums) frequencies[n-1]+=n;
        return rob(frequencies);
    }
};